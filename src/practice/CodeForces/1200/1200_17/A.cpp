#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);;
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<int> a(n * (n - 1) >> 1);

        for (auto &e : a) cin >> e;
        sort(a.begin(), a.end());

        int num = 0;
        for (int i = 0; i < n; i ++ ) {
            if (i == n - 1) {cout << int(1e9) << '\n';continue;}
            cout << a[num] << " ";
            num += n - i - 1;
        }
    }
    return 0;
}