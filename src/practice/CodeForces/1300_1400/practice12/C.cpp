#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        
        map<int, int> mp;
        for (int i = 0; i < n; i ++ ) {
            int x; cin >> x;
            mp[x] ++ ;
        }

        vector<int> num;
        for (auto [k, v] : mp) {
            while (v >= 2) num.push_back(k), v -= 2;
        }

        if (num.size() < 4) { cout << "NO\n"; continue; }

        n = num.size();
        vector<int> a{num[0], num[1], num[n - 2], num[n - 1]};

        int res = -1;
        vector<int> tmp;
        do {
            int S = abs(a[0] - a[2]) * abs(a[1] - a[3]);
            if (res < S) res = S, tmp = a;
        } while (next_permutation(a.begin(), a.end()));

        if (res == -1) cout << "NO\n";
        else {
            cout << "YEs\n";
            cout << tmp[0] << " " << tmp[1] << " ";
            cout << tmp[0] << " " << tmp[3] << " ";
            cout << tmp[2] << " " << tmp[3] << " ";
            cout << tmp[2] << " " << tmp[1] << '\n';
        }
    }
    return 0;
}