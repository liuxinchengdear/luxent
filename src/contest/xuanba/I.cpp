#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m; cin >> n >> m;

    string s1, s2; cin >> s1 >> s2;

    vector<int> t1(30), t2(30);

    for (int i = 0; i < n; i ++ ) t1[s1[i] - 0x60] ++ ;
    for (int i = 0; i < m; i ++ ) t2[s2[i] - 0x60] ++ ;

    int num1 = pow(t1['b' - 0x60], 2LL) + 2 * pow(t1['l' - 0x60], 2LL) + 3 * pow(t1['m' - 0x60], 2LL) + 4 * pow(t1['o' - 0x60], 2LL) + 5 * pow(t1['s' - 0x60], 2LL);
    int num2 = pow(t2['b' - 0x60], 2LL) + 2 * pow(t2['l' - 0x60], 2LL) + 3 * pow(t2['m' - 0x60], 2LL) + 4 * pow(t2['o' - 0x60], 2LL) + 5 * pow(t2['s' - 0x60], 2LL);
    
    int a1 = t1['b' - 0x60]; 
    a1 = min(a1, t1['l' - 0x60]);
    a1 = min(a1, t1['m' - 0x60]);
    a1 = min(a1, t1['o' - 0x60] / 2);
    a1 = min(a1, t1['s' - 0x60] / 2);
    a1 *= 5;

    int a2 = t2['b' - 0x60]; 
    a2 = min(a2, t2['l' - 0x60]);
    a2 = min(a2, t2['m' - 0x60]);
    a2 = min(a2, t2['o' - 0x60] / 2);
    a2 = min(a2, t2['s' - 0x60] / 2);
    a2 *= 5;

    cout << num1 + a1 << " " << num2 + a2 << endl;
    return 0;
}