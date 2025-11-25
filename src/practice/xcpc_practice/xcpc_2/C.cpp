#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> a(m);
        for (int i = 0; i < m; i ++ ) cin >> a[i];

        sort(a.begin(), a.end());
        long long res = 0;
        if (a[0] > k) {
            for (int i = 0; i < m; i ++ ) {
                res += a[i] - k << 1;
            }
            res += k - 1 << 1;
        }
        else {
            for (int i = 1; i < m; i ++ ) {
                res += abs(a[i] - k) << 1;
            }
            res += k - 1 << 1;
        }
        cout << res << '\n';
    }
    return 0;
}

/*

1 - 5 - 6 - 5 - 7 - 1     -> 14

1 - 5 - 4 - 5 - 3 - 1     -> 10

对于样例 
10 4 5
3 4 6 7

1 - 5 - 6 - 5 - 7 - 5 - 4 - 5 - 3 - 1

*/