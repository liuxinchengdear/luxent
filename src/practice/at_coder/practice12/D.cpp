#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); int sum = 0;
    for (int i = 0, cnt = 0; i < n; i ++ , cnt ++ ) {
        cin >> a[i];
        int num = cnt + n - 1 - i;
        sum += num * a[i];
    }

    sort(a.begin(), a.end()); int cnt = 0;
    for (int i = 0; i + 1 < n; i ++ ) {
        auto p = lower_bound(a.begin() + i + 1, a.end(), 100000000 - a[i]) - a.begin();
        cnt += n - p;
    }

    cout << static_cast<int>(sum - 100000000 * cnt) << endl;
    return 0;  
}