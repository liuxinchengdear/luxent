#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int l, a, b; cin >> l >> a >> b;
        
        vector<int> tmp; int mx = -1;
        for (int i = 0; ; ++ i) {
            tmp.push_back((a + b * i) % l);
            mx = max(mx, tmp.back());
            if (tmp.size() > 1 && tmp.back() == tmp.front()) break;
        }
        cout << mx << endl;
    }
    return 0;
}