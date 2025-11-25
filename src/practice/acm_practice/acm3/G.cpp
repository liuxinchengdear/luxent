#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

#define int long long

int a[N];

bool check(int n) {
    string s = to_string(n);
    for (int i = 0; i < s.size(); i ++ ) {
        auto num = s[i] - 0x30;
        if (num != 2 && num != 3 && num != 5)
            return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    {
        int cnt = 0;
        for (int i = 2; cnt <= 1000; i ++ ) {
            if (check(i)) a[ ++ cnt] = i;
        }
    }

    int n; 
    while (cin >> n) {
        cout << a[n] << endl;
    }
    return 0;
}