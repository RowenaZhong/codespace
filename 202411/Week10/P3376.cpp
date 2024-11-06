#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
const int MAXN = 201, MAXM = 5007;
int head[MAXN], nxt[MAXM << 1], to[MAXM << 1], now[MAXN], dis[MAXN], cnt = 1;
long long wei[MAXM << 1];
void add(int x, int y, int w)
{
    cnt++, nxt[cnt] = head[x], to[cnt] = y, wei[cnt] = w, head[x] = cnt;
    cnt++, nxt[cnt] = head[y], to[cnt] = x, wei[cnt] = 0, head[y] = cnt;
}
bool bfs()
{
    queue<int> q;
    memset(dis, 0x00, sizeof(dis));
    dis[s] = 1;
    q.push(s);
    now[s] = head[s];
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; i; i = nxt[i])
        {
            int v = to[i];
            if (wei[i] && !dis[v])
            {
                dis[v] = dis[u] + 1;
                now[v] = head[v];
                if (v == t)
                    return true;
                q.push(v);
            }
        }
    }
    return false;
}
long long dinic(int u, long long flow)
{
    if (u == t)
        return flow;
    long long rest = flow, k;
    for (; now[u] && rest; now[u] = nxt[now[u]])
    {
        int v = to[now[u]];
        if (wei[now[u]] && dis[v] == dis[u] + 1)
        {
            k = dinic(v, min(wei[now[u]], rest));
            if (!k)
                dis[v] = 0;
            rest -= k;
            wei[now[u]] -= k;
            wei[now[u] ^ 1] += k;
        }
    }
    return flow - rest;
}
int main()
{
    scanf("%d %d %d %d", &n, &m, &s, &t);
    while (m--)
    {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        add(x, y, w);
    }
    long long flow = 0, ans = 0;
    while (bfs())
        while (flow = dinic(s, LONG_LONG_MAX))
            ans += flow;
    printf("%lld\n", ans);
    return 0;
}
