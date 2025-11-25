#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Node {
    int pos, d, fg;

    bool operator > (const Node &x) const 
    {return d > x.d;}
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i ++ ) cin >> s[i];

    int st = 0, ed = 0;

    for (int i = 0; i < n; i ++ ) {
        for (int j = 0; j < m; j ++ ) {
            if (s[i][j] == 'S') st = i * m + j;
            if (s[i][j] == 'G') ed = i * m + j;
        }
    }

    vector<array<int, 2>> dist(n * m, {INF, INF});

    auto dijkstra = [&](int pos) -> int {
        priority_queue<Node, vector<Node>, greater<Node>> heap; heap.push({pos, 0, 0}); dist[pos][0] = 0;

        vector<array<int, 2>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        auto outline = [&](int x, int y) -> bool 
        {return x < 0 || x >= n || y < 0 || y >= m;};

        auto novalid = [&](int x, int y, int fg) -> bool 
        {return s[x][y] == '#' || s[x][y] == 'o' && fg == 1 || s[x][y] == 'x' && fg == 0;};

        while (heap.size()) {
            auto [t, d, fg] = heap.top(); heap.pop();
            int x = t / m, y = t % m;

            for (int i = 0; i < 4; i ++ ) {
                int nfg = fg;
                int nx = x + dir[i][0], ny = y + dir[i][1];
                int np = nx * m + ny;
                if (outline(nx, ny) || novalid(nx, ny, fg)) continue;

                if (s[nx][ny] == '?') nfg ^= 1;
                if (dist[np][nfg] > d + 1) 
                {dist[np][nfg] = d + 1; heap.push({np, d + 1, nfg});}
            }
        }
        return min(dist[ed][0], dist[ed][1]);
    };

    auto dis = dijkstra(st);
    cout << (dis == INF ? -1 : dis) << '\n';
    return 0;
}