#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b; cin >> a >> b;

    auto isP = [](int x) -> bool {
        if (x == 2) return true;
        if (x % 2 == 0) return false;
        for (int i = 3; i <= x / i; i += 2) {
            if (x % i == 0) return false;
        }
        return true;
    };

    vector<int> res;
    for (int i = 1; i <= 9999; i ++ ) {
        string ori = to_string(i), tmp = ori;
        if (ori.front() % 2 == 0) continue;
        reverse(tmp.begin(), tmp.end());
        int odd = stoi(ori + tmp.substr(1)), even = stoi(ori + tmp);
        if (odd >= a && odd <= b && isP(odd)) res.push_back(odd);
        if (even >= a && even <= b && isP(even)) res.push_back(even);
    }

    sort(res.begin(), res.end());
    for (auto e : res) cout << e << '\n';
    return 0;
}