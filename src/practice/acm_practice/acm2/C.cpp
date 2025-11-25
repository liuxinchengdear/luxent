#include <bits/stdc++.h>
using namespace std;

int convert(string s) {
    int x = 0;
    if (s.size() == 1) {
        x = isdigit(s[0]) ? s[0] - 0x30 : s[0] - 0x40;
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; while (t -- ) {
        int n; cin >> n;
        vector<int> v, s(20);
        int maxx = 0;
        for (int i = 0; i < n; i ++ ) {
            string str; cin >> str;
            auto t = convert(str);
            v.push_back(t); s[t] ++ ;
            if (s[t] == 2) {
                int num = 0;
                while (s[t]) 
                    s[v.back()] -- , v.pop_back(), num ++ ;
                maxx = max(maxx, num);
            }
        }
        cout << maxx << endl;
    }
    cout.flush(); system("pause");
    return 0;
}