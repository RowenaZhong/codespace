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
typedef long long ll;
const int MAXN = 1000007;

int n, m, k, aa, bb, fat[MAXN], cnt;
int fir[MAXN], to[MAXN], nex[MAXN], ecnt;
int son[MAXN], dep[MAXN], sz[MAXN], fa[MAXN], top[MAXN], val[MAXN];

struct node
{
    int x, y, z;
} a[MAXN];

void add_edge(int u, int v)
{
    nex[++ecnt] = fir[u];
    fir[u] = ecnt;
    to[ecnt] = v;
}

int cmp(const node &a, const node &b)
{
    return a.z < b.z;
}

int father(int x)
{
    if (x != fat[x])
        fat[x] = father(fat[x]);
    return fat[x];
}

void dfs1(int x, int f, int deep)
{
    dep[x] = deep;
    fa[x] = f;
    sz[x] = 1;
    int maxson = -1;
    for (int e = fir[x]; e; e = nex[e])
    {
        int v = to[e];
        if (v == f)
            continue;
        dfs1(v, x, deep + 1);
        sz[x] += sz[v];
        if (sz[v] > maxson)
            maxson = sz[v], son[x] = v;
    }
}

void dfs2(int x, int topf)
{
    top[x] = topf;
    if (!son[x])
        return;
    dfs2(son[x], topf);
    for (int e = fir[x]; e; e = nex[e])
    {
        int v = to[e];
        if (v == fa[x] || v == son[x])
            continue;
        dfs2(v, v);
    }
}
void kruskal()
{
    sort(a + 1, a + 1 + m, cmp);
    for (int i = 1; i <= m; i++)
    {
        if (father(a[i].x) != father(a[i].y))
        {
            int fa = father(a[i].x), fb = father(a[i].y);
            val[++cnt] = a[i].z;
            fat[cnt] = fat[fa] = fat[fb] = cnt;
            add_edge(fa, cnt);
            add_edge(cnt, fa);
            add_edge(fb, cnt);
            add_edge(cnt, fb);
        }
    }
}

int lca(int x, int y)
{
    int f1 = top[x], f2 = top[y];
    while (f1 != f2)
    {
        if (dep[f1] < dep[f2])
            swap(f1, f2), swap(x, y);
        x = fa[f1];
        f1 = top[x];
    }
    return dep[x] < dep[y] ? x : y;
}

int main()
{
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    readi(n), readi(m), readi(k);
    cnt = n;
    for (int i = 1; i <= m; i++)
        readi(a[i].x), readi(a[i].y), readi(a[i].z);
    for (int i = 1; i <= n; i++)
        fat[i] = i;
    kruskal();
    dfs1(cnt, 0, 1);
    dfs2(cnt, cnt);
    while (k--)
    {
        readi(aa), readi(bb);
        int x = val[lca(aa, bb)];
        writei(x ? x : -1);
        putchar('\n');
    }
    return 0;
}