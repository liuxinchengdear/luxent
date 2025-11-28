#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        if (k > n) { cout << "No\n"; continue; }

        vector<int> power(39); power[0] = 1;
        for (int i = 1; i <= 38; i ++ ) power[i] = 3 * power[i - 1];

        int cnt = 0;
        while (n) {
            auto p = lower_bound(power.begin(), power.end(), n + 1);
            n -= *(prev(p)); cnt ++ ;
        }

        if (k < cnt || (k - cnt) & 1) { cout << "No\n"; continue; }

        cout << "Yes\n";
    }
    return 0;
}