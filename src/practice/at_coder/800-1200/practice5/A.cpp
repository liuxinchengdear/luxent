#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        
        vector<int> a(n + 1); double sum = 0;
        for (int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];

        sort(a.begin(), a.end());

        double avg = sum * 1.0 / n; int p = lower_bound(a.begin(), a.end(), avg + 0.0000001) - a.begin();
        int res = n - p + 1; 
        for (int i = n; i > 1 ; i -- ) {
            sum -= a[i]; avg = sum / (i - 1); 
            p = lower_bound(a.begin(), a.end(), avg + 0.0000001) - a.begin();
            res = max(res, i - p);
        }

        cout << res << endl;
    }
    return 0;
}