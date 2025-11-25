#include <bits/stdc++.h>
using namespace std;

const int N = 10010;

bool dp[N][N], p[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s; cin >> s;
    s = " " + s; int n = s.size() - 1;
    for (int i = 1; i <= n; i ++ ) dp[i][i] = true;

    for (int i = 1; i <= n; i ++ ) {
        if (s[i] == '(' && s[i + 1] == ')') p[i][i + 1] = true;
    }

    int cnt = 0;
    for (int len = 2; len <= n; len ++ ) {
        for (int i = 1; i <= n - len + 1; i ++ ) {
            int j = i + len - 1;
            p[i][j] = p[i][j] || max(p[i + 1][j], p[i][j - 1]);
            if (s[i] != s[j]) dp[i][j] = false;
            else {
                if (len <= 2) dp[i][j] = true;
                else {
                    dp[i][j] = dp[i + 1][j - 1];
                    if (dp[i][j] && p[i][j]) cnt ++ ;
                }
            }
        }
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}