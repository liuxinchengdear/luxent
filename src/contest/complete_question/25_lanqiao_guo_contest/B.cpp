#include <bits/stdc++.h>
using namespace std;

// 打表找规律

const int N = 17600, mod = 1e9 + 7;

int pr[N], cnt;
bool st[N];

void sieve(int n) {
    for (int i = 2; i <= n; i ++ ) {
        if (!st[i]) pr[cnt ++ ] = i;
        for (int j = 0; pr[j] <= n / i; j ++ ) {
            st[pr[j] * i] = true;
            if (i % pr[j] == 0) break;
        }
    }
}

int ksm(int a, int n) {
    a %= mod;
    if (!a) return 0;
    if (!n) return 1;
    n %= mod - 1;
    int res = 1;
    while (n) {
        if (n & 1) res = 1LL * res * a % mod;
        a = 1LL * a * a % mod; n >>= 1;
    }
    return res;
}

int bi_se(int x) {
    int l = 0, r = 20;
    while (l < r) {
        int mid = l + r >> 1;
        if (ksm(x, mid) >= N) r = mid;
        else l = mid + 1;
    }
    if (ksm(x, l) > N) l -- ;
    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    sieve(N);

    int res = 1;
    for (int i = 0; i < cnt; i ++ ) 
        res = 1LL * res * bi_se(pr[i]) % mod;
    
    cout << res << endl;
    system("pause");
    return 0;
}