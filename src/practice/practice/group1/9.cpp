#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

struct Node {
    int l, r;
    int sum, add;
    Node *ls, *rs;

    Node(int l, int r) : l(l), r(r), sum(0), add(0) {
        ls = rs = nullptr;
    }
};

void pushup(Node *u) {
    u -> sum = u -> ls -> sum + u -> rs -> sum;
}

void makeadd (Node *u, int add) {
    u -> sum += (u -> r - u -> l + 1) * add; u -> add += add;
}

void pushdown(Node *u) {
    if (!(u -> ls)) {
        int mid = u -> l + u -> r >> 1;
        u -> ls = new Node (u -> l, mid);
        u -> rs = new Node (mid + 1, u -> r);
    }
    if (u -> add) {
        makeadd(u -> ls, u -> add);
        makeadd(u -> rs, u -> add);
        u -> add = 0;
    }
}

bool inRange(Node *u, int l, int r) {
    return l <= u -> l && u -> r <= r;
}

bool outRange(Node *u, int l, int r) {
    return u -> l > r || u -> r < l;
}

void modify(Node *u, int l, int r, int d) {
    if (inRange(u, l, r)) makeadd(u, d);
    else if (!outRange(u, l, r)){
        pushdown(u);
        modify(u -> ls, l, r, d);
        modify(u -> rs, l, r, d);
        pushup(u);
    }
}

int query(Node *u, int l, int r) {
    if (inRange(u, l, r)) return u -> sum;
    else if (outRange(u, l, r)) return 0;
    else {
        pushdown(u);
        return query(u -> ls, l, r) + query(u -> rs, l, r);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    auto root = new Node(1, n);
    for (int op, l, r; q -- ;) {
        cin >> op >> l >> r;
        if (op == 1) {
            int d; cin >> d;
            modify(root, l, r, d);
        }
        else cout << query(root, l, r) + (r - l + 1) * (r + l) / 2 << '\n';
    }
    return 0;
}