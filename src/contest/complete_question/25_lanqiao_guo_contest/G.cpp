#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200010;

int n;
int a[N], f[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    for (int i = 2; i <= n; i ++ ) {
        int x = a[i - 1], y = a[i];
        f[i] = f[i - 1];
        while (x > y) y *= 2, f[i] ++ ;
        while (x <= y >> 1) y >>= 1, f[i] = max(0LL, f[i] - 1);
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ ) res += f[i];

    cout << res << endl;
    system("pause");
    return 0;
}