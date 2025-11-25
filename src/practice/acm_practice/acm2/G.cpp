#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    vector<int> v(101);
    for (int i = 0; i < n; i ++ ) {
        int x; cin >> x;
        v[x] ++ ;
    }
    int res = 0; int tmp = 0;
    for (int i = 100; i ; i -- ) 
        if (v[i] && m)
             res += m > v[i] ? m -= v[i], v[i] * i : (tmp = m, m = 0, tmp * i);
    cout << res << endl;
    system("pause");
    return 0;
}