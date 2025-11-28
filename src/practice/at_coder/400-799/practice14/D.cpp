#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    unordered_map<int, int> mp;

    auto dfs = [&](auto &&dfs, int num) -> int {
        if (num == 1 || !num) return 0;
        if (mp.count(num)) return mp[num];
        int l = num >> 1, r = num + 1 >> 1;
        return mp[num] = dfs(dfs, l) + dfs(dfs, r) + l + r;
    };

    cout << dfs(dfs, n) << endl;
    return 0;
}