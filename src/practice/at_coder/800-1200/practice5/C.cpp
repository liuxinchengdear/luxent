#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, d; cin >> n >> d;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    sort(a.begin() + 1, a.end());

    if (n == 1) return cout << "0\n", 0;

    vector<int> diff; int cnt = 0;
    for (int i = 2; i <= n; i ++ ) diff.push_back(a[i] - a[i - 1]);

    for (auto e : diff) cout << e << " "; cout << endl;

    for (int i = 0; i < diff.size(); i ++ ) {
        int sum = 0;
        while (i < diff.size() && sum < d) sum += diff[i ++ ];
        if (sum == d) { 
            cnt ++ ; i -- ;
            if (i + 1 < diff.size()) diff[i + 1] += diff[i];
        }
    }
    cout << cnt << endl;
    return 0;
}