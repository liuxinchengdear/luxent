#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b) { a ^= b ^= a ^= b; }

int abs(int x) { return (x ^ (x >> 31)) - (x >> 31); }

ostream& operator << (ostream &cout, const vector<int> &x) {
    for (auto e : x) cout << e << " ";
    return cout;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << abs(34) << endl;
    cout << abs(-25) << endl;
    return 0;

    for (int i = 0; i < 32; ++ i) {
        unsigned num = 0u - 1;

        cout << num << " " << (num >> i) << endl;
    }
    return 0;

    unsigned int x = -1;
    for (int i = 0; i < 32; i ++ ) cout << (x >> i) << endl;
    return 0;

    int t = 100;

    vector<int> a(500); iota(a.begin(), a.end(), 0);

    cout << a << endl;
    for (int i = 0; i < t; i ++ ) {
        vector<int> b = a;
        for (int i = 1; i + 1 < 100; ++ i) b[i] = a[i - 1] | a[i] | a[i + 1];
        b[0] = a[0] | a[1]; 
        a = b; cout << a << endl;
    }



    return 0;
}