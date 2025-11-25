#include <bits/stdc++.h>
using namespace std;

#define MULTI int _T; cin >> _T; while (_T -- )

const int N = 200010;

int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    MULTI {
        int n, k; cin >> n >> k;
        for (int i = 0; i < n; i ++ ) cin >> a[i], a[i] %= k, a[i] = min(a[i], k - a[i]);

        for (int i = 0; i < n; i ++ ) cin >> b[i], b[i] %= k, b[i] = min(b[i], k - b[i]);

        sort(a, a + n); sort(b, b + n);
        bool flag = true;
        for (int i = 0; i < n; i ++ ) if (a[i] != b[i]) { flag = false; break; }

        cout << (flag ? "YES\n" : "NO\n");
    }
    cout.flush(); system("pause");
    return 0;
}