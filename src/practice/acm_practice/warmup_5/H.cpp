#include <bits/stdc++.h>
using namespace std;

const int N = 5000010;

struct Node {
    int l, r; 
    int res;
}tr[N << 2];

void pushup(Node &u, Node &l, Node &r) {
    u.res = l.res == (l.r - l.l + 1) ? l.res + r.res : l.res;
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {r, r};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u, int x, int v) {
    if (tr[u].l == tr[u].r && tr[u].l == x) tr[u] = {x, x, v};
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid) modify(u << 1, x, v);
        if (x > mid) modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

Node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid) return query(u << 1, l, r);
        else if (l > mid) return query(u << 1 | 1, l, r);
        else {
            Node res;
            Node lN = query(u << 1, l, r), rN = query(u << 1 | 1, l, r);
            pushup(res, lN, rN);
            return res;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    build(1, 1, n);
    for (int  i = 1; i <= n; i ++ ) {
        int op, x; cin >> op >> x;
        if (op == 1) modify(1, x, 1);
        else {
            modify(1, x, 1);
            auto e = query(1, 1, n);
            cout << e.res + 1 << '\n';
            modify(1, x, 0);
        }
    }
    return 0;
}