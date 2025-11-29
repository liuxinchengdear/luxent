#include <bits/stdc++.h>
using namespace std;

#define MULTI int _T; cin >> _T; while (_T -- )
#define is_leap(year) ((year) % 4 == 0 && (year) % 100 || (year) % 400 == 0)

const int N = 366, M = N * 51 + 10;

int k, st, ed;
int rest[52][N + 1], mm[N + 1], dd[N + 1];
vector<int> mon{-1, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // 全部看成闰年

using pii = pair<int, int>;

pii find(int day) {
    return {mm[day], dd[day]};
}

void init() {
    int cnt = 0;
    for (int i = 1; i <= 12; i ++ ) {
        for (int j = 1; j <= mon[i]; j ++ )
            mm[ ++ cnt] = i, dd[cnt] = j;
    }

    int week = 1; // 2024-12-31的日期
    for (int i = 2025; i <= 2075; i ++ ) {
        for (int j = 1; j <= N; j ++ ) {
            auto cnt = (i - 2025) * N + j;
            auto [m, d] = find(j);
            if (!is_leap(i) && m == 2 && d == 29) rest[i - 2025][j] ++ ;
            else {
                week = (week + 1) % 7;
                if (week == 5 || week == 6) rest[i - 2025][j] ++ ;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    MULTI {
        cin >> k >> st >> ed;

        vector<int> ans;
        for (int j = 1; j <= N; j ++ ) {
            int num = 0;
            for (int i = st; i <= ed; i ++ ) num += rest[i - 2025][j];
            ans.push_back(num);
        }

        sort(ans.begin(), ans.end(), greater<int>());

        int sum = (ed - st + 1) * k;
        for (int i = 0; i < k; i ++ ) sum -= ans[i];

        cout << sum << '\n';
    }
    cout.flush(); system("pause");
    return 0;
}