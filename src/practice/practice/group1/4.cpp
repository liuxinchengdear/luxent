#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> st(n);
    for (auto &e : st) cin >> e;
    vector<pair<int, int>> range;
    vector<int> L, R; 
    for (int i = 0; i < n; i ++ ) {
        int l, r; cin >> l >> r; 
        st[i] ? range.emplace_back(l, r), 1 : (L.push_back(r), R.emplace_back(l), 1);
    }

    sort(L.begin(), L.end());
    sort(R.begin(), R.end());

    long long res = 0;
    for (int i = 0; i < range.size(); i ++ ) {
        auto [l, r] = range[i];
        auto num1 = lower_bound(R.begin(), R.end(), l) - R.begin();
        auto num2 = lower_bound(L.begin(), L.end(), r + 1) - L.begin();

        res += num2 - num1;
    }
    cout << res << endl;
    return 0;
}