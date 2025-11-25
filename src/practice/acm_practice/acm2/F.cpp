#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    vector<int> v;
    for (int i = 0, x; i < n; i ++ ) {
        cin >> x;
        if (!i) v.push_back(x);
        else {
            auto t = lower_bound(v.begin(), v.end(), x + 1);
            if (t == v.end()) v.push_back(x);
            else * t = x;
        }
    }
    cout << v.size() << endl;
    // cout.flush(); system("pause");
    return 0;
}