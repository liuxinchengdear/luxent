#include <bits/stdc++.h>
using namespace std;

#define MULTI int _T; cin >> _T; while (_T -- )

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    MULTI {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        
        long long res = 0;
        for (int i = 0, x; i < n; i ++ ) {
            cin >> x;
            res += x < a[i] ? a[i] - x : 0;
        }
        cout << (res + 1) << '\n';
    }
    cout.flush(); system("pause");
    return 0;
}