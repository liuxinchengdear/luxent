#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n), c(n);
        for (int i = 0; i < n; i ++ ) cin >> a[i];
        for (int i = 0; i < n; i ++ ) cin >> c[i];

        vector<int> lis;
        auto binary_search = [&](int l, int r, int x) -> int {
            while (l < r) {
                int mid = l + r >> 1;
                if (a[lis[mid]] >= x) r = mid;
                else l = mid + 1;
            }
            return l;
        };

        for (int i = 0; i < n; i ++ ) {
            if (!lis.size()) {lis.push_back(i); continue;}
            auto t = binary_search(0, lis.size(), a[i]);
            if (t == lis.size()) lis.push_back(i);
            else swap(lis[t], i);
        }
        
    }
}