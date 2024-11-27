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
const int MAXN = 1e4 + 7, MAXM = 1e5 + 7;
int n, m;
tuple<int, int, int> edges[MAXM];
map<pair<int, int>, int> weis;
int head[MAXN], ver[MAXN * 2], wei[MAXN * 2], nxt[MAXN * 2];
void AddEdge(int u, int v, int w)
{
    static int tot = 0;
    ver[++tot] = v, wei[tot] = w, nxt[tot] = head[u], head[u] = tot;
}
int top[MAXN];
int GetTop(int x)
{
    // cerr << boolalpha << (top[x] == x) << endl;
    return top[x] == x ? x : top[x] = GetTop(top[x]);
}
int fa[MAXN], dep[MAXN], faw[MAXN];
void dfs(int u, int f, int w)
{
    fa[u] = f;
    faw[u] = w;
    dep[u] = dep[f] + 1;
    for (int i = head[u]; i; i = nxt[i])
    {
        int v = ver[i];
        if (v == f)
            continue;
        dfs(v, u, wei[i]);
    }
}

int main()
{
    freopen("mintree.in", "r", stdin);
    freopen("mintree.out", "w", stdout);
    IO::readl(n, m);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        IO::readl(u, v, w);
        weis[{min(u, v), max(u, v)}] = w;
        edges[i] = make_tuple(w, u, v);
    }
    sort(edges + 1, edges + m + 1);
    for (int i = 1; i <= n; i++)
        top[i] = i;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        IO::readl(u, v);
        w = weis[{min(u, v), max(u, v)}];
        AddEdge(u, v, w);
        AddEdge(v, u, w);
    }
    dfs(1, 0, 0);
    long long ans = 0;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        tie(w, u, v) = edges[i];
        int tu = GetTop(u), tv = GetTop(v);
        if (tu != tv)
        {
            u = tu, v = tv;
            if (dep[u] < dep[v])
                swap(u, v), swap(tu, tv);
            while (dep[u] > dep[v])
            {
                if (faw[u] > w)
                    ans += faw[u] - w, faw[u] = w;
                top[u] = fa[u];
                u = fa[u];
            }
            while (u != v)
            {
                if (faw[u] > w)
                    ans += faw[u] - w, faw[u] = w;
                if (faw[v] > w)
                    ans += faw[v] - w, faw[v] = w;
                top[u] = fa[u], top[v] = fa[v];
                u = fa[u], v = fa[v];
            }
            top[tu] = top[tv] = u;
        }
    }
    IO::writel(ans);
    return 0;
}
