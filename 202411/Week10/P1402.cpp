#include <bits/stdc++.h>
using namespace std;
const int MAXN = 107, INF = INT_MAX, SIZE_N = 5 * MAXN,
          SIZE_M = 2 * (MAXN * 3 + MAXN * MAXN * 2);
int n, p, q;
inline int GetRoomIndex(int idx)
{
    return idx;
}
inline int GetDishIndex(int idx)
{
    return idx + MAXN;
}
inline int GetInPersonIndex(int idx)
{
    return idx + MAXN * 2;
}
inline int GetOutPersonIndex(int idx)
{
    return idx + MAXN * 3;
}
const int s = MAXN * 4 + 1, t = MAXN * 4 + 2;
int head[SIZE_N], now[SIZE_N], ver[SIZE_M], nxt[SIZE_M], cap[SIZE_M],
    dis[SIZE_N], tot = 1;
inline void Add(int u, int v, int w)
{
    tot++, ver[tot] = v, nxt[tot] = head[u], cap[tot] = w, head[u] = tot;
}
inline void AddEdge(int u, int v)
{
    Add(u, v, 1);
    Add(v, u, 0);
}
bool bfs()
{
    memset(dis, 0x00, sizeof(dis));
    memcpy(now, head, sizeof(head));
    queue<int> q;
    dis[s] = 1;
    q.push(s);
    while (q.size())
    {
        const auto u = q.front();
        q.pop();
        for (auto e = head[u]; e; e = nxt[e])
        {
            const auto v = ver[e];
            if (cap[e] && !dis[v])
            {
                dis[v] = dis[u] + 1;
                q.push(v);
                if (v == t)
                    return true;
            }
        }
    }
    return false;
}
int dinic(int u, int flow)
{
    if (u == t)
        return flow;
    auto rest = flow, e = now[u];
    for (; e && rest; e = nxt[e])
    {
        auto v = ver[e];
        if (cap[e] && dis[v] == dis[u] + 1)
        {
            auto subFlow = dinic(v, min(cap[e], rest));
            if (!subFlow)
                dis[v] = 0;
            cap[e] -= subFlow;
            cap[e ^ 1] += subFlow;
            rest -= subFlow;
        }
    }
    now[u] = e;
    return flow - rest;
}
int main()
{
    scanf("%d %d %d", &n, &p, &q);
    for (int i = 1; i <= n; i++)
        AddEdge(GetInPersonIndex(i), GetOutPersonIndex(i));
    for (int i = 1; i <= p; i++)
        AddEdge(s, GetRoomIndex(i));
    for (int i = 1; i <= q; i++)
        AddEdge(GetDishIndex(i), t);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            int t;
            scanf("%d", &t);
            if (t)
                AddEdge(GetRoomIndex(j), GetInPersonIndex(i));
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= q; j++)
        {
            int t;
            scanf("%d", &t);
            if (t)
                AddEdge(GetOutPersonIndex(i), GetDishIndex(j));
        }
    }
    int maxFlow = 0, flow;
    while (bfs())
        while (flow = dinic(s, INF))
            maxFlow += flow;
    printf("%d\n", maxFlow);
    return 0;
}
