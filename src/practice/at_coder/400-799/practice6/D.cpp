#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, S; cin >> n >> S;
    vector<int> a(n + 1);
    int sum = 0;
    for (int i = 1; i <= n; i ++ ) cin >> a[i], sum += a[i];

    unordered_set<int> st;
    vector<int> pre(n + 1), suff(n + 2);
    for (int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + a[i];
    for (int i = n; i; i -- ) suff[i] = suff[i + 1] + a[i], st.insert(suff[i]);
    st.insert(0);
    
    for (int i = 0; i <= n; i ++ ) {
        int tmp = S - pre[i];
        tmp %= sum;
        if (st.count(tmp)) {cout << "Yes\n"; return 0;}
    }
    cout << "No\n";
    return 0;
}