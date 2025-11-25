#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int x, n; cin >> x >> n;

        int d = 1;
        for (int i = 1; i <= x / i; i ++ ) {
            if (x % i == 0) {
                if (x / i >= n) d = max(d, i);
                if (i >= n) d = max(d, x / i);
            }
        }
        cout << d << '\n';
    }
    return 0;
}