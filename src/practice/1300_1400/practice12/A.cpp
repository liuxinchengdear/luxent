#include <bits/stdc++.h>
using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<int> st{1, 2, 3, 4, 5};

    for (int i = 0; i < 4; i ++ ) {
        int x; cin >> x; st.erase(x);
    }
    cout << *st.begin() << endl;
    return 0;
}