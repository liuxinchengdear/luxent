#include <stdio.h>
#include <stdlib.h>

// 定义进程结构体
typedef struct {
    int id;          // 进程ID
    int arrivalTime; // 到达时间
    int burstTime;   // 运行时间
    int completionTime; // 完成时间
    int waitingTime;    // 等待时间
    int turnaroundTime; // 周转时间
} Process;

// 计算FCFS调度结果
void fcfsScheduling(Process *processes, int n) {
    int currentTime = 0;
    
    for (int i = 0; i < n; i++) {
        // 如果当前时间小于进程到达时间，等待到进程到达
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }
        
        // 计算完成时间
        processes[i].completionTime = currentTime + processes[i].burstTime;
        // 计算周转时间 = 完成时间 - 到达时间
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        // 计算等待时间 = 周转时间 - 运行时间
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        
        // 更新当前时间
        currentTime = processes[i].completionTime;
    }
}

// 计算SJF调度结果（非抢占式）
void sjfScheduling(Process *processes, int n) {
    int currentTime = 0;
    int completed = 0;
    int *isCompleted = (int *)calloc(n, sizeof(int)); // 标记进程是否已完成
    
    while (completed < n) {
        // 找到当前可运行的进程中运行时间最短的
        int shortestJob = -1;
        int minBurstTime = 99999; // 假设一个较大的值
        
        for (int i = 0; i < n; i++) {
            // 进程已到达且未完成
            if (processes[i].arrivalTime <= currentTime && !isCompleted[i]) {
                // 找到运行时间最短的进程
                if (processes[i].burstTime < minBurstTime) {
                    minBurstTime = processes[i].burstTime;
                    shortestJob = i;
                }
            }
        }
        
        // 如果没有找到可运行的进程，时间向前推进到下一个进程到达的时间
        if (shortestJob == -1) {
            int nextArrival = 99999;
            for (int i = 0; i < n; i++) {
                if (!isCompleted[i] && processes[i].arrivalTime < nextArrival) {
                    nextArrival = processes[i].arrivalTime;
                }
            }
            currentTime = nextArrival;
            continue;
        }
        
        // 处理找到的最短作业
        processes[shortestJob].completionTime = currentTime + processes[shortestJob].burstTime;
        processes[shortestJob].turnaroundTime = processes[shortestJob].completionTime - processes[shortestJob].arrivalTime;
        processes[shortestJob].waitingTime = processes[shortestJob].turnaroundTime - processes[shortestJob].burstTime;
        
        currentTime = processes[shortestJob].completionTime;
        isCompleted[shortestJob] = 1;
        completed++;
    }
    
    free(isCompleted);
}

// 打印调度结果
void printResults(Process *processes, int n, const char *algorithmName) {
    printf("\n%s 调度算法结果:\n", algorithmName);
    printf("进程ID | 到达时间 | 运行时间 | 完成时间 | 周转时间 | 等待时间\n");
    printf("---------------------------------------------------------\n");
    
    float avgWaitingTime = 0, avgTurnaroundTime = 0;
    
    for (int i = 0; i < n; i++) {
        printf("%6d | %8d | %8d | %8d | %8d | %8d\n",
               processes[i].id,
               processes[i].arrivalTime,
               processes[i].burstTime,
               processes[i].completionTime,
               processes[i].turnaroundTime,
               processes[i].waitingTime);
        
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }
    
    avgWaitingTime /= n;
    avgTurnaroundTime /= n;
    
    printf("---------------------------------------------------------\n");
    printf("平均等待时间: %.2f\n", avgWaitingTime);
    printf("平均周转时间: %.2f\n", avgTurnaroundTime);
}

// 复制进程数组（用于两种算法独立计算）
void copyProcesses(Process *dest, Process *src, int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    // 示例进程数据
    int n = 5;
    Process originalProcesses[] = {
        {1, 0, 8},   // 进程ID=1, 到达时间=0, 运行时间=8
        {2, 1, 4},   // 进程ID=2, 到达时间=1, 运行时间=4
        {3, 2, 9},   // 进程ID=3, 到达时间=2, 运行时间=9
        {4, 3, 5},   // 进程ID=4, 到达时间=3, 运行时间=5
        {5, 4, 2}    // 进程ID=5, 到达时间=4, 运行时间=2
    };
    
    // 为两种算法创建独立的进程数组副本
    Process fcfsProcesses[n];
    Process sjfProcesses[n];
    copyProcesses(fcfsProcesses, originalProcesses, n);
    copyProcesses(sjfProcesses, originalProcesses, n);
    
    // 执行FCFS调度
    fcfsScheduling(fcfsProcesses, n);
    printResults(fcfsProcesses, n, "先来先服务(FCFS)");
    
    // 执行SJF调度
    sjfScheduling(sjfProcesses, n);
    printResults(sjfProcesses, n, "短作业优先(SJF)");
    
    return 0;
}