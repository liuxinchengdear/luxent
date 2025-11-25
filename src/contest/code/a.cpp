#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

#define x first
#define y second

int n;

struct node
{
    string d, idx, ok;
    int time;
}q[N];

struct node
{
    string d;
    int num, s;
}qq[N];

//map<string, pair<int, int>> mp;
map<pair<string, string>, int> mp;

void solve()
{
    int j = 0;
    cin >> n;
    for (int i = 1; i <= n; i ++ )
    {
        string a, b, c;
        int x;
        cin >> a >> b >> x >> c;
        if (c == "Accepted")
        {
            
        }

        if (x >= 240)
        {
            q[ ++ j].d = a;
            q[j].idx = b;
            q[j].ok = c;
            q[j].time = x;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t -- )
    {
        solve();
    }
    return 0;
}