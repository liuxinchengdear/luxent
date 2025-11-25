#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int l[N], r[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n; cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> l[i] >> r[i];

    sort(l + 1, l + 1 + n); sort(r + 1, r + 1 + n);

    int i = 1, j = 1;
    int room = 0, res = 0;
    while (i <= n && j <= n) {
        if (l[i] <= r[j]) room ++ , i ++ ;
        else room -- , j ++ ;
        res = max(res, room);
    }
    cout << res << endl;
    return 0;
}