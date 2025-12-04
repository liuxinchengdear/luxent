#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Mon {
    int a, b; 
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<Mon> mon(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> mon[i].a;
    for (int i = 1; i <= n; i ++ ) cin >> mon[i].b;

    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i ++ ) {
        auto [a, b] = mon[i];

        g[b].push_back(a);
    }

    auto LIS = [&](int num) -> int {
        vector<int> lis; auto &a = g[num]; int n = a.size();
        for (int i = 0; i < n; i ++ ) {
            if (!lis.size()) lis.push_back(a[i]);
            else {
                auto p = lower_bound(lis.begin(), lis.end(), a[i]);
                if (p == lis.end()) lis.push_back(a[i]);
                else swap(*p, a[i]);
            }
        }
        return a.size() - lis.size();
    };

    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        res += i * LIS(i);
    }
    cout << res << endl;
    return 0;
}