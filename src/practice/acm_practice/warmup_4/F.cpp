#include <bits/stdc++.h>
using namespace std;

map<string, int> rj;

struct Problem {
    int t; string id;
    Problem(int t, string id) : t(t), id(id) {}

    bool operator < (const Problem &x) const {
        return t + rj[id] * 20 < x.t + rj[x.id] * 20;
    }
};

struct Player {
    int time;
    map<string, int> rj, ac;
    Player(int t) : time(t) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n, a, b; cin >> n >> a >> b;
        int m; cin >> m;
        Player py(0);
        vector<Problem> pms;

        for (int i = 0; i < m; i ++ ) {
            int t; string id, st; cin >> t >> id >> st;
            if (py.ac.count(id)) continue;
            if (t < 240) {
                if (st == "rj") py.rj[id] ++ ;
                else if (st == "ac") py.time += py.rj[id] * 20 + t, py.ac[id] ++ ;
            }
            else pms.emplace_back(t, id);
        }

        rj = py.rj;
        sort(pms.begin(), pms.end());

        auto check = [&]() -> bool {
            return py.ac.size() > a || py.ac.size() == a && py.time < b;
        };

        if (check()) {cout << "0\n"; continue;}

        int cnt = 0;
        bool flag = false;
        for (auto [t, id] : pms) {
            if (py.ac.count(id)) continue;
            py.time += py.rj[id] * 20 + t, py.ac[id] ++ ;
            cnt ++ ;
            if (check()) {cout << cnt << '\n'; flag = true; break;}
        }
        if (!flag) cout << "-1\n";
    }
    return 0;
}