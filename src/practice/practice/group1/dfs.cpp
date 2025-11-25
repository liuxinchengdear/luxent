#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> num(5);

    auto check = [&]() -> bool {
        int a, b, c;
        a = num[0] * 1000 + num[1] * 100 + num[2] * 10 + num[3];
        b = num[4] * 1000 + num[1] * 100 + num[4] * 10 + num[3];
        c = num[4] * 10000 + num[3] * 1000 + num[2] * 100 + num[0] * 10 + num[3];
        return a + b == c;
    };

    auto print = [&]() -> void {
        for (int i = 0; i < 5; i ++ ) cout << char(0x41 + i) << ": " << num[i] << '\n';
    };

    auto dfs = [&](auto &&self, int de, int st) -> void {
        if (de == 5) {if (check()) print(); return ;}
        for (int i = 0; i < 10; i ++ ) {
            if (st >> i & 1) continue;
            num[de] = i;
            self(self, de + 1, st + (1 << i));
        }
    };

    dfs(dfs, 0, 0);
    return 0;
}