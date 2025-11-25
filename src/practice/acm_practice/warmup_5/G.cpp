#include <bits/stdc++.h>
using namespace std;

/*

a + c * x = b

c * x = b - a (有c的取值范围)

*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int a, b; cin >> a >> b;
        
        int num = abs(a - b);
        if (!num) {
            if (a == 1) cout << "-1 -1\n";
            else cout << 2 << " " << a << '\n'; continue;
        }

        if (num == 1) cout << "-1 -1\n";
        else {
            int p = 0;
            for (int i = 2; i <= num / i; i ++ ) {
                if (num % i == 0) {p = i; break;}
            }
            if (!p) p = num;
            cout << p << " " << num << '\n';
        }
    }
    return 0;
}