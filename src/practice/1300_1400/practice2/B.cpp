#include <bits/stdc++.h>
using namespace std;

template <typename T>
ostream& operator << (ostream& cout, const initializer_list<T> &X) {
    for (auto e : X) cout << e << " ";
    return cout;
}

ostream& operator << (ostream& cout, const vector<int>& X) {
    for (auto e : X) cout << e << " ";
    return cout;
}

template <typename... Args>
void o(const Args&... args) {
    ((cout << args << " "), ...); cout << endl;
}

void print(initializer_list<int> list) {
    for (auto e : list) cout << e << " "; cout << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        string s; cin >> s;

        int cnt = count(s.begin(), s.end(), 0x61) * 2ll - n;

        int cur = 0, ans = n;
        unordered_map<int, int> lst; lst[cur] = -1;
        for (int i = 0; i < n; i ++ ) { auto &&c = s[i];
            cur += c == 0x61 ? 1 : -1;
            lst[cur] = i;
            if (lst.count(cur - cnt)) {
                ans = min(ans, i - lst[cur - cnt]);
            }
        }
        cout << (ans == n ? -1 : ans) << endl;
    }
    return  0;
}