#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &e : a) cin >> e;
    for (auto &e : b) cin >> e;

    unordered_set<int> st;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] == b[j]) st.insert(i), j ++ ;
        i ++ ; 
    }
    if (j < m) {cout << "No\n"; return 0;}
    i = n - 1, j = m - 1;
    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) st.insert(i), j -- ;
        i -- ;
    }
    cout << (st.size() > m ? "Yes\n" : "No\n");
    return 0;
}