#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 200010;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, r, c; cin >> n >> r >> c;
    string s; cin >> s;

    int edge = N * 2 + 1, org = N * edge + N;

    unordered_map<int, int> op{{'N', edge}, {'S', -edge}, {'W', 1}, {'E', -1}};
    unordered_map<int, int> g; g[org] = 1;
    int EP = (r + N) * edge + c + N;
    
    for (auto c : s) {
        org += op[c]; g[org] = 1;
        EP += op[c];
        cout << g[EP];
    }
    cout << endl;
    
    return 0;
}
    