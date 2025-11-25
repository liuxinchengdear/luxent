#include <bits/stdc++.h>
using namespace std;

const int N = 2000010;
int a[N], q[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    int hh = 0, tt = -1;
    for (int i = 0; i < n; i ++ ) {
        cout << (hh <= tt ? a[q[hh]] : 0) << '\n';
        if (hh <= tt && i - q[hh] >= m) hh ++ ;
        cin >> a[i];
        while (hh <= tt && a[q[tt]] >= a[i]) tt -- ;
        q[ ++ tt] = i;
    }
    return 0;
}