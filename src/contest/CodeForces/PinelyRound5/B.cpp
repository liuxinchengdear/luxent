#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<string> g(n);
        for (auto &e : g) cin >> e;

        if (n == 1 || n == 2) { cout << "YES\n"; continue; }

        set<int> tol, left, right;
        for (int i = 0; i < n; i ++ ) {
            for (int j = 0; j < n; j ++ ) {
                if (g[i][j] == '#') tol.insert(i * n + j), left.insert(i - j), right.insert(i + j);
            }
        }
        auto t = *tol.begin();
        set<int> t1, t2;
        if ((t + 1) % n == 0) t1 = {t, t - 1 + n, t + n};
        else if (t % n == 0) t2 = {t, t + 1, t + n, t + 1 + n};
        else {
            t1 = {t - 1, t, t - 1 + n, t + n}, t2 = {t, t + 1, t + n, t + 1 + n};
        }

        if (tol.size() <= 4) {
            bool f1 = true, f2 = true;
            for (auto e : tol) if (!t1.count(e)) f1 = false;
            for (auto e : tol) if (!t2.count(e)) f2 = false;
            bool fg = f1 || f2;
            if (fg) { cout << "YES\n"; continue; }
        }

        if (left.size() == 1 || right.size() == 1) { cout << "YES\n"; continue; }
        if (left.size() == 2 && abs(*left.begin() - *next(left.begin())) == 1) { cout << "YES\n"; continue; } 
        if (right.size() == 2 && abs(*right.begin() - *next(right.begin())) == 1) { cout << "YES\n"; continue; } 
    
        cout << "NO\n";
    }
    return 0;
}