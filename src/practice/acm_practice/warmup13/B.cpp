#include <bits/stdc++.h>
using namespace std;;

#define double long double

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<double> a(5), b(8);
    vector<double> ji_tap{1, 1, 0.8, 0.5, 0}, ji_b{5, 5, 5, 4, 3, 2.5, 2, 0};
    vector<double> award{1, 0.75, 0.5, 0.4, 0.4, 0.4, 0.3, 0};
    double n1 = 0, n2 = 0;
    double num1 = 0, num2 = 0;
    for (int i = 0; i < 5; i ++ ) cin >> a[i], n1 += ji_tap[i] * a[i], num1 += a[i];
    for (int i = 0; i < 8; i ++ ) cin >> b[i], n1 += ji_b[i] * b[i], n2 += award[i] * b[i], num2 += b[i];

    double res = (n1 / (num1 + 5 * num2) * 100 + n2 / num2);

    int ans = res * 10000;

    cout << fixed << setprecision(4) << (ans * 1.0 / 10000) << endl;

    return 0;
}