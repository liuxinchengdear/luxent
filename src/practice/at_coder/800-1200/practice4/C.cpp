#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++ ) cin >> a[i];

    vector<int> res{ 1 };
    for (int i = 2; i < n; i ++ ) {
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) res.push_back(i);
        if (a[i] < a[i - 1] && a[i] < a[i + 1]) {
            if (res.size() == 1) { res.back() = i; continue; }
            res.push_back(i);
        }
    }

    res.push_back(n);

    int sum = 0;
    for (int i = 1; i + 2 < res.size(); i += 2) sum += (res[i] - res[i - 1]) * (res[i + 2] - res[i + 1]);

    cout << sum << endl;
    return 0;
}