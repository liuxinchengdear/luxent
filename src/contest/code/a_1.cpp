 #include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
const int N = 2e5 + 10;
using pii = pair<int, int>;
int n, m, h[N], e[N], ne[N], dist[N], st[N], v, t, idx, w[N];

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

void djkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[t] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> heap;
    heap.push({0, t});

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int v = t.y;

        if (st[v]) continue;
        st[v] = 1;

        for (int i = h[v]; i != - 1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > t.x + w[i])
            {
                dist[j] = t.x + w[i];
                heap.push(dist[j], j);
            }
        }

        for (int i = 1; i <= n; i ++ ) 
        {
            if (i == t) cout << 1 << ' ';
            if (dist[i] == 0x3f3f3f3f) cout << -1 << ' ';
            else if (dist[i] % v == 0) cout << dist[i] / v << ' ';
            else cout << dist[i] / v + 1 << ' ';
        }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m >> v >> t;
    while(m -- )
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }
    dijkstra();
    return 0;
}