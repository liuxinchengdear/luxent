#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    list<int> li;

    int n, k; cin >> n >> k;

    for (int i = 1; i <= n; i ++ ) {
        li.push_back(i);
    }

    auto st = li.begin();
    bool flag = true;
    while (n -- > 1) {
        if (k & 1 || flag) {
            for (int i = 1; i < k; i ++ ) {
                st = next(st);
                if (st == li.end()) st = li.begin();
            }
            flag = false;
        }
        else {
            for (int i = 1; i < k; i ++ ) {
                if (st == li.begin()) st = prev(li.end());
                else st = prev(st);
            }
        }
        k += *st;
        auto pre = st == li.begin() ? prev(li.end()) : prev(st), nxt = next(st) == li.end() ? li.begin() : next(st);
        li.erase(st);
        if (k & 1) st = nxt;
        else st = pre;
    }
    cout << *li.begin() << endl;
    return 0;
}