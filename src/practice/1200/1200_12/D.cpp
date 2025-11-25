#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200010;

int dp[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i < N; i ++ ) {
        string s = to_string(i);
        dp[i] = dp[i - 1] + accumulate(s.begin(), s.end(), s.size() * -0x30);
    }

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}