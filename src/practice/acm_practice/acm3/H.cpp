#include <bits/stdc++.h>
using namespace std;

const int N = 35;

using pii = pair<int, int>;

int n;
char s[N][N];

queue<pii> q;

vector<vector<int>> dir{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
string mat = "CHINA";

int cnt = 0;

bool check(int x, int y, int nx, int ny) {
    if (nx < 0 || nx >= n || ny < 0 || ny >= n) return false;
    auto num = s[nx][ny];
    auto p = find(mat.begin(), mat.end(), num);
    if (p == mat.end()) return false;
    else {
        if (*prev(p) == s[x][y]) {
            if (*p == 'A') cnt ++ ;
            return true;
        }
        else return false;
    }
}

void bfs() {
    while (q.size()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i ++ ) {
            int nx = x + dir[i][0], ny = y + dir[i][1];
            if (check(x, y, nx, ny)) {
                q.push({nx, ny});
            }
        }
    }
    cout << cnt << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n;
    for (int i = 0; i < n; i ++ )
        for (int j = 0; j < n; j ++ ) {
            cin >> s[i][j], 
            s[i][j] == 'C' ? q.push({i, j}), 1 : 1;
        }
    
    bfs();
    return 0;
}