#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; while (t -- ) {
        int n; cin >> n;

        vector<ll> a(22), b{-1, 2, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, -9, -10};
        a[1] = 3;
        for (int i = 2; i <= 20; i ++ ) a[i] = a[i - 1] + b[i >> 1], a[i] += a[i - 1];

        cout << a[n] << endl;
    }
    cout.flush(); system("pause");
    return 0;
}