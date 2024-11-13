#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void readi(T &x)
{
    T f = 1;
    x = 0;
    int ch;
    while (ch = getchar(), !feof(stdin) && !isdigit(ch) && ch != '-')
        ;
    if (ch == '-')
        f = -f, ch = getchar();
    while (!feof(stdin) && isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
template <typename T>
inline void writei(T x)
{
    if (x == 0)
    {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p)
    {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}

const int MAXN = 407, MAXM = 4.4e4 + 7, MAXR = 200;
int head[MAXN], now[MAXN];
int nxt[MAXM], ver[MAXM], cap[MAXM];
int dis[MAXN], tot = 1;
int n, s, t;
inline void AddSingleEdge(int u, int v, int w)
{
    ++tot, nxt[tot] = head[u], head[u] = tot, ver[tot] = v, cap[tot] = w;
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
            if (cap[e] && !dis[v])
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
    for (e = now[u]; e && rest; e = nxt[e])
    {
        auto v = ver[e];
        if (dis[v] == dis[u] + 1 && cap[e])
        {
            auto subFlow = dinic(v, min(cap[e], rest));
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
inline int GetRow(int r)
{
    return r;
}
inline int GetCol(int c)
{
    return MAXR + c;
}
int main()
{
    int T;
    readi(T);
    s = MAXR * 2 + 1, t = MAXR * 2 + 2;
    while (T--)
    {
        memset(head, 0x00, sizeof(head));
        tot = 1;
        readi(n);
        for (int i = 1; i <= n; i++)
            AddEdge(s, GetRow(i), 1), AddEdge(GetCol(i), t, 1);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int t;
                readi(t);
                if (t)
                    AddEdge(GetRow(i), GetCol(j), 1);
            }
        }
        int flow, maxFlow = 0;
        while (bfs())
        {
            while (flow = dinic(s, INT_MAX))
                maxFlow += flow;
        }
        puts((maxFlow == n) ? "Yes" : "No");
    }

    return 0;
}