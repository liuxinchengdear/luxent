#include <bits/stdc++.h>
using namespace std;

int fast_pow(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * a;
        a *= a; n >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int k, x; cin >> k >> x;
        for (int i = 0; i < k; i ++ ) {
            if (x != -1 && (x - 1) % 3 == 0) {
                auto t = x / 3;
                if (t & 1) x = t;
                else x <<= 1;
            } 
            else x <<= 1;
        }
        cout << x << '\n';
    }
    return 0;
}