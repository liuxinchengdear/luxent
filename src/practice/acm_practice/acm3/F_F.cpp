#include <bits/stdc++.h>
using namespace std;

#define int long long

string s; 
int cnt, res = 0;

void dfs(int de, int c, int num, int pro) {
    if (de == s.size()) {
        if (c == cnt) res = max(res, pro * num);
        return ;
    }
    num = (num << 3) + (num << 1) + s[de] - 0x30;

    if (c < cnt) dfs(de + 1, c + 1, 0, pro * num);
    dfs(de + 1, c, num, pro);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> s; cnt = s.back() - 0x30; cnt -- ;

    dfs(0, 0, 0, 1);

    cout << res << endl;
    return 0;
}