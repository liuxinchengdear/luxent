#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 0x3f3f3f3f;

struct Edge {
    int to, w;
    Edge(int to, int w) : to(to), w(w) {}
};

struct Info {
    int id, time, num;
    Info(int id, int time, int num) : id(id), time(time), num(num) {}

    bool operator < (const Info &x) const {
        return time < x.time;
    }
};

struct Cmp {
    bool operator() (const Info &x, const Info &y) const {
        return x.time > y.time;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k; cin >> n >> m >> k;

    vector<int> A(n + 1);
    vector<vector<Edge>> g(n + 1);
    priority_queue<Info, vector<Info>, Cmp> heap;

    for (int i = 1; i <= n; i ++ ) cin >> A[i];

    for (int i = 0; i < k; i ++ ) {
        int t, n; cin >> t >> n;
        for (int j = 0, x; j < n; j ++ ) cin >> x, heap.push({x, t, INF});
    }

    for (int i = 0; i < m; i ++ ) {
        int a, b, w; cin >> a >> b >> w;
        g[a].push_back(Edge(b, w));
    }
    
    vector<bool> st(n + 1);
    vector<int> pt(n + 1), res(n + 1);
    
    for (int i = 1; i <= n; i ++ ) if (!A[i]) heap.push({i, 0, 0});
    
    while (heap.size()) {
        auto [u, time, num] = heap.top(); heap.pop();
        pt[u] += num;
        if (!st[u] && pt[u] >= A[u]) {
            st[u] = true, res[u] = time;
            for (auto [v, w] : g[u]) {
                heap.push({v, time + w, 1});
            }
        }
    }

    for (int i = 1; i <= n; i ++ ) cout << (st[i] ? res[i] : -1) << " \n"[i == n];
    return 0;
}