#include <bits/stdc++.h>
using namespace std;

using pci = pair<char, int>;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n; 

    vector<pci> a(n);
    for (int i = 0; i < n;  ++ i) {
        char c; int p; cin >> c >> p;

        a[i] = {c, p};
    }
}