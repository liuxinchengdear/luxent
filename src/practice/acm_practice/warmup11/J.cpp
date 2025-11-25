#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string T; cin >> T; int n = T.size(); T = " " + T;

    if (n & 1 || count(T.begin() + 1, T.end(), 0x31) != n >> 1) 
    {cout << "-1\n"; exit(0);}

    stack<int> stk;
    int pos = 1;
    cout << (n >> 1) << endl;
    for (int i = 1; i <= n; i ++ ) {
        auto c = T[i];
        if (!stk.size() || T[stk.top()] == c) {
            stk.push(i); cout << pos << " " << c - 0x2f << endl;
        }
        else {
            stk.pop(); pos ++ ;
        }
    }
    return 0;
}