#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1000010;

int n, m;
int w[N], diff[N], pre[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> w[i], diff[i] = w[i - 1] - w[i];

    sort(diff + 2, diff + 1 + n, greater<int>());

    for (int i = 2; i <= n; i ++ ) pre[i] = pre[i - 1] + diff[i], sum += diff[i];

    cin >> m;
    for (int op, x, k; m -- ; ) {
        cin >> op;
        if (op == 1) cin >> k, cout << sum - pre[k] << '\n';
        else cin >> x;
    }
    return 0;
}