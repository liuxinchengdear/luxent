#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        bitset<30> bit(n);
        vector<int> s0, s1; bool fg = false;
        for (int i = 0; i < 30; i ++ ) {
            if (!fg && bit[i] == 1) fg = true;
            if (!fg) continue;
            int j = i;
            while (i + 1 < 30 && bit[i + 1] == bit[i]) ++ i;
            if (bit[i] == 0) s0.push_back(i - j + 1);
            else s1.push_back(i - j + 1);
        }

    }
    return 0;
}