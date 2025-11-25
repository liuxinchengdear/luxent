#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s;

    vector<int> pos;
    for (int i = 0; i < n; i ++ ) if (s[i] == 0x31) pos.push_back(i);

    int cnt = pos.size();
    int res = 0;
    auto half = cnt >> 1;
    if (cnt & 1) {
        auto refer = pos[half];
        for (auto e : pos) res += abs(e - refer);
        res -= half * (half + 1);
    }
    else {
        auto tmp = 1ll * half * (half - 1) / 2 + 1ll * half * (half + 1) / 2;
        int t1 = 0, t2 = 0;
        auto refer = pos[half - 1];
        for (auto e : pos) t1 += abs(e - refer);
        refer = pos[half];
        for (auto e : pos) t2 += abs(e - refer);
        res = min(t1, t2) - tmp;
    }
    cout << res << endl;
    return 0;
}