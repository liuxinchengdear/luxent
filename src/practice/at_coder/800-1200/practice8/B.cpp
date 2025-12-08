#include <bits/stdc++.h>
using namespace std;

#define int long long

#define lowbit(x) ((x) & -(x))

struct Fenwick {
    vector<int> tree;

    Fenwick(int n) { tree.resize(n); }

    void update(int x, int d) { while (x < tree.size()) tree[x] += d, x += lowbit(x); }
    
    int query(int x) { int sum = 0; while (x) sum += tree[x], x -= lowbit(x); return sum; }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    Fenwick t(n + 1);

    int res = 0;
    for (int i = 1; i <= n; i ++ ) {
        t.update(a[i], 1); 
        auto x = t.query(n) - t.query(a[i]);
        res += x * i - (x + 1) * x / 2;
    }

    cout << res << endl;
    return 0;
}