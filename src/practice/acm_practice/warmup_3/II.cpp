#include <bits/stdc++.h>
using namespace std;

const int N = 300010;

int son[N][26], cnt[N], idx;

void insert(string s) {
    int p = 0;
    for (auto c : s) {
        auto &t = son[p][c - 0x61];
        if (!t) t = ++ idx;
        p = t;
        cnt[p] ++ ;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 0; i < n; i ++ ) {
        string s; cin >> s;
        reverse(s.begin(), s.end());
        insert(s);
    }

    int res = 0;
    for (int p = 0; p < N; p ++ ) res += cnt[p] > 0;

    cout << res << '\n';

    return 0;
}