#include <bits/stdc++.h>
using namespace std;

ostream& operator << (ostream &os, const vector<int> &x) {
    for (auto e : x) os << e << " ";
    return os;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k; cin >> n >> k;

    if (n % 2 == 0) {
        cout << (n >> 1) << " ";
        for (int i = n; i ; i -- ) {
            vector<int> tmp(k, i);
            if (i == n >> 1) tmp.pop_back();
            cout << tmp;
        }
        exit(0);
    }

    vector<int> tmp(k, n + 1 >> 1); cout << tmp;
    if (n == 1) return 0;
    cout << (n >> 1) << " ";
    for (int i = n; i ; i -- ) {
        if (i == n + 1 >> 1) continue;
        tmp = vector<int>(k, i);
        if (i == n >> 1) tmp.pop_back();
        cout << tmp;
    }
    return 0;
}