#include <stdio.h>
#include <stdbool.h>
 
#define P 5  // 进程数
#define R 3  // 资源种类数
 
// 资源数据结构
int available[R] = {3, 3, 2};  // 系统中每种资源的可用数量
int maximum[P][R] = {           // 每个进程对资源的最大需求
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};
 
int allocation[P][R] = {         // 每个进程当前分配的资源数量
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
 
int need[P][R];                 // 每个进程尚需的资源数量
 
// 计算need矩阵
void calculateNeed() {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}
 
// 检查系统是否处于安全状态
bool isSafe() {
    int work[R];
    bool finish[P] = {0};
    int safeSeq[P];
    int count = 0;
 
    // 初始化work为available
    for (int i = 0; i < R; i++) {
        work[i] = available[i];
    }
 
    // 尝试为每个进程找到一个可行的执行顺序
    while (count < P) {
        bool found = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p]) {
                bool canAllocate = true;
                // 检查进程p是否能够被分配资源
                for (int j = 0; j < R; j++) {
                    if (need[p][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
 
                // 如果可以分配资源，则执行该进程
                if (canAllocate) {
                    for (int j = 0; j < R; j++) {
                        work[j] += allocation[p][j];  // 分配资源
                    }
                    safeSeq[count++] = p;  // 将进程p加入安全序列
                    finish[p] = true;      // 标记进程p为完成
                    found = true;
                    break;
                }
            }
        }
 
        // 如果没有找到可以分配资源的进程，则说明进入死锁
        if (!found) {
            return false;
        }
    }
 
    // 打印安全序列
    printf("安全序列为: ");
    for (int i = 0; i < P; i++) {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");
 
    return true;
}
 
// 请求资源
bool requestResources(int processID, int request[]) {
    // 检查请求是否小于进程的需求
    for (int i = 0; i < R; i++) {
        if (request[i] > need[processID][i]) {
            printf("请求大于进程的最大需求\n");
            return false;
        }
    }
 
    // 检查请求是否小于系统的可用资源
    for (int i = 0; i < R; i++) {
        if (request[i] > available[i]) {
            printf("请求大于系统的可用资源\n");
            return false;
        }
    }
 
    // 假设分配资源
    for (int i = 0; i < R; i++) {
        available[i] -= request[i];
        allocation[processID][i] += request[i];
        need[processID][i] -= request[i];
    }
 
    // 安全性检查
    if (isSafe()) {
        printf("资源请求被允许\n");
        return true;
    } else {
        // 如果系统不安全，撤销资源分配
        for (int i = 0; i < R; i++) {
            available[i] += request[i];
            allocation[processID][i] -= request[i];
            need[processID][i] += request[i];
        }
        printf("资源请求被拒绝，系统进入不安全状态\n");
        return false;
    }
}
 
int main() {
    // 初始化need矩阵
    calculateNeed();
 
    // 显示初始状态
    printf("初始状态：\n");
    printf("进程\t最大需求\t已分配\t尚需资源\n");
    for (int i = 0; i < P; i++) {
        printf("P%d\t", i);
        for (int j = 0; j < R; j++) {
            printf("%d ", maximum[i][j]);
        }
        printf("\t");
        for (int j = 0; j < R; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\t");
        for (int j = 0; j < R; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
 
    // 请求资源
    int processID = 1;  // 请求进程P1
    int request[R] = {1, 0, 2};  // 请求资源{1, 0, 2}
    requestResources(processID, request);
 
    return 0;
}