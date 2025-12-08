#include <bits/stdc++.h>
using namespace std;

int n, c;
vector<int> a;

vector<int> d;

int dfs(int dep, int num, int cnt, int st) {
    if (dep == n) return cnt;

    int res = 0;
    for (int i = 0; i < n; i ++ ) {
        if (!(st >> i & 1)) {
            if (num + a[i] == c) res = max(res, dfs(dep + 1, 0, cnt + 1, st + (1 << i)));
            else res = max(res, dfs(dep + 1, num + a[i], cnt, st + (1 << i)));
        }
    }
    return res;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> c;

    a.resize(n); d.resize(1 << n, -1);

    for (int  i = 0; i < n; i ++ ) cin >> a[i];

    cout << dfs(0, 0, 0, 0) << endl;
    return 0;
}