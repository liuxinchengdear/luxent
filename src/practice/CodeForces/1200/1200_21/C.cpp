#include <bits/stdc++.h>
using namespace std;

#define lowbit(x) ((x) & -(x))

using pii = pair<int, int>;

const int N = 200010;

int tr[N << 2];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        int sum = 0;
        for (int i = 1; i <= n; i ++ ) {
            int x; cin >> x;
            while (x && x % 2 == 0) sum ++ , x /= 2;
        }
    }
    return 0;
}