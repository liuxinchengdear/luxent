#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<vector<int>> idx(n + 1);
    vector<int> c(n + 1), w(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        cin >> c[i];
        idx[c[i]].push_back(i);
    }
    for (int i = 1; i <= n; i ++ ) cin >> w[i];

    for (int i = 1; i <= n; i ++ ) {
        
    }
}