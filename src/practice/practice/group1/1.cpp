#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    
    int li, len; li = len = 2000;
    vector<vector<int>> dp(len + 1, vector<int>(li + 1));
    for (int i = 1; i <= li; i ++ ) dp[1][i] = 1;
    for (int i = 2; i <= len; i ++ ) {
        for (int j = 1; j <= li; j ++ ) {
            for (int k = j; k <= li; k += j) dp[i][k] = (dp[i][k] + dp[i - 1][j]) % mod;
        }
    }

    int _T; cin >> _T; while (_T -- ) {
        cin >> li >> len;
        int res = 0;
        for (int i = 1; i <= li; i ++ ) res = (res + dp[len][i]) % mod;
        cout << res << '\n';
    }
    return 0;
}