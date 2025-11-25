#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> dp(3, vector<int>(n + 1)), pre(3, vector<int>(n + 1)), suff(3, vector<int>(n + 2));
        
        int sum = 0;
        for (int i = 1; i <= 2; i ++ ) {
            for (int j = 1; j <= n; j ++ ) {
                cin >> dp[i][j]; sum += dp[i][j];
                pre[i][j] = pre[i][j - 1] + dp[i][j];
            }
        }
        for (int i = 1; i <= 2; i ++ ) {
            for (int j = n; j ; j -- ) suff[i][j] = suff[i][j + 1] + dp[i][j];
        }

        if (n & 1) {
            if (n == 1) {
                int x = dp[1][1], y = dp[2][1];
                cout << (x == y ? "draw\n" : (x > y ? "Mandy\n" : "brz\n"));
                continue;   
            }
            int x = max(pre[1][n >> 1] + pre[2][n >> 1], pre[1][n + 1 >> 1] + min(pre[2][n + 1 >> 1], suff[1][n + 3 >> 1])), y = sum - x;
            cout << (x == y ? "draw\n" : (x > y ? "Mandy\n" : "brz\n"));
        }
        else {
            if (n == 2) {
                int x = dp[1][1] + max(dp[1][2], dp[2][1]), y = sum - x;
                cout << (x == y ? "draw\n" : (x > y ? "Mandy\n" : "brz\n"));
                continue;
            }
            int x = max(pre[1][n >> 1] + pre[2][n >> 1], min(pre[1][n], pre[1][n + 2 >> 1] + pre[2][n + 2 >> 1])), y = sum - x;
            cout << (x == y ? "draw\n" : (x > y ? "Mandy\n" : "brz\n"));
        }
    }
    return 0;
}