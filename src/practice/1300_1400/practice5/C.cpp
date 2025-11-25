#include <bits/stdc++.h>
using namespace std;

#define int long long

#define lowbit(x) ((x) & -(x))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, l, r, k; cin >> n >> l >> r >> k;

        if (n & 1) {cout << l << endl; continue;}

        if (n == 2) {cout << "-1\n"; continue;}

        int num, nl = l;
        while (nl) {num = lowbit(nl); nl -= num;}
        if (num << 1 > r) cout << "-1\n";
        else {
            if (n - k <= 1) cout << (num << 1) << endl;
            else cout << l << endl;
        }
    }
    return 0;
}