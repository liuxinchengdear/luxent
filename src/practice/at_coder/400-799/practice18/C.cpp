#include  <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; string T; cin >> n >> T;

    vector<int> res;
    for (int i = 0; i < n; i ++ ) {
        string t; cin >> t;
        if (abs(int(t.size() - T.size())) > 1) continue;
        int cnt = 0;
        string nT = T;
        while (nT.size() && t.size()) {
            if (t.back() != nT.back()) {
                cnt ++ ;
                if (cnt > 1) break;
                else {
                    if (nT.size() > t.size()) { nT.pop_back(); continue; }
                    else if (nT.size() < t.size()) { t.pop_back(); continue; }
                }
            }
            nT.pop_back(); t.pop_back();
        }
        
        if (cnt <= 1) res.push_back(i + 1);
    }

    cout << res.size() << endl;
    for (auto e : res) cout << e << " "; cout << endl;
    return 0;
}