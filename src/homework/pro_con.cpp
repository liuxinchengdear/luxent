#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <random>
#include <chrono>

// 定义缓冲区大小
const int BUFFER_SIZE = 10;

// 共享缓冲区和索引
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv;
int in = 0, out = 0;

// 随机生成器
std::mt19937 rng(std::random_device{}());
std::uniform_int_distribution<int> dist(0, 99);

// 退出标志
std::atomic<bool> stop(false);

void producer() {
    while (!stop) {
        int item = dist(rng);
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });

        if (stop) break;
        
        buffer.push(item);
        std::cout << "生产者生产数据 " << item << " 放入缓冲区位置 " << in << std::endl;
        in = (in + 1) % BUFFER_SIZE;

        lock.unlock();
        cv.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(dist(rng) % 3000));
    }
}

void consumer() {
    while (!stop) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size(); });

        if (stop) break;

        int item = buffer.front();
        buffer.pop();
        std::cout << "消费者消费数据 " << item << " 从缓冲区位置 " << out << std::endl;
        out = (out + 1) % BUFFER_SIZE;

        lock.unlock();
        cv.notify_one();

        std::this_thread::sleep_for(std::chrono::milliseconds(dist(rng) % 4000));
    }
}

int main() {
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    // 模拟运行一段时间后停止
    std::this_thread::sleep_for(std::chrono::seconds(10));
    stop = true;

    producerThread.join();
    consumerThread.join();

    return 0;
}