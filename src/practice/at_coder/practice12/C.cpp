#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id, a, c;

    bool operator < (const Node &x) const {
        return a < x.a || a == x.a && c < x.c;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<Node> a(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        int l, r; cin >> l >> r;
        a[i] = {i, l, r};        
    }

    sort(a.begin() + 1, a.end());

    vector<bool> st(n + 1);
    int mn = 1e9;
    for (int i = n; i ; i -- ) {
        int tmp = mn;
        while (i && a[i].a == a[i - 1].a) {
            tmp = min(mn, a[i].c);
            if (a[i].c > mn) st[a[i].id] = true;
            i -- ;
        } 
        if (a[i].c > mn) st[a[i].id] = true; tmp = min(mn, a[i].c);
        mn = tmp;
    }

    cout << count(st.begin() + 1, st.end(), false) << endl;
    for (int i = 1; i <= n; i ++ ) {
        if (!st[i]) cout << i << " \n"[i == n];
    }
    return 0;
}