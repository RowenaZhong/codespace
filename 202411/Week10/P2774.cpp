#include <bits/stdc++.h>
using namespace std;

int row, col;
const int MAX_DIM = 107;
int a[MAX_DIM][MAX_DIM], sum;
inline int GetPosIdx(int r, int c)
{
    return r * MAX_DIM + c;
}
const int s = MAX_DIM * MAX_DIM, t = MAX_DIM * MAX_DIM + 1;
const int MAXN = 12007, MAXM = 60007, INF = INT_MAX;
int head[MAXN], now[MAXN], ver[MAXM], nxt[MAXM], cap[MAXM];
int dis[MAXN];
int tot = 1;
inline void Add(int u, int v, int w)
{
    tot++, nxt[tot] = head[u], head[u] = tot, ver[tot] = v, cap[tot] = w;
}
inline void AddEdge(int u, int v, int w)
{
    Add(u, v, w);
    Add(v, u, 0);
}
bool bfs()
{
    memset(dis, 0x00, sizeof(dis));
    memcpy(now, head, sizeof(head));
    queue<int> q;
    q.push(s), dis[s] = 1;
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (auto e = head[u]; e; e = nxt[e]) {
            auto v = ver[e];
            if (cap[e] && !dis[v]) {
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
    auto rest = flow;
    auto e = now[u];
    for (; e && rest; e = nxt[e]) {
        auto v = ver[e];
        if (cap[e] && dis[v] == dis[u] + 1) {
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
    scanf("%d %d", &row, &col);
    for (int r = 1; r <= row; r++)
        for (int c = 1; c <= col; c++)
            scanf("%d", &a[r][c]), sum += a[r][c];
    for (int r = 1; r <= row; r++) {
        for (int c = 1; c <= col; c++) {
            if ((r + c) % 2 == 0) {
                AddEdge(GetPosIdx(r, c), t, a[r][c]);
                continue;
            }
            AddEdge(s, GetPosIdx(r, c), a[r][c]);
            if (r != row)
                AddEdge(GetPosIdx(r, c), GetPosIdx(r + 1, c), INF);
            if (c != col)
                AddEdge(GetPosIdx(r, c), GetPosIdx(r, c + 1), INF);
            if (r != 1)
                AddEdge(GetPosIdx(r, c), GetPosIdx(r - 1, c), INF);
            if (c != 1)
                AddEdge(GetPosIdx(r, c), GetPosIdx(r, c - 1), INF);
        }
    }
    auto flow = int();
    while (bfs())
        while (flow = dinic(s, sum))
            sum -= flow;
    printf("%d\n", sum);
    return 0;
}
