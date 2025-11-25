#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    string s; cin >> s; s = " " + s;

    vector<int> A(n + 1), C(n + 2);

    vector<int> num;
    for (int i = 1; i <= n; i ++ ) A[i] = s[i] == 'A' ? A[i - 1] + 1 : 0;
    for (int i = n; i; i -- ) C[i] = s[i] == 'C' ? C[i + 1] + 1 : 0;

    for (int i = 1; i <= n; i ++ ) {
        if (s[i] == 'A' && s.substr(i, 3) == "ABC") 
            num.push_back(min(A[i], C[i + 2])); 
    }
    sort(num.begin(), num.end());

    int i = 0, j = num.size() - 1;
    int cnt = 1;
    while (i <= j) {
        if (cnt & 1) {
            num[j] -- ;
            if (!num[j]) j -- ;
            else if (num[j] == 1) j -- , cnt ++ ;
        }
        else i ++ ;
        cnt ++ ;
    }

    cout << cnt - 1 << endl;

    return 0;
}