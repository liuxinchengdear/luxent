#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, a, b; cin >> n >> a >> b;

        if (a > b) {
            if (n % 2 == a % 2 && a % 2 == b % 2) cout << "YES\n";
            else cout << "NO\n";
        }
        else {
            if (n % 2 == b % 2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}