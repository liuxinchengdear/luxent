#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int a, na; cin >> a >> na;
    int b, nb; cin >> b >> nb; 
    int c, nc; cin >> c >> nc;

    cout << min({ceil(n * 1.0 / a) * na, ceil(n * 1.0 / b) * nb, ceil(n * 1.0 / c) * nc}) << endl;
    return 0;
}