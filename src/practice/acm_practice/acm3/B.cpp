#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<pair<int, int>> aa;
    for (int i = 0; i < n; i ++ ) {
        int a, b; cin >> a >> b; aa.emplace_back(a, b);
    }

    sort(aa.begin(), aa.end(), [](pair<int, int> x, pair<int, int> y) {
        return x.second < y.second;
    });

    int ed = aa[0].second;
    int cnt = 1;
    for (int i = 1; i < aa.size(); i ++ ) {
        auto [l, r] = aa[i];
        if (l > ed) ed = r, cnt ++ ; 
    }
    cout << cnt << endl;
    system("pause");
    return 0;
}