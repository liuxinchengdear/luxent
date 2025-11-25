#include <bits/stdc++.h>
using namespace std;

const int N = 1000010, M = N << 1;

int h[N], e[M], ne[M], idx;
int p[N], dp[N];

struct Node {
    int id, w;
    bool operator < (const Node &x) const {
        return w < x.w;
    }
}w[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

int find(int x) {
    return x == p[x] ? p[x] : p[x] = find(p[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        memset(h, -1, (n + 1) * sizeof(int));
        idx = 0;
        for (int i = 0; i + 1 < n; i ++ ) {
            int a, b; cin >> a >> b;
            add(a, b), add(b, a);
        }
        for (int i = 1, x; i <= n; i ++ ) {
            cin >> x; w[i] = {i, x};
        }
        sort(w + 1, w + 1 + n);

        memset(p, -1, (n + 1) * sizeof(int));
        memset(dp, -1, (n + 1) * sizeof(int));
        for (int i = 1; i <= n; i ++ ) {
            auto [id, wei] = w[i];
            p[id] = id; dp[id] = 1;
            for (int j = h[id]; ~ j; j = ne[j]) {
                int k = e[j];
                if (p[k] != -1) {
                    auto t = find(k);
                    p[t] = id;
                }
            }
        }

        for (int i = 1; i <= n; i ++ ) cout << dp[i] << '\n';
    }
    return 0;
}