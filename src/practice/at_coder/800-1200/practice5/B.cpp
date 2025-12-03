#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> w(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> w[i];
    vector<vector<int>> a(n + 1);

    for (int i = 1; i <= m; i ++ ) {
        int k; cin >> k;
        for (int j = 0; j < k; j ++ ) {
            int x; cin >> x; a[x].push_back(i);
        }
    }

    vector<int> st;

    int res = 1e18;

    auto dfs = [&](auto &&dfs, int de, int sum) -> void {
        if (de == n + 1) {
            multiset<int> tmp; 
            for (auto store : st) for (auto e : a[store]) tmp.insert(e); 

            for (int i = 1; i <= m; i ++ ) if (tmp.count(i) < 2) return;
            res = min(res, sum); return;
        }
        
        st.push_back(de);
        st.push_back(de);
        if (sum + 2 * w[de] < res) dfs(dfs, de + 1, sum + 2 * w[de]);
        st.pop_back();
        if (sum + w[de] < res) dfs(dfs, de + 1, sum + w[de]);
        st.pop_back();
        if (sum < res) dfs(dfs, de + 1, sum);
    };

    dfs(dfs, 1, 0);
    cout << res << endl;
    return 0;
}