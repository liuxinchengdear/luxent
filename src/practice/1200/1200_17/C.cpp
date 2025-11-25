#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, num; cin >> n >> num;

        vector<int> a(n + 2);
        vector<vector<int>> vt(num + 1);
        vector<array<int, 2>> diff(num + 1);

        auto update = [&](int num, int x) -> void {
            auto &[a, b] = diff[num];
            if (a > b) swap(a, b);
            a = max(a, x);
        };

        for (int i = 1; i <= num; i ++ ) vt[i].push_back(0);

        for (int i = 1; i <= n; i ++ ) cin >> a[i], update(a[i], i - 1 - vt[a[i]].back()), vt[a[i]].push_back(i);

        for (int i = 1; i <= num; i ++ ) update(i, n - vt[i].back());

        auto check = [&](int x) -> bool {
            for (int i = 1; i <= num; i ++ ) {
                auto [a, b] = diff[i];
                if (a > b) swap(a, b);
                if (b <= 2 * x + 1 && a <= x) return true;
            }
            return false;
        };

        auto binary_search = [&]() -> int {
            int l = 0, r = n;
            while (l < r) {
                int mid = l + r >> 1;
                if (check(mid)) r = mid;
                else l = mid + 1;
            }
            return l;
        };

        cout << binary_search() << '\n';
    }
    return 0;
}