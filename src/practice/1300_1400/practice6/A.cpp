#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 7000100;

vector<int> st(N), pme, pre{0};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    auto euler = [&](int n) -> void {
        for (int i = 2; i <= n; i ++ ) {
            if (!st[i]) pme.push_back(i);
            for (int j = 0; i <= n / pme[j]; j ++ ) {
                st[i * pme[j]] = true;
                if (i % pme[j] == 0) break;
            }
        }
    };

    euler(N - 1);

    for (auto e : pme) {
        pre.push_back(pre.back() + e);
    }

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n); int sum = 0;
        for (int i = 0; i < n; i ++ ) cin >> a[i], sum += a[i];

        sort(a.begin(), a.end());
        int res = 0;
        for (auto e : a) {
            if (sum >= pre[n - res]) break;
            sum -= a[res ++ ];
        }
        cout << res << endl;
    }
    return 0;
}