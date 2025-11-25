#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

struct Node {
    Node *ls, *rs;
    int l, r;
    int sum, add;

    Node(int l, int r) : l(l), r(r), sum(0), add(0) {
        ls = rs = nullptr;
    }

    bool inRange(int L, int R) {return l >= L && r <= R;}
    bool outRange(int L, int R) {return l > R || r < L;}

    inline void maketag(int x) {sum += (r - l + 1) * x; add += x;}

    void pushup() {sum = ls -> sum + rs -> sum;}
    void pushdown() {
        if (!ls) {int mid = l + r >> 1; ls = new Node(l, mid); rs = new Node(mid + 1, r);}
        if (add) {ls -> maketag(add); rs -> maketag(add); add = 0;}
    }

    void modify(int L, int R, int d) {
        if (inRange(L, R)) maketag(d);
        else if (!outRange(L, R)) {
            pushdown();
            ls -> modify(L, R, d);
            rs -> modify(L, R, d);
            pushup();
        }
    }

    int query(int L, int R) {
        if (inRange(L, R)) return sum;
        else if (outRange(L, R)) return 0;
        else {pushdown(); return ls -> query(L, R) + rs -> query(L, R);}
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q; cin >> n >> q;

    auto root = new Node(1, n);

    for (int op, l, r; q -- ;) {
        cin >> op >> l >> r;
        if (op == 1) {
            int d; cin >> d;
            root -> modify(l, r, d);
        }
        else cout << ((root -> query(l, r)) + (l + r) * (r - l + 1) / 2) << '\n';
    }
    return 0;
}