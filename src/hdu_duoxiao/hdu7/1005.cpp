#include <bits/stdc++.h>
using namespace std;

#define MULTI int _T; cin >> _T; while (_T -- )

const int N = 15;

int n, m, k;
int a[N][N], pi[N][N];

bool check(int x, int y, int p) {
    return x >= 1 && x <= n && y >= 1 && y <= m && p > pi[x][y];
}

void draw(int x, int y, int d, int p) {
    if (check(x - 4, y, p)) a[x - 4][y] = d, pi[x - 4][y] = p;
    for (int i = 0; i < 3; i ++ ) 
        if (check(x - 3, y - 1 + i, p)) a[x - 3][y - 1 + i] = d, pi[x - 3][y - 1 + i] = p;
    for (int i = 0; i < 5; i ++ ) 
        if (check(x - 2, y - 2 + i, p)) a[x - 2][y - 2 + i] = d, pi[x - 2][y - 2 + i] = p;
    if (check(x - 1, y, p)) a[x - 1][y] = d, pi[x - 1][y] = p;
    if (check(x, y, p)) a[x][y] = d, pi[x][y] = p;
}


int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);

    MULTI {
        cin >> n >> m >> k;

        memset(a, 0, sizeof a);
        memset(pi, 0, sizeof pi);

        for (int i = 1; i <= k; i ++ ) {
            int x, y; cin >> x >> y;
            draw(x, y, i, x);
        }
        for (int i = 1; i <= n; i ++ ) {
            for (int j = 1; j <= m; j ++ )
                cout << (a[i][j] ? (char)(a[i][j] + 0x30) : '.');
            cout << '\n';
        }
    }
    cout.flush(); system("pause");
    return 0;
}