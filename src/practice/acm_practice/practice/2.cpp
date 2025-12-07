#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(1, 100);
    
    map<int, int> mp;
    for (int i = 0; i < 100; i ++ ) {
        mp[dist(rng)] ++ ;
    }

    for (int i = 1; i <= 100; i ++ ) {
        cout << i << ": " << mp[i] << endl;
    }
    return 0;
}