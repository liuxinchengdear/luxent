#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, k; cin >> n >> m >> k;
        string s; cin >> s; s = "L" + s + "L";
        
        vector<int> pos;
        for (int i = 0; i <= n + 1; i ++ ) if (s[i] == 'L') pos.push_back(i);

        vector<int> pre(n + 2);
        for (int i = 1; i <= n + 1; i ++ ) pre[i] = pre[i - 1] + (s[i] == 'C');

        int sum = 0;
        bool flag = true;
        for (int i = 1; i < pos.size(); i ++ ) {
            string t = s.substr(pos[i - 1] + 1, pos[i] - pos[i - 1] - 1);
            if (m <= t.size()) {
                int p = pos[i - 1] + m;
                sum += t.size() - m + 1;
                if (pre[pos[i]] - pre[p - 1] || sum > k) {flag = false; break;}
            }
        }

        cout << (flag ? "YES" : "NO") << '\n';
    }
    return 0;
}