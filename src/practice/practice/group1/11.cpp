#include <bits/stdc++.h>
using namespace std;

ostream& operator << (ostream& cout, vector<int> a) {
    for (auto e : a) cout << e << " ";
    return cout;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    vector<int> num(n);

    auto dfs = [&](auto &&self, int de, int st) -> void {
        if (de == n) {cout << num << '\n'; return;}

        for (int i = 0; i < n; i ++ ) {
            if (!(st >> i & 1)) {
                num[de] = i + 1;
                self(self, de + 1, st + (1 << i));
            }
        }
    };

    dfs(dfs, 0, 0);
    return 0;
}