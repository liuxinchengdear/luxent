#include <bits/stdc++.h>
using namespace std;

#define MULTI int _T; cin >> _T; while (_T -- )

const int N = 100010, mod = 1e9 + 7;

int f[N], c0[N], c1[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    c0[1] = 1; c0[2] = 0;
    c1[1] = 0; c1[2] = 1;

    for (int i = 3; i < N; i ++ ) {
        c0[i] = (c0[i - 2] + c0[i - 1]) % mod, c1[i] = (c1[i - 2] + c1[i - 1]) % mod;
        f[i] = (1LL * c1[i - 2] * c0[i - 1] + f[i - 2] + f[i - 1]) % mod;
    }

    MULTI {
        int n; cin >> n;
        cout << f[n] << '\n';
    }
    cout.flush();
    system("pause");
    return 0;
}