#include <bits/stdc++.h>
using namespace std;

#define int long long

#define lowbit(x) ((x) & -(x))

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int num = n;

        vector<int> bit;
        while (n) {
            auto t = lowbit(n); 
            bit.push_back(t); n -= t;
        }

        if (bit.size() == 1) { cout << "1\n" << num << '\n'; continue; }

        cout << bit.size() + 1 << endl;
        sort(bit.begin(), bit.end(), greater<int>());

        for (int i = 0; i < bit.size(); i ++ ) cout << num - bit[i] << " ";
        cout << num << endl;
    }
    return 0;
}