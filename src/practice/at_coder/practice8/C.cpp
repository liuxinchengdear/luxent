#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s; 
    vector<vector<int>> p(26); vector<int> ans(26);
    int sum = 0;
    for (int i = 0; i < s.size(); i ++ ) {
        auto c = s[i] - 0x41;

        sum += p[c].size() * i - ans[c] - p[c].size();
        p[c].push_back(i); ans[c] += i;
    }

    cout << sum << endl;
    return 0;
}