#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        string s; cin >> s;
        vector<int> t(9), pre(s.size());

        for (int i = 9; i < s.size(); i ++ ) {
            pre[i] = pre[i - 1];
            if (s[i] == 'a') pre[i] ++ ;
        }

        int res = 0;
        for (int i = 0; i < s.size(); i ++ ) {
            if (s[i] == 'n') t[0] += 1, t[2];
            else if (s[i] == 'e') t[1]
            res = (res + 1LL * );
        }
    }
}