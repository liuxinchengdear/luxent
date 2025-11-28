#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;

    string s; cin >> s;
    stack<int> stk; 
    vector<int> res;
    for (int i = 0; i < n; i ++ ) { char c = s[i];
        res.push_back(i);
        if (c == '(') stk.push(i);
        else if (c == ')' && stk.size() && s[stk.top()] == '(') {
            while (res.back() != stk.top()) res.pop_back(); res.pop_back();
            stk.pop();
        }
    }

    for (auto t : res) cout << s[t]; cout << endl;

    return 0;
}