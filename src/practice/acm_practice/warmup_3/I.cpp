#include <bits/stdc++.h>
using namespace std;

using ull = unsigned long long;

const int N = 300010, P = 131;

int n, m;
ull h[N], p[N];

ull get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    string s; cin >> s; s = " " + s;
    
    p[0] = 1;
    for (int i = 1; i <= n; i ++ ) p[i] = p[i - 1] * P, h[i] = h[i - 1] * P + s[i];
    
    while (m -- ) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        cout << (get(a, b) == get(c, d) ? "Yes" : "No") << '\n';
    }
    return 0;
}