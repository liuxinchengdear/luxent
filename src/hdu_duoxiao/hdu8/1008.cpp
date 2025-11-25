#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T; cin >> T; while (T -- ) {
        int n, m; cin >> n >> m;
        string s, t; cin >> s >> t;
        auto sp = s.find(0x31), tp = t.find(0x31);
        if (sp < tp) { cout << "-1\n"; continue; }

        s = s.substr(sp); t = t.substr(tp);
        int cnt = 0;
        for (int i = 0; i <= s.size() - t.size(); i ++ ) {
            if (s[i] == 0x31) {
                for (int j = 0; j < t.size(); j ++ ) s[i + j] = s[i + j] == t[j] ? 0x30 : 0x31; 
                cnt ++ ;
            }
        }
        cout << (count(s.begin(), s.end(), 0x31) ? -1 : cnt) << '\n';
    }
    cout.flush(); system("pause");
    return 0;
}