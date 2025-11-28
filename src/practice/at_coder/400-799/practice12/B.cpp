#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i ++ ) cin >> a[i];

    sort(a.begin(), a.end());

    if (a.front() == 1 || a.back() == n) { cout << "-1\n"; exit(0); }
    
    a.push_back(n);
    vector<int> num;
    for (auto e : a) {
        if (!num.size()) { num.resize(e); iota(num.begin(), num.end(), 1); continue; }
        int t = num.back(); num.pop_back(); 
        num.push_back(num.size() + 2); num.push_back(t);
        for (int i = num.size() + 1; i <= e; i ++ ) num.push_back(i);
    }

    for (auto e : num) cout << e << " "; cout << endl;;
    return 0;
}