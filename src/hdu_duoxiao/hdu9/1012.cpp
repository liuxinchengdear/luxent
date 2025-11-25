#include <bits/stdc++.h>
using namespace std;

const int N = 1000010;

using pii = pair<int, int>;

pii ord[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; while (t -- ) {
        int n, m; cin >> n >> m;
        vector<int> res;
        unordered_map<int, int> mp;
        while (m -- ) {
            int x; cin >> x;
            if (!mp.count(x)) res.push_back(x);
            mp[x] ++ ;
        }
        int idx = 0;
        for (auto [k, v] : mp) {
            ord[idx ++ ] = {v, k};
        }
        sort(ord, ord + idx, [](pii x, pii y) {
            return x.first > y.first || x.first == y.first && x.second < y.second;
        });
        int cnt = 0;
        for (int i = 0; i < idx; i ++ ) {
            cnt += res[i] != ord[i].second;
        }
        cout << cnt << endl;
    }
    system("pause");
    return 0;
}