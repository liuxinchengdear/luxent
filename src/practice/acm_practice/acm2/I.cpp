#include <bits/stdc++.h>
using namespace std;

const int N = 1000010, mod = 2021;


// 动态规划thinks: (不能有连续的1)
// f(i, 0) = f(i - 1, 1) + f(i - 1, 0)
// f(i, 1) = f(i - 1, 0)
int f[N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    f[1][0] = f[1][1] = 1;
    for (int i = 2; i < N; i ++ ) 
        f[i][0] = (f[i - 1][0] + f[i - 1][1]) % mod, f[i][1] = f[i - 1][0];

    int n; 
    while (cin >> n, n) {
        cout << (f[n][1] + f[n][0]) % mod << '\n';
    }
    cout.flush(); system("pause");
}