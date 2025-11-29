#include <bits/stdc++.h>
using namespace std;

#define MULTI int _T; cin >> _T; while (_T -- )

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    MULTI {
        string s; cin >> s;
        if (s == "0") {
            cout << "10\n"; continue;
        }
        if (s[0] == '-') {
            int i = 1; 
            while (i < s.size() && s[i] <= 0x31) i ++ ;
             cout << s.substr(0, i) << 1 << s.substr(i) << '\n';
        }
        else {
            int i = 0;
            while (i < s.size() && s[i] > 0x31) i ++ ;
            cout << s.substr(0, i) << 1 << s.substr(i) << '\n';
        }
    }
    cout.flush();
    system("pause");
    return 0;
}