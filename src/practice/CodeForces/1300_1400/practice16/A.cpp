#include <bits/stdc++.h>
using namespace std;

struct Node {
    int a, b;

    bool operator < (const Node &x) const {
        if (min(a, b) != min(x.a, x.b)) return min(a, b) < min(x.a, x.b);
        return max(a, b) < max(x.a, x.b);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<Node> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i ++ ) {
            int x, y; cin >> x >> y; a[i] = { x, y };
        }

        auto merge = [&](int l, int mid, int r) -> void {
            int i = l, j = mid + 1, t = l;
            while (i <= mid && j <= r) {
                if (less<Node>()(a[i], a[j])) b[t ++ ] = a[i ++ ];
                else b[t ++ ] = a[j ++ ];
            }
            while (i <= mid) b[t ++ ] = a[i ++ ];
            while (j <= r) b[t ++ ] = a[j ++ ];
            for (int i = l; i <= r; i ++ ) a[i] = b[i];
        };

        auto merge_sort = [&](this auto &&merge_sort, int l, int r) -> void {
            if (l >= r) return;
            int mid = l + r >> 1;
            merge_sort(l, mid); merge_sort(mid + 1, r);
            merge(l, mid, r);
        };

        merge_sort(1, n);

        for (int i = 1; i <= n; i ++ ) cout << a[i].a << " " << a[i].b << " \n"[i == n];
        continue;
    }
    return 0;
}