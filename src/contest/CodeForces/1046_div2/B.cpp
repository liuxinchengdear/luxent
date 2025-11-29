#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        s = " " + s;
        int len = 0, t = 0;
        for (int i = 1; i <= n; i ++ ) {
            if (s[i] == 0x31) t ++ , len = max(len, t);
            else t = 0;
        }
        if (k <= len) cout << "NO\n";
        else {
            cout << "YES\n";
            int num = 0;
            vector<int> v(n + 1);
            for (int i = 1; i <= n; i ++ ) {
                if (s[i] == 0x31) v[i] = ++ num;
            }
            for (int i = 1; i <= n; i ++ ) {
                if (s[i] == 0x30) v[i] = ++ num;
            }
            for (int i = 1; i <= n; i ++ ) 
                cout << v[i] << " \n"[i == n];
        }
    }
    return 0;
}