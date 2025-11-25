#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; while (t -- ) {
        int n, m;
        cin >> n >> m;
        using pii = pair<int, int>;
        vector<pair<int, pii>> v;
        for (int i = 0; i < n; i ++ ) {
            int a, b, c; cin >> a >> b >> c;
            v.push_back({c, {a, b}});
        }
        sort(v.begin(), v.end(), [](pair<int, pii> x, pair<int, pii> y) {
            return x.first > y.first || x.first == y.first && x.second < y.second;
        });
        v.resize(m);
        for (auto [c, e] : v) {
            auto [a, b] = e;
            cout << a << " " << b << " " << c << '\n';
        } 
    }
    cout.flush(); system("pause");
    return 0;
}