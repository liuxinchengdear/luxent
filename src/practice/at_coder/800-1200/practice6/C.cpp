#include <bits/stdc++.h>
using namespace std;

struct Node {
    int a, b;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<Node> mon(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> mon[i].a;
    for (int i = 1; i <= n; i ++ ) cin >> mon[i].b;

    vector<vector<int>> g(n + 1);
    for (int i = 1; i <= n; ++ i) {
        auto [a, b] = mon[i];
        g[b].push_back(a);
    }

    

    for (int i = 1; i <= n; i ++ ) {

    }
}