#include <bits/stdc++.h>
using namespace std;

#define MULTI int _T; cin >> _T; while (_T -- )

using ll = long long;
using pli = pair<ll, int>;

const int N = 100010;

pli h[N];
int perm[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    MULTI {
        int n, H; cin >> n >> H;
        for (int i = 1; i <= n; i ++ ) {
            int x; cin >> x;
            h[i] = {1LL * x * (H - x), i};
        }
        
        sort(h + 1, h + 1 + n, [](pli x, pli y) {
            return x.first < y.first;
        });
        
        for (int i = 1; i <= n; i ++ ) {
            auto [num, ord] = h[i];
            perm[ord] = i;
        }
        for (int i = 1; i <= n; i ++ ) cout << perm[i] << " \n"[i == n];
    }
    return 0;
}