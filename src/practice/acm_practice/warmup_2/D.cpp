#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int yy; 
    while (cin >> yy) {
        string s = to_string(yy);
        int num = accumulate(s.begin(), s.end(), s.size() * -0x30);
        if (pow(int(sqrt(yy)), 2) == yy && pow(int(sqrt(num)), 2) == num) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}