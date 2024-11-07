#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6007, MAXM = 1e4 + 7;
const int MAXCOL = 50;
int n, k, s, t;
int head[MAXN], nxt[MAXM << 1], ver[MAXM << 1], cap[MAXM << 1], cost[MAXM << 1],
    tot = 1;
int vis[MAXN], incf[MAXN], dis[MAXN], pre[MAXN];
int A[51][51];
inline int GetIndex(int x, int y, int IsOut)
{
    return x * MAXCOL + y + IsOut * MAXCOL * MAXCOL;
}
inline void Add(int u, int v, int w, int c)
{
    tot++, nxt[tot] = head[u], ver[tot] = v, cap[tot] = w, cost[tot] = c,
           head[u] = tot;
}
inline void AddEdge(int u, int v, int w, int c)
{
    Add(u, v, w, c);
    Add(v, u, 0, -c);
}
void spfa()
{
    memset(vis, 0x00, sizeof vis);
    memset(dis, 0xcf, sizeof dis);
    queue<int> q;
    q.push(s);
    vis[s] = true, dis[s] = 0;
    while (q.size()) {
        auto u = q.front();
        vis[u] = false;
        q.pop();
        for (auto e = head[u]; e; e = nxt[e]) {
            auto v = ver[e];
            if (cap[e] && dis[v] < dis[u] + cost[e]) {
                dis[v] = dis[u] + cost[e];
                incf[v] = min(incf[u], cap[e]);
                pre[v] = e;
                if (!vis[v])
                    vis[v] = true, q.push(v);
            }
        }
    }
    return;
}
int max_sum;
void Update()
{
    auto u = t;
    while (u != s) {
        auto e = pre[u];
        cap[e] -= incf[t];
        cap[e ^ 1] += incf[t];
        u = ver[e ^ 1];
    }
    incf[s] -= incf[t];
    max_sum += incf[t] * dis[t];
}
#define DOT_IN false
#define DOT_OUT true
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &A[i][j]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i < n)
                AddEdge(GetIndex(i, j, DOT_OUT), GetIndex(i + 1, j, DOT_IN), k,
                        0);
            if (j < n)
                AddEdge(GetIndex(i, j, DOT_OUT), GetIndex(i, j + 1, DOT_IN), k,
                        0);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            AddEdge(GetIndex(i, j, DOT_IN), GetIndex(i, j, DOT_OUT), 1,
                    A[i][j]);
            AddEdge(GetIndex(i, j, DOT_IN), GetIndex(i, j, DOT_OUT), k - 1, 0);
        }
    }
    s = GetIndex(1, 1, DOT_IN);
    t = GetIndex(n, n, DOT_OUT);
    incf[s] = k;
    do
        spfa(), Update();
    while (incf[s]);
    printf("%d\n", max_sum);
    return 0;
}
