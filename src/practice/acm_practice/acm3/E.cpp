#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v(n + 2);
    for (int i = 1; i <= n; i ++ ) cin >> v[i];
    reverse(v.begin(), v.end());
    vector<int> res;
    for (int i = 1; i <= n; i ++ ) {
        if (i == 1) res.push_back(v[i]); 
        else {
            auto p = lower_bound(res.begin(), res.end(), v[i]);
            if (p != res.end()) swap(*p, v[i]);
            else res.push_back(v[i]);
        }
    }
    cout << res.size() << endl;
    return 0;
}