#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;

int n;

vector<array<int, 2>> dir{{1, 0}, {0, 1}, {-1, 0}, {0, 1}};

bool outline(int x, int y) {
    return x < 1 || x > n || y < 1 || y > n;
}

void dfs(int x, int y, int num, int op) {
    if (num == n * n + 1) return ;
    g[x][y] = num;
    if (op % 4 == 1 || op % 4 == 3) ++ op;
    auto nx = x + dir[op % 4][0], ny = y + dir[op % 4][1];
    if (outline(nx, ny)) nx = x + dir[( ++ op) % 4][0], ny = y + dir[op % 4][1];
    dfs(nx, ny, num + 1, op);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n; g.resize(n + 1);

    for (int i = 1; i <= n; i ++ ) g[i].resize(n + 1);

    dfs(1, 1, 1, 0);

    cout << right;
    
    for (int i = 1; i <= n; i ++ ) {
        for (int j = 1; j <= n; j ++ ) {
            int t = max(g[1][j], g[n][j]), len = t >= 100 ? 3 : (t >= 10 ? 2 : 1);
            cout << setw(len) << g[i][j] << " \n"[j == n]; 
        }
    }
    return 0;
}