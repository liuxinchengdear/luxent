#include <bits/stdc++.h>
using namespace std;

const int N = 100010;

int stk[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t; while (t -- ) {
        string s; cin >> s;
        // 模拟栈
        int tt = -1;
        bool flag = true;
        for (int i = 0; i < s.size(); i ++ ) {
            auto ch = s[i];
            if (ch == '(') stk[ ++ tt] = 1;
            else {
                if (tt == -1) { flag = false; break; }
                else auto t = stk[tt -- ];
            }
        }
        cout << (flag && tt == -1 ? "True\n" : "False\n");
    }
    // cout.flush(); system("pause");
    return 0;
}