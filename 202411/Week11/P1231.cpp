#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e4 + 7, MAXM = 8e5 + 7, MAX_SUB_N = 1e4;
int head[MAXN], now[MAXN], dis[MAXN];
int ver[MAXM], nxt[MAXM], cap[MAXM];
int tot = 1, s = 4 * MAX_SUB_N + 1, t = 4 * MAX_SUB_N + 2;
inline int GetTestIdx(int idx)
{
    return idx;
}
inline int GetBookInIdx(int idx)
{
    return MAX_SUB_N + idx;
}
inline int GetBookOutIdx(int idx)
{
    return MAX_SUB_N * 2 + idx;
}
inline int GetAnsIdx(int idx)
{
    return MAX_SUB_N * 3 + idx;
}
inline void AddSingleEdge(int u, int v, int w)
{
    tot++, nxt[tot] = head[u], head[u] = tot, ver[tot] = v, cap[tot] = w;
}
inline void AddEdge(int u, int v, int w)
{
    AddSingleEdge(u, v, w);
    AddSingleEdge(v, u, 0);
}
bool bfs()
{
    memcpy(now, head, sizeof(head));
    memset(dis, 0x00, sizeof(dis));
    queue<int> que;
    que.push(s), dis[s] = 1;
    while (que.size())
    {
        auto u = que.front();
        que.pop();
        for (auto e = head[u]; e; e = nxt[e])
        {
            auto v = ver[e];
            if (!dis[v] && cap[e])
            {
                dis[v] = dis[u] + 1;
                if (v == t)
                    return true;
                que.push(v);
            }
        }
    }
    return false;
}
int dinic(int u, int flow)
{
    if (u == t)
        return flow;
    auto rest = flow;
    auto e = now[u];
    for (; e && rest; e = nxt[e])
    {
        auto v = ver[e];
        if (dis[v] == dis[u] + 1 && cap[e])
        {
            auto subFlow = dinic(v, min(rest, cap[e]));
            rest -= subFlow;
            cap[e] -= subFlow;
            cap[e ^ 1] += subFlow;
            if (subFlow == 0)
                dis[v] = 0;
        }
    }
    now[u] = e;
    return flow - rest;
}
int N1, N2, N3;
int M1, M2;
int main()
{
    scanf("%d %d %d", &N1, &N2, &N3);
    for (int i = 1; i <= N1; i++)
        AddEdge(GetBookInIdx(i), GetBookOutIdx(i), 1);
    for (int i = 1; i <= N2; i++)
        AddEdge(s, GetTestIdx(i), 1);
    for (int i = 1; i <= N3; i++)
        AddEdge(GetAnsIdx(i), t, 1);
    scanf("%d", &M1);
    for (int i = 1; i <= M1; i++)
    {
        int b, t;
        scanf("%d %d", &b, &t);
        AddEdge(GetTestIdx(t), GetBookInIdx(b), 1);
    }
    scanf("%d", &M2);
    for (int i = 1; i <= M2; i++)
    {
        int b, a;
        scanf("%d %d", &b, &a);
        AddEdge(GetBookOutIdx(b), GetAnsIdx(a), 1);
    }
    int maxFlow = 0, flow;
    while (bfs())
        while (flow = dinic(s, INT_MAX))
            maxFlow += flow;
    printf("%d\n", maxFlow);
    return 0;
}