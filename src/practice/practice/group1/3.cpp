#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, p;
    // 多重背包
    while (cin >> n >> p) {
        vector<int> v, w;
        for (int i = 0; i < n; i ++ ) {
            int num, vv, charm; cin >> num >> vv >> charm;
            int j = 1;
            while (j <= num) v.push_back(vv * j), w.push_back(charm * j), num -= j, j <<= 1;
            if (num) v.push_back(num * vv), w.push_back(num * charm);
        }
        vector<int> dp(p + 1);
        for (int i = 0; i < v.size(); i ++ ) {
            for (int j = p; j >= v[i]; j -- ) {
                dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        cout << dp[p] << '\n';
    }
    return 0;
}