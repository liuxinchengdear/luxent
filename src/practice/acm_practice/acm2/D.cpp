#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1; while (t -- ) {
        int n, m; cin >> n >> m;
        unordered_map<int, int> mp;
        for (int i = 0; i < m; i ++ )
            for (int j = 0, x; j < n; j ++ ) 
                cin >> x, mp[x] ++ ;
        int maxx = 0, num = 0;
        for (auto [k, v] : mp) {
            if (maxx < k) maxx = k, num = v;
        }
        cout << maxx << " " << num << endl;
    }
    cout.flush(); system("pause");
    return 0;
}