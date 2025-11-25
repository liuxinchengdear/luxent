#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100010;

int n, q;
int a[N], num[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i ++ ) cin >> a[i] >> num[i], a[i] += a[i - 1];

    while (q -- ) {
        int pos ; cin >> pos;
        auto p = lower_bound(a + 1, a + 1 + n, pos);
        cout << num[p - a] << '\n';
    }
    cout.flush(); system("pause");
    return 0;
}