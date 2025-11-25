#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    int a[1010] = {0};
    for (int i = 0, x; i < n; i ++ ) cin >> x, a[x] ++ , cout << a[x] << " \n"[i == n - 1];
    cout.flush();
    return 0;
}