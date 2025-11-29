#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<string> s(n + 1);
        for (int i = 1; i <= n; i ++ ) cin >> s[i], s[i] = " " + s[i];

        int op = 0;
        for (int i = 1; i <= n >> 1; i ++ ) {
            for (int j = 1; j <= n >> 1; j ++ ) {
                vector<char> tmp{s[i][j], s[j][n - i + 1], s[n - j + 1][i], s[n - i + 1][n - j + 1]};
                auto c = *max_element(tmp.begin(), tmp.end());
                for (auto e : tmp) op += c - e;
            }
        }
        cout << op << '\n';
    }
    return  0;
}