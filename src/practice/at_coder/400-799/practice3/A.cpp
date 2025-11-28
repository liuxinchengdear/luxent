#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int A, N; cin >> A >> N;
    string ns = to_string(N); int n = ns.size();

    auto check = [](int num, int A) -> bool {
        string s;
        while (num) s += num % A + 0x30, num /= A;
        for (int i = 0, j = s.size() - 1; i < j; i ++ , j -- ) {
            if (s[i] != s[j]) return false;
        }
        return true;
    };

    auto tran_str = [](int num, int nature) -> string {
        string s, t = to_string(num);
        if (nature & 1) {
            string tmp = t;
            reverse(tmp.begin(), tmp.end());
            tmp = (tmp.size() > 1 ? tmp.substr(1) : "");
            s = t + tmp;
        }
        else {
            string tmp = t;
            reverse(tmp.begin(), tmp.end());
            s = t + tmp;
        }
        return s;
    };

    int odd, even;
    string tmp = ns.substr(0, n + 1 >> 1), ntmp = string(n >> 1, 0x39);
    tmp = tmp == "" ? "0" : tmp;
    ntmp = ntmp == "" ? "0" : ntmp;

    if (n & 1) odd = stoll(tmp), even = stoll(ntmp);
    else odd = stoll(ntmp), even = stoll(tmp);
    
    if (stoll(tran_str(odd, 1)) > N) odd -- ;
    if (stoll(tran_str(even, 0)) > N) even -- ;

    int res = 0;
    for (int i = 1; i <= odd; i ++ ) {
        string s = tran_str(i, 1);
        int num = stoll(s);

        if (check(num, A)) res += num;
    }

    for (int i = 1; i <= even; i ++ ) {
        string s = tran_str(i, 0);
        int num = stoll(s);

        if (check(num, A)) res += num;
    }
    cout << res << endl;
    return 0;
}