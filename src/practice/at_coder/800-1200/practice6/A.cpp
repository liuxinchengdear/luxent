#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

// 变成了一个图论问题
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pii> a(n + 1), b(n + 1);

    vector<vector<int>> g(n + 1);

    for (int i = 1; i <= n; i ++ ) cin >> a[i].first;
    for (int i = 1; i <= n; i ++ ) cin >> a[i].second;

    auto merge = [&](int l, int mid, int r) -> void {
        int i = l, j = mid + 1, t = l;
        while (i <= mid && j <= r) {
            if (a[i] < a[j]) b[t ++ ] = a[i ++ ];
            else {
                if (a[i].second == a[j].second) g[a[i].first].push_back(a[j].first), g[a[j].first].push_back(a[i].first);
                b[t ++ ] = a[j ++ ];
            }
        }
        while (i <= mid) b[t ++ ] = a[i ++ ];
        while (j <= r) b[t ++ ] = a[j ++ ];
        for (int i = l; i <= r; i ++ ) a[i] = b[i];
    };

    auto merge_sort = [&](auto &&merge_sort, int l, int r) -> void {
        if (l >= r) return;
        int mid = l + r >> 1;
        merge_sort(merge_sort, l, mid); merge_sort(merge_sort, mid + 1, r);
        merge(l, mid, r);
    };

    merge_sort(merge_sort, 1, n);

    for (int i = 1; i <= n; i ++ ) cout << a[i].first << " \n"[i == n];
    for (int i = 1; i <= n; i ++ ) cout << a[i].second << " \n"[i == n];

    for (int i = 1; i <= n; i ++ ) {
        cout << i << ": ";
        for (auto e : g[i]) cout << e << " "; cout << endl;
    }

    return 0;
}