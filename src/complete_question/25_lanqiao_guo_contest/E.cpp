/* 

模拟输入

a b c

// 最多变化次数？ 最少变化次数？
// 选择数量较少的珠子， 插空插入另一种珠子
// 则变化次数 ＝ max > min ? 2 * min : 2 * min - 1
// 最少变化次数为 min ? 1 : 0

// 接下来模拟怎么选择使得字典序最小

输入 4 3 5 // 我觉得你是真的成长了！加油！！

_Q_Q_Q_ -> LQLQLQ + 添加余下的L放到开头
answer = LLQLQLQ

若输入 3 4 5

_L_L_L_ -> 由于 c = 5 < 2 * 3， answer = LQLQLQQ

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b, c; cin >> a >> b >> c;

    int mi = min(a, b) ? 1 : 0;
    int ma = max(a, b) > min(a, b) ? 2 * min(a, b) : 2 * min(a, b) - 1;

    if (c < mi || c > ma) cout << "-1\n";
    else {
        string s, t;
        for (int i = 0; i <= c; i ++ ) t += i & 1 ? 'Q' : 'L';
        if (c != ma || a >= b) {
            s = string(a - (c + 2 >> 1), 'L') + t;
            string q_r = string(b - (c + 1 >> 1), 'Q');
            if (t.back() == 'Q') s += q_r;
            else s.insert(s.size() - 1, q_r);
        }
        else s = t.substr(1) + "Q" + string(b - (c + 2 >> 1), 'Q');
        cout << s << '\n';
    }
    cout.flush(); system("pause");
    return 0;
}