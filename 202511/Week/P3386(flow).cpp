#include <bits/stdc++.h>
using namespace std;
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
const int MAXN = 1024, MAXM = 5e4 + 7 + MAXN * 2;
int tot = 1, head[MAXN], to[MAXM << 1], nxt[MAXM << 1], cap[MAXM << 1], dis[MAXN], now[MAXN];
void AddSingleEdge(int u, int v, int c)
{
    tot++;
    auto t = head[u];
    head[u] = tot, to[tot] = v, cap[tot] = c, nxt[tot] = t;
}
int S, T;
int n, m;
bool bfs()
{
    memset(dis, 0x00, sizeof(dis));
    memcpy(now, head, sizeof(head));
    queue<int> que;
    dis[S] = 1;
    que.push(S);
    while (!que.empty())
    {
        auto u = que.front();
        que.pop();
        for (auto e = head[u]; e; e = nxt[e])
        {
            auto v = to[e];
            if (!dis[v] && cap[e])
            {
                dis[v] = dis[u] + 1;
                que.push(v);
                if (v == T)
                    return true;
            }
        }
    }
    return false;
}
int dinic(int u, int flow)
{
    if (u == T)
        return flow;
    auto rest = flow;
    auto e = now[u];
    for (; e && rest; e = nxt[e])
    {
        auto v = to[e];
        if (dis[v] == dis[u] + 1 && cap[e])
        {
            auto sub = dinic(v, min(rest, cap[e]));
            cap[e] -= sub;
            cap[e ^ 1] += sub;
            rest -= sub;
            if (sub == 0)
                dis[v] = 0;
        }
    }
    now[u] = e;
    return flow - rest;
}
int main()
{
    int e;
    cin >> n >> m >> e;
    S = n + m + 1, T = n + m + 2;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        v += n;
        AddSingleEdge(u, v, 1);
        AddSingleEdge(v, u, 0);
    }
    for (int i = 1; i <= n; i++)
    {
        AddSingleEdge(S, i, 1);
        AddSingleEdge(i, S, 0);
    }
    for (int i = n + 1; i <= n + m; i++)
    {
        AddSingleEdge(i, T, 1);
        AddSingleEdge(T, i, 0);
    }
    int flow = 0, sub_flow;
    while (bfs())
        while (sub_flow = dinic(S, INT_MAX))
            flow += sub_flow;
    cout << flow << endl;
    return 0;
}