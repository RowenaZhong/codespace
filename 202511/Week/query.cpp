// import bless from molly
#include <bits/stdc++.h>
using namespace std;
namespace IO
{
    template <typename T>
    inline void readi(T &x)
    {
        T f = 1;
        int ch;
        x = 0;
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
            putchar('-'), x = -x;
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
    inline void readl() {}
    inline void writel() {}
    template <typename T, typename... Args>
    inline void readl(T &x, Args &...args)
    {
        readi(x);
        readl(args...);
    }
    template <typename T, typename... Args>
    inline void writel(T x, Args... args)
    {
        writei(x);
        if (sizeof...(args) != 0)
            putchar(' ');
        else
            putchar('\n');
        writel(args...);
    }
}
const int MAXN = 5007;
int dep[MAXN];
int fa[MAXN][16];
int n, q;
int head[MAXN], ver[MAXN * 2], nxt[MAXN * 2];
void AddEdge(int u, int v)
{
    static int tot = 1;
    tot++;
    nxt[tot] = head[u];
    head[u] = tot;
    ver[tot] = v;
}
void dfs(int u, int f)
{
    fa[u][0] = f;
    dep[u] = dep[f] + 1;
    for (int d = 1; d < 16; d++)
        fa[u][d] = fa[fa[u][d - 1]][d - 1];
    for (auto e = head[u]; e; e = nxt[e])
    {
        auto v = ver[e];
        if (v != f)
            dfs(v, u);
    }
}
static unsigned mylg(unsigned x)
{
    int ans = 0;
    if (x & 0xffff'0000)
        ans += 16, x >>= 16;
    if (x & 0x0000'ff00)
        ans += 8, x >>= 8;
    if (x & 0x0000'00f0)
        ans += 4, x >>= 4;
    if (x & 0x0000'000c)
        ans += 2, x >>= 2;
    if (x & 0x0000'0002)
        ans += 1, x >>= 1;
    return ans;
}
int lca(int u, int v)
{
    if (dep[u] < dep[v])
        swap(u, v);
    while (dep[u] > dep[v])
        u = fa[u][mylg(dep[u] - dep[v])];
    if (u == v)
        return u;
    for (auto i = 15; i >= 0; i--)
        if (fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

int st[MAXN][15];
void build()
{
    for (int i = 1; i <= n; i++)
        st[i][0] = i;
    for (int l = 1; l < 15; l++)
        for (int i = 1; i + (1 << l) <= n + 1; i++)
            st[i][l] = lca(st[i][l - 1], st[i + (1 << (l - 1))][l - 1]);
}
int query(int l, int r)
{
    int k = mylg(r - l + 1);
    return lca(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
    IO::readi(n);
    if (n > 20000)
    {
        puts("Best wishes for the tomorrow!");
        return 0;
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        IO::readl(u, v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    dfs(1, 0);
    build();
    IO::readi(q);
    while (q--)
    {
        int l, r, k;
        IO::readl(l, r, k);
        int ans = 1;
        for (int i = l; i + k <= r + 1; i++)
            ans = max(ans, dep[query(i, i + k - 1)]);
        IO::writel(ans);
    }
    return 0;
}