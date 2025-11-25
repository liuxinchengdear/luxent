#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<pii> a(n);
        for (int i = 0; i < n; i ++ ) {
            int  x; cin >> x; a[i] = make_pair(x, i + 1);
        }

        auto mx = max_element(a.begin(), a.end()), mn = min_element(a.begin(), a.end());
        
        if (mn -> first == 1 && mx -> first != mn -> first) {cout << "-1\n"; continue;}

        if (mx -> first == mn -> first) {cout << "0\n"; continue;}

        int sum = 0;
        vector<pii> res;

        while (true) {
            auto mx = max_element(a.begin(), a.end()), mn = min_element(a.begin(), a.end());
            if (mx -> first == mn -> first) break;
            sum ++ ; 
            mx -> first = mx -> first / mn -> first + (mx -> first % mn -> first > 0);
            res.emplace_back(make_pair(mx -> second, mn -> second));
        }
        cout << sum << '\n';
        for (auto [a, b] : res) cout << a << " " << b << '\n';
    }
    return 0;
}