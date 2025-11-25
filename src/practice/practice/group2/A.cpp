#include <stdio.h>
#include <math.h>
int main()
{
    int N, M, i;
    float xo, yo;
    float x, y, smin = 1e9, s, time;
    while (~scanf("%d %d", &N, &M))
    {
        smin = 1e9;
        scanf("%f %f", &xo, &yo);
        for (i = 0; i < M; i++)
        {
            scanf("%f %f", &x, &y);
            s = sqrt((x - xo) * (x - xo) + (y - yo) * (y - yo));
            if (s < smin)
                smin = s;
        }
        time = smin / N;
        printf("%.2f\n", time);
    }
    return 0;
}