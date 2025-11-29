#include <bits/stdc++.h>
using namespace std;

#define MULTI  int _T; cin >> _T; while (_T -- )

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    MULTI {
        int n; cin >> n;
        for (int i = 1; i <= n; i ++ ) 
            cout << (i & 1 ? -1 : (i == n ? 2 : 3)) << " \n"[i == n];
    }
    cout.flush();
    system("pause");
    return 0;
}