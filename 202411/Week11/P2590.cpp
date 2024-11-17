#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 7, MAXM = MAXN * 2;
int head[MAXN], ver[MAXM], nxt[MAXM], tot;
int hson[MAXN], top[MAXN], size[MAXN], dep[MAXN];
int dfn[MAXN], rnk[MAXN], fa[MAXN], dfntot;

int n, w[MAXN];
inline void AddEdge(int u, int v)
{
    ++tot, nxt[tot] = head[u], head[u] = tot, ver[tot] = v;
    ++tot, nxt[tot] = head[v], head[v] = tot, ver[tot] = u;
}
void Dfs1(int u, int father)
{
    fa[u] = father;
    dep[u] = dep[father] + 1;
    size[u] = 1;
    for (auto e = head[u]; e; e = nxt[e])
    {
        auto v = ver[e];
        if (v == father)
            continue;
        Dfs(v, u);
        size[u] += size[v];
        if (size[v] > size[hson[u]])
            hson[u] = v;
    }
}
void Dfs2(int u, int t)
{
    dfntot++;
    dfn[u] = dfntot;
    rnk[dfntot] = u;
    top[u] = t;
    if (!hson[u])
        return;
    Dfs2(hson[u], t);
    for (auto e = head[u]; e; e = nxt[e])
    {
        auto v = ver[e];
        if (v == hson[u] || v == fa[u])
            continue;
        Dfs2(v, v);
    }
}
void build()
{
}
int main()
{
    return 0;
}