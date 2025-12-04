#include <bits/stdc++.h>
using namespace std;

string s = "123456789";
vector<int> path(10);

bool check() {
    auto n1 = path[0] * 1000 + path[1] * 100 + path[2] * 10 + path[3];
    auto n2 = path[4] * 10000 + path[5] * 1000 + path[6] * 100 + path[7] * 10 + path[8];
    return n1 * 3 == n2;
}

string print() {
    string s;
    for (int i = 0; i < 9; i ++ ) {
        if (i == 4) s += '/';
        s += path[i] + 0x30;
    }
    return s;
}

vector<string> res;

void dfs(int dep, int st) {
    if (dep == 9) { 
        if (check()) res.push_back(print());
        return;
    }
    for (int i = 0; i < 9; i ++ ) {
        if (st >> i & 1) continue;
        path[dep] = i + 1;
        dfs(dep + 1, st + (1 << i));
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    dfs(0, 0);

    sort(res.begin(), res.end(), greater<string>());

    for (auto e : res) cout << e << endl;
    return 0;
}