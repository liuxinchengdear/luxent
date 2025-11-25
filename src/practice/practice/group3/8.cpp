#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <algorithm>

// 内存块结构
struct Block {
    size_t size;         // 块大小（含头），必须是2的幂
    bool free;           // true-空闲，false-占用
    Block* prev;         // 双向链表前指针
    Block* next;         // 双向链表后指针
    Block* buddy;        // 伙伴块指针
};

class BuddyAllocator {
private:
    static const int MAX_ORDER = 12;        // 最大块大小：2^12 = 4096 bytes
    static const int MIN_BLOCK_SIZE = 16;   // 最小块大小（必须是2的幂）

    Block* free_lists[MAX_ORDER + 1] = {nullptr}; // 空闲块链表
    char* memory_pool = nullptr;                  // 内存池起始地址
    size_t pool_size;                             // 内存池总大小

    // 计算一个数的log2值（仅对2的幂有效）
    int log2(size_t x) const {
        if (x == 0 || (x & (x - 1)) != 0) {
            std::cerr << "错误：输入不是2的幂次！" << std::endl;
            exit(1);
        }
        return __builtin_ctz(static_cast<unsigned int>(x));
    }

    // 查找伙伴块
    Block* find_buddy(Block* block) const {
        if (!block) return nullptr;
        uintptr_t block_addr = reinterpret_cast<uintptr_t>(block);
        uintptr_t pool_addr = reinterpret_cast<uintptr_t>(memory_pool);
        uintptr_t offset = block_addr - pool_addr;
        uintptr_t buddy_offset = offset ^ block->size;
        return reinterpret_cast<Block*>(pool_addr + buddy_offset);
    }

    // 分割块
    Block* split_block(Block* block) {
        if (!block || block->size <= MIN_BLOCK_SIZE) return nullptr;

        int order = log2(block->size);
        size_t new_size = block->size / 2;

        // 从空闲链表中移除原块
        if (block->prev) block->prev->next = block->next;
        if (block->next) block->next->prev = block->prev;
        if (free_lists[order] == block) free_lists[order] = block->next;
        block->prev = block->next = nullptr;

        Block* new_block = reinterpret_cast<Block*>(reinterpret_cast<char*>(block) + new_size);
        new_block->size = new_size;
        new_block->free = true;
        new_block->prev = new_block->next = nullptr;

        block->size = new_size;
        block->buddy = new_block;
        new_block->buddy = block;

        // 将两个新块加入新的空闲链表
        int new_order = order - 1;
        block->next = free_lists[new_order];
        if (free_lists[new_order]) free_lists[new_order]->prev = block;
        free_lists[new_order] = block;

        new_block->next = free_lists[new_order];
        if (free_lists[new_order]) free_lists[new_order]->prev = new_block;
        free_lists[new_order] = new_block;

        return block;
    }

    // 合并块
    Block* merge_blocks(Block* block) {
        if (!block || !block->free) return block;

        Block* buddy = block->buddy;
        if (!buddy || !buddy->free || buddy->size != block->size) {
            return block;
        }

        Block* merged_block = (block < buddy) ? block : buddy;
        size_t merged_size = block->size * 2;
        int merged_order = log2(merged_size);

        // 从空闲链表中移除两个小块
        int order = merged_order - 1;
        if (block->prev) block->prev->next = block->next;
        if (block->next) block->next->prev = block->prev;
        if (free_lists[order] == block) free_lists[order] = block->next;
        
        if (buddy->prev) buddy->prev->next = buddy->next;
        if (buddy->next) buddy->next->prev = buddy->prev;
        if (free_lists[order] == buddy) free_lists[order] = buddy->next;

        merged_block->size = merged_size;
        merged_block->buddy = nullptr;
        merged_block->prev = merged_block->next = nullptr;

        // 将合并后的大块加入新的空闲链表
        merged_block->next = free_lists[merged_order];
        if (free_lists[merged_order]) free_lists[merged_order]->prev = merged_block;
        free_lists[merged_order] = merged_block;

        return merged_block;
    }

public:
    // 构造函数：初始化内存池
    explicit BuddyAllocator(size_t total_size) {
        // 计算总大小（向上取整为2的幂）
        pool_size = 1;
        while (pool_size < total_size) {
            pool_size <<= 1;
        }
        std::cout << "内存池初始化大小：" << pool_size << " bytes（向上取整为2的幂）" << std::endl;

        // 分配内存池
        memory_pool = reinterpret_cast<char*>(std::malloc(pool_size));
        if (!memory_pool) {
            std::perror("内存池分配失败");
            exit(1);
        }

        // 初始化第一个块
        Block* first_block = reinterpret_cast<Block*>(memory_pool);
        first_block->size = pool_size;
        first_block->free = true;
        first_block->prev = first_block->next = nullptr;
        first_block->buddy = nullptr;

        // 将初始块加入对应空闲链表
        int order = log2(pool_size);
        free_lists[order] = first_block;
    }

    // 析构函数：释放内存池
    ~BuddyAllocator() {
        std::free(memory_pool);
        std::cout << "内存池已释放" << std::endl;
    }

    // 内存分配（模拟malloc）
    void* allocate(size_t size) {
        if (size == 0) return nullptr;

        // 计算需要的块大小（包含块头）
        size_t alloc_size = MIN_BLOCK_SIZE;
        while (alloc_size < (size + sizeof(Block))) {
            alloc_size <<= 1;
        }
        int order = log2(alloc_size);

        // 查找合适的空闲块
        Block* target_block = nullptr;
        int i;
        for (i = order; i <= MAX_ORDER; ++i) {
            if (free_lists[i]) {
                target_block = free_lists[i];
                break;
            }
        }
        if (!target_block) {
            std::cout << "分配失败：没有足够大的空闲块（请求大小：" << size << " bytes）" << std::endl;
            return nullptr;
        }

        // 分割块直到大小匹配
        while (target_block->size > alloc_size) {
            target_block = split_block(target_block);
        }

        // 从空闲链表中移除目标块
        if (target_block->prev) target_block->prev->next = target_block->next;
        if (target_block->next) target_block->next->prev = target_block->prev;
        if (free_lists[order] == target_block) free_lists[order] = target_block->next;
        target_block->prev = target_block->next = nullptr;

        // 标记为占用
        target_block->free = false;
        void* user_ptr = reinterpret_cast<char*>(target_block) + sizeof(Block);
        std::cout << "分配成功：地址=" << user_ptr << "，大小=" << (alloc_size - sizeof(Block)) 
                  << " bytes（请求大小：" << size << " bytes）" << std::endl;

        return user_ptr;
    }

    // 内存回收（模拟free）
    void deallocate(void* ptr) {
        if (!ptr) return;

        // 计算块头地址
        Block* block = reinterpret_cast<Block*>(reinterpret_cast<char*>(ptr) - sizeof(Block));
        if (block->free) {
            std::cout << "回收失败：地址=" << ptr << " 已空闲" << std::endl;
            return;
        }

        // 标记为空闲
        block->free = true;
        int order = log2(block->size);

        // 将块加入对应空闲链表
        block->next = free_lists[order];
        if (free_lists[order]) free_lists[order]->prev = block;
        free_lists[order] = block;

        // 尝试合并块
        Block* merged_block = block;
        do {
            merged_block = merge_blocks(merged_block);
        } while (merged_block && merged_block->size < pool_size);

        std::cout << "回收成功：地址=" << ptr << "，大小=" << (merged_block->size - sizeof(Block)) << " bytes" << std::endl;
    }

    // 打印内存池状态
    void print_status() const {
        std::cout << "\n===== 内存池状态 =====\n";
        for (int i = 0; i <= MAX_ORDER; ++i) {
            size_t block_size = static_cast<size_t>(1) << i;
            Block* curr = free_lists[i];
            int count = 0;
            while (curr) {
                count++;
                curr = curr->next;
            }
            if (count > 0) {
                std::cout << "空闲块大小：" << (block_size - sizeof(Block)) 
                          << " bytes，数量：" << count << std::endl;
            }
        }
        std::cout << "======================\n" << std::endl;
    }
};

// 测试函数
int main() {
    // 创建一个2048字节的内存管理器
    BuddyAllocator allocator(2048);
    allocator.print_status();

    // 分配测试
    void* p1 = allocator.allocate(100);
    void* p2 = allocator.allocate(200);
    void* p3 = allocator.allocate(50);
    allocator.print_status();

    // 回收测试
    allocator.deallocate(p2);
    allocator.print_status();

    allocator.deallocate(p1);
    allocator.print_status();

    allocator.deallocate(p3);
    allocator.print_status();

    // 重复分配回收测试
    void* p4 = allocator.allocate(300);
    void* p5 = allocator.allocate(150);
    allocator.deallocate(p4);
    allocator.print_status();
    
    allocator.deallocate(p5);
    allocator.print_status();

    // 当 main 函数结束时，allocator 的析构函数会自动调用，释放内存池

    return 0;
}