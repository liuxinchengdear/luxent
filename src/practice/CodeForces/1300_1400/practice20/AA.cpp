#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s; s = " " + s;

        auto calculate = [](vector<int> &dit) -> int {
            if (count(dit.begin(), dit.end(), 0)) return 0;

            auto t = accumulate(dit.begin(), dit.end(), 0) - count(dit.begin(), dit.end(), 1);

            return max(t, 1ll);
        };

        int res = 261;
        for (int i = 1; i < n; i ++ ) {
            vector<int> num;
            for (int j = 1; j <= n; j ++ ) {
                if (j == i) num.push_back(stoi(string(s.begin() + j, s.begin() + j + 2))), ++ j;
                else num.push_back(s[j] - 0x30);
            }

            res = min(res, calculate(num));
        }
        cout << res << endl;
    }
    return 0;
}