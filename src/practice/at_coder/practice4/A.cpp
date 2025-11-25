#include <bits/stdc++.h>
using namespace std;

#define int long long

#define endl '\n'
const int N=2e5+5;
int vish[N],visw[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int h, w, n; cin >> h >> w >> n;
    vector<unordered_set<int>> row(h + 1), col(w + 1);
    vector<pair<int, int>> poi(n + 1);
    for (int i = 0; i < n; i ++ ) {
        int x, y; cin >> x >> y;
        row[x].insert(i + 1); col[y].insert(i + 1);
        poi[i + 1] = {x, y};
    }
    int q; cin >> q;
    while (q -- ) {
        int op, x; cin >> op >> x;
        if (op == 1) {
            if(vish[x]==1){
                cout<<"0\n";continue;
            }
            cout << row[x].size() << endl;
            for (auto e : row[x]) col[poi[e].second].erase(e);
            vish[x]=1;
        }
        else {
            if(visw[x]==1){
                cout<<"0\n";continue;
            }
            cout << col[x].size() << endl;
            for (auto e : col[x]) row[poi[e].first].erase(e);
            visw[x]=1;
        }
    }
    return 0;
}