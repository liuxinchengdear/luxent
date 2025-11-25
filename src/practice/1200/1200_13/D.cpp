#include <bits/stdc++.h>
using namespace std;

#define int long long

// 用结构体来维护

struct Node {
    int num[3];
    int pos[3];
    Node() {memset(num, 0, sizeof num); memset(pos, -1, sizeof pos);}
    void update(int idx, int x) {
        if (!num[0]) {num[0] = x; pos[0] = idx; return;}
        if (x >= num[0]) {num[2] = num[1]; num[1] = num[0]; num[0] = x; pos[2] = pos[1]; pos[1] = pos[0]; pos[0] = idx;}
        else {
            if (x >= num[1]) {num[2] = num[1]; num[1] = x; pos[2] = pos[1]; pos[1] = idx;}
            else {
                if (x >= num[2]) {num[2] = x; pos[2] = idx;}
            }
        }
    }
};

ostream& operator << (ostream& cout, int x[]) {
    cout << x[0] << " " << x[1] << " " << x[2];
    return cout;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;

        Node node[3];
        for (int j = 0; j < 3; j ++ ) {
            for (int i = 0, x; i < n; i ++ ) {
                cin >> x;
                node[j].update(i, x);
            }
        }

        int res = 0;

        auto dfs = [&](auto &&self, int de, int num, int st, vector<int>& idx) {
            if (de == 3) {res = max(res, num); return;}

            for (int i = 0; i < 3; i ++ ) {
                if (!(st >> i & 1)) {
                    auto [a, p] = node[i];
                    for (int j = 0; j < 3; j ++ ) {
                        if (find(idx.begin(), idx.end(), p[j]) == idx.end()) {
                            idx.push_back(p[j]);
                            self(self, de + 1, num + a[j], st + (1 << i), idx);
                            idx.pop_back();
                            break;
                        }
                    }
                }
            }
        };

        vector<int> tmp;
        dfs(dfs, 0, 0, 0, tmp);

        cout << res << '\n';
    }
    return 0;
}