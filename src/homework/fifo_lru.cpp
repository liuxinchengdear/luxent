#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 100   /* 最大访问序列长度 */
#define MAX_FRAMES 20   /* 最大页框数 */

int seq[MAX_PAGES];     /* 页面访问序列 */
int n;                  /* 序列长度 */
int frames[MAX_FRAMES]; /* 当前内存中的页 */
int fcnt;               /* 页框数 */
int timestamp[MAX_FRAMES];

/* 工具：查找页 p 是否在 frames 中，返回下标，-1 表示不在 */
int find_index(int p)
{
    for (int i = 0; i < fcnt; i++)
        if (frames[i] == p) return i;
    return -1;
}

/* FIFO 算法 */
void fifo()
{
    int fault = 0, in = 0;  /* in 指向最早进入的页框 */
    for (int i = 0; i < fcnt; i++) frames[i] = -1;

    for (int i = 0; i < n; i++)
    {
        int p = seq[i];
        if (find_index(p) == -1)   /* 缺页 */
        {
            frames[in] = p;
            in = (in + 1) % fcnt;
            fault++;
        }
    }
    printf("FIFO 缺页次数 = %d，缺页率 = %.2f%%\n",
           fault, 100.0 * fault / n);
}

/* LRU 算法（用 timestamp 记录“最近使用”时间） */
void lru()
{
    int fault = 0, time = 0;
    for (int i = 0; i < fcnt; i++) { frames[i] = -1; timestamp[i] = 0; }

    for (int i = 0; i < n; i++)
    {
        int p = seq[i];
        int idx = find_index(p);
        if (idx != -1)          /* 命中，更新时间戳 */
        {
            timestamp[idx] = ++time;
            continue;
        }
        /* 缺页 */
        fault++;
        /* 找时间戳最小的框淘汰 */
        int victim = 0;
        for (int j = 1; j < fcnt; j++)
            if (timestamp[j] < timestamp[victim]) victim = j;
        frames[victim] = p;
        timestamp[victim] = ++time;
    }
    printf("LRU  缺页次数 = %d，缺页率 = %.2f%%\n",
           fault, 100.0 * fault / n);
}

int main()
{
    printf("请输入页框数（<=20）：\n");
    scanf("%d", &fcnt);
    printf("请输入访问序列长度（<=100）：\n");
    scanf("%d", &n);
    printf("请输入访问序列（空格分隔）：\n");
    for (int i = 0; i < n; i++) scanf("%d", &seq[i]);

    fifo();
    lru();
    return 0;
}