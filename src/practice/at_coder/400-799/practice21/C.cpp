#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long

#define lowbit(x) ((x) & -(x))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        if (n == 7) { cout << "7\n"; continue; }
        
        auto count = [](int x) -> int {
            int len = 0;
            while (x) x >>= 1, len ++ ;
            return len;
        };

        int t = count(n);
        if (t <= 3) { cout << "-1\n"; continue; }

        int cnt = __builtin_popcountll(n);
        while (cnt < 3) n -- , cnt = __builtin_popcountll(n);
        while (cnt != 3) cnt -- , n -= lowbit(n);
        cout << n << endl;
    }
    return 0;
}