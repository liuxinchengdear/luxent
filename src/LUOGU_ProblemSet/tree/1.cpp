#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

struct Node {
    int l, r;
    int on, add;
}tr[N << 2];

void pushup(int u) {
    tr[u].on = tr[u << 1].on + tr[u << 1 | 1].on;
}

void eval(Node &t) {
    t.on = (t.r - t.l + 1) - t.on; t.add = !t.add;
}

void pushdown(int u) {
    if (tr[u].add) {
        eval(tr[u << 1]);
        eval(tr[u << 1 | 1]);
        tr[u].add = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {r, r, 0, 0};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    }
}

void modify(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) eval(tr[u]);
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r);
        if (r > mid) modify(u << 1 | 1, l, r);
        pushup(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].on;
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int sum = 0;
        if (l <= mid) sum = query(u << 1, l, r);
        if (r > mid) sum += query(u << 1 | 1, l, r);
        return sum;
    }
}

ostream& operator << (ostream &os, const Node &X) {
    os << X.l << " " << X.r << " " << X.on << " " << X.add;
    return os;
}

void dfs (int u) {
    if (tr[u].l) {
        dfs(u << 1);
        cout << tr[u] << endl;
        dfs(u << 1 | 1);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    build(1, 1, n);

    while (m -- ) {
        int op, l, r; cin >> op >> l >> r;
        if (op == 0) modify(1, l, r);
        else cout << query(1, l, r) << endl;
    }
    return 0;
}