#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    vector<int> p(n + 1), s(n + 1);
    iota(p.begin(), p.end(), 0);

    fill(s.begin() + 1, s.end(), 1);

    auto getfa = [&](auto &&self, int x) -> int {
        return x == p[x] ? p[x] : p[x] = self(self, p[x]);
    };

    int res = 0;
    for (int i = m; i -- ; ) {
        int a, b; cin >> a >> b;
        a = getfa(getfa, a), b = getfa(getfa, b);
        if (a == b) {res ++ ; continue;}
        p[a] = b; s[b] += s[a];
    }
    
    int cnt = 0;
    for (int i = 1; i <= n; i ++ ) cnt += p[i] == i;
    cout << res + cnt - 1 << '\n';
    return 0;
}