// 两个矩形
#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int, int>;
vector<pii> l, r;
vector<int> xx;

int area(int x1, int x2) {
    vector<pii> tmp;
    for (int i = 0; i < 2; i ++ ) {
        auto [a, b] = l[i]; auto [c, d] = r[i];
        if (x1 >= a && x2 <= c) tmp.emplace_back(d, b);
    }

    sort(tmp.begin(), tmp.end());
    if (!tmp.size()) return 0;
    int len = 0, st= tmp[0].first, ed = tmp[0].second;
    // 合并区间
    for (int i = 1; i < tmp.size(); i ++ ) {
        auto [l, r] = tmp[i];
        if (l > ed) len += ed - st, st = l, ed = r;
        else ed = max(ed, r);
    }
    len += ed - st;
    return len * (x2 - x1);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int res = 0;
    int a, b, c, d; cin >> a >> b >> c >> d;
    res = c * d;
    c = a + c; d = b - d;
    xx.push_back(a), xx.push_back(c);
    l.emplace_back(a, b); r.emplace_back(c, d);

    cin >> a >> b >> c >> d;
    res += c * d;
    c = a + c; d = b - d; 
    xx.push_back(a), xx.push_back(c);
    l.emplace_back(a, b); r.emplace_back(c, d);
    sort(xx.begin(), xx.end());
    xx.erase(unique(xx.begin(), xx.end()), xx.end());

    int ans = 0;
    for (int i = 0; i + 1 < xx.size(); i ++ ) {
        ans += area(xx[i], xx[i + 1]);
    }
    cout << res - ans << endl;
    system("pause");
    return 0;
}