#include <bits/stdc++.h>
using namespace std;

/* 
有序列 {e1, e2, ... en}

考虑动态规划 f(m, n) 表示对于
序列 {e1, e2 ... en} 有 max{ei, e[i + 1]} = m, i >= 1 && i <= n - 1

有状态转移方程 : f(m, n) = f(m, n - 1) * 1 + f(m, n - 2) * m
*/

const int N = 2050, mod = 1e9 + 7;

int f[5][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    // 有两个序列 n >= 2 成立
    f[2][0] = 1; f[2][1] = 3;
    f[4][0] = 1; f[4][1] = 5;
    for (int i = 2; i <= 2025; i ++ ) 
        f[2][i] = (f[2][i - 1] + 1LL * f[2][i - 2] * 2) % mod, 
        f[4][i] = (f[4][i - 1] + 1LL * f[4][i - 2] * 4) % mod;

    cout << (1LL * f[2][2025] * f[4][2025] % mod) << endl;
    system("pause");
    return 0;
}