#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n); int sum = 0;
    for (int i = 0; i < n; i ++ ) cin >> a[i], sum += a[i];

    int avg = sum / n, r = sum % n;

    vector<int> b(n, avg);
    for (int i = 0; i < r; i ++ ) b[n - 1 - i] += 1;

    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < n; i ++ ) res += abs(a[i] - b[i]);

    cout << (res >> 1) << endl;
    return 0;
}