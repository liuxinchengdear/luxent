#include <bits/stdc++.h>
using namespace std;

// 47

int main() {
    ios::sync_with_stdio(false);;
    cin.tie(0);

    vector<int> a(48), b(48);
    a[1] = b[2] = 1;
    for (int i = 3; i <= 47; i ++ ) a[i] = a[i - 1] + a[i - 2], b[i] = b[i - 1] + b[i - 2];

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        if (k >= 47) cout << "0\n";
        else {
            // n = a[k] * x + b[k] * y
            int res = 0;
            for (int x = 0; x <= n / a[k]; x ++ ) {
                auto t = n - a[k] * x;
                res += t % b[k] == 0 && t / b[k] >= x;
            }
            cout << res << '\n';
        }
    }
    return 0;
}