#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        vector<int> odd, even; 
        for (int i = 0; i < n; ++ i) {
            int x; cin >> x;
            x & 1 ? odd.push_back(x) : even.push_back(x);
        }

        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end(), greater<int>());

        if (!odd.size()) {
            for (int i = 1; i <= n; ++ i) cout << 0 << " \n"[i == n];
            continue;
        }

        if (!even.size()) {
            for (int i = 1; i <= n; ++ i) cout << (i & 1 ? odd.front() : 0) << " \n"[i == n];
            continue;
        }

        vector<int> res(n + 1); 
        if (odd.size()) res[1] = odd.front();
        if (even.size()) res[1] = max(res[1], even.front());

        for (int i = 2; i <= 1 + even.size(); ++ i) {
            if (i == 2) res[i] = odd.front() + even[i - 2];
            else res[i] = res[i - 1] + even[i - 2];
        }
    }
    return 0;
}