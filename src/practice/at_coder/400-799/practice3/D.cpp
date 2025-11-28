#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, L; cin >> n >> L;

    if (L % 3) {cout << "0\n"; return 0;}

    vector<int> a(L); a[0] = 1;
    int cur = 0;
    for (int i = 0; i + 1 < n; i ++ ) {
        int d; cin >> d;
        cur = (cur + d) % L; a[cur] ++ ;
    }

    int prt = L / 3, sum = 0;
    for (int i = 0; i < prt; i ++ ) {
        sum += 1ll * a[i] * a[i + prt] * a[i + prt * 2];
    }
    cout << sum << endl;
    return 0;
}