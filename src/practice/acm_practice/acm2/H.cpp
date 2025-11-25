#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    for (int i = 1; i <= n; i ++ ) cin >> a[i];
    for (int i = 1; i <= n; i ++ ) cin >> b[i];

    unordered_map<int, int> mp;
    int i = 1, j = 1;
    int cnt = 0;
    while (j <= n) {
        if (mp[a[i]]) i ++ ;
        else if (a[i] == b[j]) i ++ , j ++ ;
        else mp[b[j]] = 1, j ++ , cnt ++ ;
    }
    cout << cnt << endl;
    // system("pause");
    return 0;
}