#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

using pii = pair<int, int>;

struct Comp {
    // greater
    bool operator () (pii x, pii y) {
        return x.second > y.second;
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<pii> a(n + 1);
        vector<int> dist(n + 1); dist[1] = 1; dist[n] = -1;
        priority_queue<pii, vector<pii>, Comp> heap;

        for (int i = 1; i <= n; i ++ ) {
            int x; cin >> x;
            a[i] = {i, x};
            if (i != 1) heap.push(a[i]);
        }

        queue<int> q; q.push(1);
        while (q.size()) {
            auto size = q.size(); 
            while (size -- ) {
                auto [id, num] = a[q.front()]; q.pop();
                int mx = num * 2;
                while (heap.size()) {
                    auto [tid, tnum] = heap.top();
                    if (tnum > mx) break;
                    dist[tid] = dist[id] + 1;
                    q.push(tid); heap.pop();
                }
            }
        }
        cout << dist[n] << endl;
    }
    return 0;
}