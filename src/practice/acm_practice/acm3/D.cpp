#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isprime(int x) {
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    for (int i = 3; i <= x / i; i += 2) 
        if (x % i == 0) return false;
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    vector<int> res;
    for (int i = 1; i < 1 << s.size(); i ++ ) {
        int num = 0;
        for (int j = 0; j < s.size(); j ++ ) 
            if (i >> j & 1) num = (num << 3) + (num << 1) + s[j] - 0x30;
        if (isprime(num)) res.push_back(num);
    }
    sort(res.begin(), res.end());
    if (res.size()) cout << res.back() << endl;
    else cout << "No result." << endl;
    return 0;
}