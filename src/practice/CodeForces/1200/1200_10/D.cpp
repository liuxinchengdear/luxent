#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        string a, b; cin >> a >> b;
        string c = string(a.size(), 0x30), d = c;
        for (int i = 0; i < a.size(); i ++ ) c[i] = max(a[i], b[i]), d[i] = min(a[i], b[i]);
        
        for (int i = 0; i < a.size(); i ++ ) {
            if (a[i] > b[i]) {
                a = a.substr(0, i + 1) + d.substr(i + 1);
                b = b.substr(0, i + 1) + c.substr(i + 1);
                break;
            }
            else if (a[i] < b[i]) {
                a = a.substr(0, i + 1) + c.substr(i + 1);
                b = b.substr(0, i + 1) + d.substr(i + 1);
                break;
            }
        }
        cout << a << '\n' << b << '\n';
    }
    return 0;
}