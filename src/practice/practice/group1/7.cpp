#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100010;

int n, m;
int w[N];

struct Node {
    int l, r;
    int sum, add;
}tr[N << 2];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    if (tr[u].add) {
        auto &rt = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
        left.add += rt.add, left.sum += (left.r - left.l + 1) * left.add;
        right.add += rt.add, right.sum += (right.r - right.l + 1) * right.add;
        rt.add = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) tr[u] = {r, r, w[r], 0};
    else {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int v) {
    if (tr[u].l >= l && tr[u].r <= r) tr[u].sum += (tr[u].r - tr[u].l + 1) * v, tr[u].add += v;
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid) modify(u << 1, l, r, v);
        if (r > mid) modify(u << 1 | 1, l, r, v);
        pushup(u);
    }
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int res = 0;
        if (l <= mid) res = query(u << 1, l, r);
        if (r > mid) res += query(u << 1 | 1, l, r);
        return res;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    iota(w, w + n + 1, 0);

    build(1, 1, n);
    while (m -- ) {
        int op, l, r, k;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> k;
            modify(1, l, r, k);
        }
        else cout << query(1, l, r) << '\n';
    }
    return 0;
}