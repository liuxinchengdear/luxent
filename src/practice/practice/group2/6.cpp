#include <bits/stdc++.h>
using namespace std;

map<string, int> mp{{"BangZhu", 0}, {"FuBangZhu", 1}, {"HuFa", 2}, {"ZhangLao", 3}, {"TangZhu", 4}, {"JingYing", 5}, {"BangZhong", 6}};

struct Node {
    int id;
    string name, post;
    int cont, level;

    bool operator > (const Node &x) const {
        return cont > x.cont || cont == x.cont && id < x.id;
    }

    bool operator < (const Node &x) const {
        return mp[post] < mp[x.post] || mp[post] == mp[x.post] && (level > x.level || level == x.level && id < x.id);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<Node> a(n);
    for (int i = 0; i < n; i ++ ) {
        string name, post; int cont, level; cin >> name >> post >> cont >> level;
        a[i] = {i + 1, name, post, cont, level};
    }

    sort(a.begin(), a.end(), greater<Node>());
    
    auto mat = [](int x) -> string {
        if (x <= 2) return "HuFa";
        else if (x <= 6) return "ZhangLao";
        else if (x <= 13) return "TangZhu";
        else if (x <= 38) return "JingYing";
        else return "BangZhong";
    };
    
    int cnt = 0;
    for (auto &[id, name, post, cont, level] : a) {
        if (post == "BangZhu" || post == "FuBangZhu") continue;
        post = mat( ++ cnt);
    }

    sort(a.begin(), a.end());
    for (auto &[id, name, post, cont, level] : a) {
        cout << name << " " << post << " " << level << endl;
    }
    return 0;
}