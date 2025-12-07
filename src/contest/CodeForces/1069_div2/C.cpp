#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        string s, t; cin >> s >> t;

        vector<int> sa(26), ta(26);
        for (auto c : s) sa[c - 0x61] ++ ;
        for (auto c : t) ta[c - 0x61] ++ ;

        bool fg = true;
        for (int i = 0; i < 26; i ++ ) {
            if (ta[i] < sa[i]) { fg = false; break; }
        }

        if (!fg) { cout << "Impossible\n"; continue; }

        sort(t.begin(), t.end());

        vector<string> res;
        for (int i = 0; i < 26; i ++ ) {
            ta[i] -= sa[i]; 
            if (ta[i]) res.push_back(string(ta[i], 0x61 + i));
        }

        vector<string> tmp;
        for (int  i = 0; i < s.size(); ++ i) {
            int j = i;
            while (i + 1 < s.size() && s[i + 1] <= s[i]) ++ i;
            tmp.push_back(string(s.begin() + j, s.begin() + i + 1));
        }

        int i = 0, j = 0;
        while (i < res.size() && j < tmp.size()) {
            if (res[i].front() < tmp[j].front()) cout << res[i ++ ];
            else cout << tmp[j ++ ];
        }

        while (i < res.size()) cout << res[i ++ ];
        while (j < tmp.size()) cout << tmp[j ++ ];
        cout << endl;
    }
    return 0;
}