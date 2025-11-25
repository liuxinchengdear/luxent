#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        vector<double> dis(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> dis[i];
        dis[0] = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        sort(dis.begin(), dis.end());
        double sum = 0;
        for (int i = 0; i < n; i ++ ) sum += dis[i];
        if (sum >= dis[n]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}