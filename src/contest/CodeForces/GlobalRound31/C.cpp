#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & -(x))

ostream& operator << (ostream &cout, const vector<int> &x) {
    for (auto e : x) cout << e << " ";
    return cout;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;

        vector<int> a(k);

        if (k & 1) { fill(a.begin(), a.end(), n); cout << a << endl; continue; }

        if (__builtin_popcount(n) == 1) { fill(a.begin() + 1, a.end(), n); cout << a << endl; continue; }

        vector<int> res; int nt = n;
        while (nt) {
            int t = lowbit(nt); nt -= t;
            res.push_back(t);
        }

        int t = res.back() + res[res.size() - 2] - 1;
        a[0] = t; a[1] = t ^ n; if (a[0] > a[1]) swap(a[0], a[1]);

        if (n > a[0] + a[1]) a[0] = 0, a[1] = n;

        fill(a.begin() + 2, a.end(), n);
        cout << a << endl;
    }
    return 0;
}