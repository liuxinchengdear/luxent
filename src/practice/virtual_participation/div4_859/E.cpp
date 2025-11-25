#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> a[i];

        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i ++ ) pre[i] = pre[i - 1] + a[i];

        auto check = [&](int l, int r) -> bool {
            cout << "? " << r - l + 1 << " ";
            for (int i = l; i <= r; i ++ ) cout << i << " \n"[i == r];
            cout.flush();
            int ans; cin >> ans;
            return ans == pre[r] - pre[l - 1] + 1;
        };

        auto binary_search = [&](auto &&self, int l, int r) -> void {
            if (l == r) {cout << "! " << r << endl; return;}
            int mid = l + r >> 1;
            if (check(l, mid)) self(self, l, mid);
            else self(self, mid + 1, r);
        };

        binary_search(binary_search, 1, n);
    }
    return 0;
}