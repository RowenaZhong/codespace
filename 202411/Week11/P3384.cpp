#include <bits/stdc++.h>
using namespace std;
namespace IO
{
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
    inline void readl() {}
    template <typename T, typename... Args>
    inline void readl(T &x, Args &...args)
    {
        readi(x);
        readl(args...);
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
    inline void writel() {}
    template <typename T, typename... Args>
    inline void writel(T x, Args... args)
    {
        writei(x);
        putchar(" \n"[sizeof...(args) == 0]);
        writel(args...);
    }
}

const int MAXN = 1e5 + 7;
int n, m, r, modp;
class P
{
public:
    int ver;
    P *next;
    P(int ver, P *next) : ver(ver), next(next) {}
};
int a[MAXN], fa[MAXN], hson[MAXN], size[MAXN], top[MAXN], dep[MAXN];
int dfn[MAXN], dfnTot, rnk[MAXN];
P *e[MAXN];
int sum[MAXN << 2], lazy[MAXN << 2];
void Build(int l, int r, int p)
{
    lazy[p] = 0;
    if (l == r)
    {
        sum[p] = a[rnk[l]] % modp;
        return;
    }
    auto mid = l + r >> 1;
    Build(l, mid, p * 2);
    Build(mid + 1, r, p * 2 + 1);
    sum[p] = (sum[p * 2] + sum[p * 2 + 1]) % modp;
}
void spread(int l, int r, int p)
{
    if (lazy[p])
    {
        int mid = l + r >> 1;
        (lazy[p * 2] += lazy[p]) %= modp;
        (sum[p * 2] += (long long)(mid - l + 1) % modp * lazy[p] % modp) %= modp;
        (lazy[p * 2 + 1] += lazy[p]) %= modp;
        (sum[p * 2 + 1] += (long long)(r - mid) % modp * lazy[p] % modp) %= modp;
        lazy[p] = 0;
    }
}
void Add(int lq, int rq, int x, int l, int r, int p)
{
    if (lq <= l && r <= rq)
    {
        (sum[p] += (long long)(r - l + 1) % modp * x % modp) %= modp;
        (lazy[p] += x) %= modp;
        return;
    }
    spread(l, r, p);
    int mid = l + r >> 1;
    if (lq <= mid)
        Add(lq, rq, x, l, mid, p * 2);
    if (rq > mid)
        Add(lq, rq, x, mid + 1, r, p * 2 + 1);
    sum[p] = (sum[p * 2] + sum[p * 2 + 1]) % modp;
}
int Query(int lq, int rq, int l, int r, int p)
{
    if (lq <= l && r <= rq)
        return sum[p];
    spread(l, r, p);
    int mid = l + r >> 1;
    int ret = 0;
    if (lq <= mid)
        ret += Query(lq, rq, l, mid, p * 2);
    if (rq > mid)
        ret += Query(lq, rq, mid + 1, r, p * 2 + 1);
    return ret % modp;
}
void Dfs1(int u, int f)
{
    size[u] = 1;
    fa[u] = f;
    dep[u] = dep[f] + 1;
    for (P *p = e[u]; p; p = p->next)
        if (p->ver != f)
        {
            Dfs1(p->ver, u);
            size[u] += size[p->ver];
            if (!hson[u] || size[p->ver] > size[hson[u]])
                hson[u] = p->ver;
        }
}
void Dfs2(int u, int t)
{
    top[u] = t;
    dfn[u] = ++dfnTot;
    rnk[dfnTot] = u;
    if (!hson[u])
        return;
    Dfs2(hson[u], t);
    for (P *p = e[u]; p; p = p->next)
        if (p->ver != fa[u] && p->ver != hson[u])
            Dfs2(p->ver, p->ver);
}
void AddPath(int u, int v, int z)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        Add(dfn[top[u]], dfn[u], z, 1, n, 1);
        u = fa[top[u]];
    }
    Add(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]), z, 1, n, 1);
}
int QueryPath(int u, int v)
{
    int ret = 0;
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        ret += Query(dfn[top[u]], dfn[u], 1, n, 1);
        ret %= modp;
        u = fa[top[u]];
    }
    ret += Query(min(dfn[u], dfn[v]), max(dfn[u], dfn[v]), 1, n, 1);
    ret %= modp;
    return ret;
}
void AddSubTree(int u, int z)
{
    Add(dfn[u], dfn[u] + size[u] - 1, z, 1, n, 1);
}

int QuerySubTree(int u)
{
    return Query(dfn[u], dfn[u] + size[u] - 1, 1, n, 1);
}
int main()
{
    IO::readl(n, m, r, modp);
    for (int i = 1; i <= n; i++)
        IO::readi(a[i]);
    for (int i = 1; i <= n - 1; i++)
    {
        int x, y;
        IO::readl(x, y);
        e[x] = new P(y, e[x]);
        e[y] = new P(x, e[y]);
    }
    Dfs1(r, 0);
    Dfs2(r, r);
    Build(1, n, 1);
    while (m--)
    {
        int opt, x, y, z;
        IO::readi(opt);
        switch (opt)
        {
        case 1:
            IO::readl(x, y, z);
            AddPath(x, y, z);
            break;
        case 2:
            IO::readl(x, y);
            IO::writel(QueryPath(x, y));
            break;
        case 3:
            IO::readl(x, z);
            AddSubTree(x, z);
            break;
        case 4:
            IO::readi(x);
            IO::writel(QuerySubTree(x));
            break;
        }
    }
    return 0;
}