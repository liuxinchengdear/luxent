#include <bits/stdc++.h>
using namespace std;

string mul(string a, int b) {
    string c;
    long long t = 0;
    for (int i = a.size() - 1; ~ i; i -- ) {
        int da = a[i] - 0x30; 
        long long pro = 1ll * da * b; 
        c.push_back((pro + t) % 10 + 0x30); 
        t = (t + pro) / 10;
    }
    while (t) { c.push_back(t % 10 + 0x30); t /= 10; }
    reverse(c.begin(), c.end());
    return c;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<double> w(n + 1);

    for (int i = 1; i <= n; i ++ ) w[i] = log(i);

    vector<double> dp(n + 1);
    vector<int> fg(n + 1);
    for (int i = 1; i <= n; i ++ ) {
        for (int j = n; j >= i; j -- ) if (dp[j - i] + w[i] > dp[j]) dp[j] = dp[j - i] + w[i], fg[j] = j - i;
    }

    vector<int> res;
    for (int p = n; p ; p = fg[p]) res.push_back(p - fg[p]);

    sort(res.begin(), res.end());

    string ans = "1";
    for (auto e : res) cout << e << " ", ans = mul(ans, e); cout << endl;;
    cout << ans << endl;

    return 0;
}