#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s, t; cin >> s >> t;

    int ta = n, tb = -1;
    set<int> pa;
    vector<int> pb;
    for (int i = 0; i < n; i ++ ) { auto c = s[i];
        if (c != t[i]) {
            if (c == 0x41) pa.insert(i);
            if (c == 0x42) pb.push_back(i);
        }
        if (ta == n && t[i] == 0x41) ta = i;
        if (t[i] == 0x42) tb = i;
    }

    if (pa.size() && ta > *pa.begin() || pb.size() && tb < pb.back()) { cout << "-1\n"; exit(0); }

    int ans = pa.size() + pb.size();
    for (auto i : pb) {
        auto p = pa.lower_bound(i);
        if (p != pa.end()) pa.erase(p), ans -- ;
    }

    cout << ans << endl;
    return 0;
}