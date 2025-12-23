#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    auto fac = [&](int x) -> int {
        if (x == 2 || x == 1) return x;
        vector<int> p;
        if (x % 2 == 0) {
            p.push_back(2);
            while (x % 2 == 0) x /= 2;
        }
        for (int i = 3; i <= x / i; i += 2) {
            if (x % i == 0) {
                p.push_back(i);
                while (x % i == 0) x /= i;
            }
        }
        if (x > 1) p.push_back(x);

        int sum = 1;
        for (auto e : p) sum *= e;
        return sum;
    };

    cout << fac(n) << endl;
    return 0;
}