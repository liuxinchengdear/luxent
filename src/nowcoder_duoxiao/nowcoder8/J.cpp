#include <bits/stdc++.h>
using namespace std;

#define MULTI int _T; cin >> _T; while (_T -- )

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    MULTI {
        string s1, s2; cin >> s1 >> s2;
        int n1 = s1.size(), n2 = s2.size();
        s1 = " " + s1; s2 = " " + s2;

        map<int, int> mp; 
        for (int i = 1; i <= n1; i ++ ) {
            if (s1[i] == 0x31) {
                for (int j = 1; j <= n2; j ++ ) {
                    if (s2[j] == 0x31) 
                        mp[n1 - i + n2 - j] ++ ;
                }
            }
        }

        for (auto [k, num] : mp) {
            
        }
    }
}