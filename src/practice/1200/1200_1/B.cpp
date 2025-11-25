#include <bits/stdc++.h>
using namespace std;

/*

5 2
11011

11011 -> 01010 -> 01110 -> 01000 -> 01110

7 4
1011011

1011011 -> 0001000 -> 

诀窍在于能否找到减少1的方法

对于一个二进制字符串，寻找左右两端长度为k的字符串能否重叠

*/

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, k; cin >> n >> k;
        string s; cin >> s;

        int cnt = count(s.begin(), s.end(), 0x31);
        
        if (cnt <= k || k << 1 > n) cout << "Alice\n";
        else cout << "Bob\n";
    }
    return 0;
}