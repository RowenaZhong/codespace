#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7, NON = 0;
int n;
int fa[MAXN], dep[MAXN], size[MAXN];
int head[MAXN], nxt[MAXN], ver[MAXN], tot; // childs
int top[MAXN], hson[MAXN], dfn[MAXN], rnk[MAXN], dfntot;
const int INSTALLED = 1, UNINSTALLED = 2;
inline void AddEdge(int u, int v)
{
    tot++, nxt[tot] = head[u], ver[tot] = v, head[u] = tot;
}
void Dfs1(int u)
{
    dep[u] = dep[fa[u]] + 1;
    size[u] = 1;
    for (auto e = head[u]; e; e = nxt[e])
    {
        auto v = ver[e];
        Dfs1(v);
        size[u] += size[v];
        if (!hson[u] || size[v] > size[hson[u]])
            hson[u] = v;
    }
}
void Dfs2(int u, int t)
{
    dfn[u] = ++dfntot;
    rnk[dfntot] = u;
    top[u] = t;
    if (hson[u])
        Dfs2(hson[u], t);
    for (auto e = head[u]; e; e = nxt[e])
    {
        auto v = ver[e];
        if (v != hson[u])
            Dfs2(v, v);
    }
}

int sum[MAXN << 2], lazy[MAXN << 2];
void spread(int l, int r, int p)
{
    if (lazy[p])
    {
        auto mid = l + r >> 1;
        if (lazy[p] == INSTALLED)
            sum[p * 2] = mid - l + 1,
                    sum[p * 2 + 1] += r - mid;
        else
            sum[p * 2] = sum[p * 2 + 1] = 0;
        lazy[p * 2] = lazy[p];
        lazy[p * 2 + 1] = lazy[p];
        lazy[p] = 0;
    }
}
void Add(int l, int r, int p, int lq, int rq, int x)
{
    if (lq <= l && r <= rq)
    {
        if (x == INSTALLED)
            sum[p] = r - l + 1;
        else
            sum[p] = 0;
        lazy[p] = x;
        return;
    }
    spread(l, r, p);
    auto mid = l + r >> 1;
    if (lq <= mid)
        Add(l, mid, p * 2, lq, rq, x);
    if (rq > mid)
        Add(mid + 1, r, p * 2 + 1, lq, rq, x);
    sum[p] = sum[p * 2] + sum[p * 2 + 1];
}
int Query(int l, int r, int p, int lq, int rq)
{
    if (lq <= l && r <= rq)
        return sum[p];
    spread(l, r, p);
    auto mid = l + r >> 1;
    auto ret = int();
    if (lq <= mid)
        ret += Query(l, mid, p * 2, lq, rq);
    if (rq > mid)
        ret += Query(mid + 1, r, p * 2 + 1, lq, rq);
    return ret;
}
int QueryList(int u)
{
    auto ret = int();
    while (u != NON)
    {
        ret += Query(1, n, 1, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    return ret;
}
void InstallList(int u)
{
    while (u != NON)
    {
        Add(1, n, 1, dfn[top[u]], dfn[u], INSTALLED);
        u = fa[top[u]];
    }
}
int QuerySubTree(int u)
{
    return Query(1, n, 1, dfn[u], dfn[u] + size[u] - 1);
}
void RemoveSubTree(int u)
{
    Add(1, n, 1, dfn[u], dfn[u] + size[u] - 1, UNINSTALLED);
}
int main()
{
    freopen("stdin", "r", stdin);
    scanf("%d", &n);
    for (int v = 2; v <= n; v++)
    {
        int u;
        scanf("%d", &u);
        u++;
        AddEdge(u, v);
        fa[v] = u;
    }
    Dfs1(1);
    Dfs2(1, 1);
    int q;
    scanf("%d", &q);
    while (q--)
    {
        char str[15];
        int u;
        scanf("%s %d", str, &u);
        u++;
        if (str[0] == 'i')
        {
            printf("%d\n", dep[u] - QueryList(u));
            InstallList(u);
        }
        else
        {
            printf("%d\n", QuerySubTree(u));
            RemoveSubTree(u);
        }
    }
    return 0;
}