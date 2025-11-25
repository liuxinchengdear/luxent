#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s; cin >> s;
    auto num = s.back() - 0x30;

    vector<long long> tt;
    for (int i = 1; i < 1 << s.size(); i ++ ) {
        int cnt = 0;
        for (int j = 0; j < s.size(); j ++ ) 
            if (i >> j & 1) cnt ++ ;
        if (cnt == num) {
            int e = i;
            bitset<20> bt(e);
            vector<int> ans;
            int tmp = 0;
            for (int i = s.size() - 1, j = 0; ~ i; i -- ) {
                tmp = (tmp << 3) + (tmp << 1) + s[j ++ ] - 0x30;
                if (bt[i]) ans.push_back(tmp), tmp = 0;
            }
            long long x = ans[0];
            for (int i = 1; i < ans.size(); i ++ ) x = x * ans[i];
            tt.push_back(x);
        }
    }

    sort(tt.begin(), tt.end());
    cout << tt.back() << endl;
    return 0;
}