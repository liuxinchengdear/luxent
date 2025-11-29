#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k;; cin >> n >> k;

        if (k >= 30) {cout << "0\n"; continue;}
        int ans = 0;
        for (int i = 1; i <= n; i ++ ) {
            int first = i, second = n;
            bool vl = true;
            for (int j = 0; j < k - 2; j ++ ) {
                int fx = first; 
                first = second - first; second = fx;
                vl &= first <= second;
                vl &= min(first, second) >= 0;
                if (!vl) {break;}
            }
            ans += vl;
        }
        cout << ans << '\n';
    }
    return 0;
}