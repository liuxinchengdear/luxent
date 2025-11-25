#include <bits/stdc++.h>
using namespace std;;

#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int _T; cin >> _T; while (_T -- ) {
        int n; cin >> n;
        vector<vector<int>> A(n + 1, vector<int>(n + 1)), C(n + 1, vector<int>(n + 1));
        vector<vector<double>> K(4, vector<double>(4));

        for (int i = 1; i <= n; i ++ ) 
            for (int j = 1; j <= n; j ++ ) cin >> A[i][j];
        int sum = 0;
        for (int i = 1; i <= 3; i ++ ) 
            for (int j = 1; j <= 3; j ++ ) cin >> K[i][j], sum += K[i][j];
        
        for (int i = 1; i <= 3; i ++ )
            for (int j = 1; j <= 3; j ++ ) K[i][j] /= sum;
        for (int t = 0; t < 20; t ++ ) {
            for (int i = 1; i <= n; i ++ ) {
                for (int j = 1; j <= n; j ++ ) {
                    for (int ii = 1; ii <= min(n - i + 1, 3LL); ii ++ ) {
                        for (int jj = 1; jj <= min(n - j + 1, 3LL); jj ++ ) {
                            C[i][j] += A[i + ii - 1][j + jj - 1] * K[ii][jj];
                        }
                    }
                }
            }
            if (A == C) {
                for (int i = 1; i <= n; i ++ ) {
                    for (int j = 1; j <= n; j ++ ) cout << C[i][j] << " \n"[j == n];
                }
                break;
            }
            A = C; C = vector<vector<int>>(n + 1, vector<int>(n + 1));
        }
    }
    return 0;
}