#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e4 + 7, MAXM = MAXN * 2;
int head[MAXN], ver[MAXM], nxt[MAXM], tot;
int hson[MAXN], top[MAXN], size[MAXN], dep[MAXN];
int dfn[MAXN], rnk[MAXN], fa[MAXN], dfntot;
int n, w[MAXN];
class Node
{
public:
    int max, sum;
    const Node operator+(const Node &b)
    {
        Node ret;
        ret.max = ::max(this->max, b.max);
        ret.sum = this->sum + b.sum;
        return ret;
    }
    Node &operator+=(const Node &b)
    {
        this->max = ::max(this->max, b.max);
        this->sum = this->sum + b.sum;
        return *this;
    }
    Node()
    {
        this->max = this->sum = 0;
    }
};
Node nodes[MAXN << 2];
#define maxn(i) nodes[i].max
#define sum(i) nodes[i].sum
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
        Dfs1(v, u);
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
void Build(int l, int r, int p)
{
    if (l == r)
    {
        sum(p) = maxn(p) = w[rnk[l]];
        return;
    }
    auto mid = l + r >> 1;
    Build(l, mid, p * 2);
    Build(mid + 1, r, p * 2 + 1);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
    maxn(p) = max(maxn(p * 2), maxn(p * 2 + 1));
}
void Set(int l, int r, int p, int x, int a)
{
    if (l == r)
    {
        sum(p) = maxn(p) = a;
        return;
    }
    auto mid = l + r >> 1;
    if (x <= mid)
        Set(l, mid, p * 2, x, a);
    else
        Set(mid + 1, r, p * 2 + 1, x, a);
    sum(p) = sum(p * 2) + sum(p * 2 + 1);
    maxn(p) = max(maxn(p * 2), maxn(p * 2 + 1));
}
Node Query(int l, int r, int p, int lq, int rq)
{
    if (lq <= l && r <= rq)
        return nodes[p];
    auto mid = l + r >> 1;
    auto ret = Node();
    if (lq <= mid)
        ret += Query(l, mid, p * 2, lq, rq);
    if (rq > mid)
        ret += Query(mid + 1, r, p * 2 + 1, lq, rq);
    return ret;
}
Node QueryPath(int u, int v)
{
    auto ret = Node();
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]])
            swap(u, v);
        ret += Query(1, n, 1, dfn[top[u]], dfn[u]);
        u = fa[top[u]];
    }
    if (dep[v] > dep[u])
        swap(u, v);
    ret += Query(1, n, 1, dfn[v], dfn[u]);
    return ret;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        AddEdge(u, v);
    }
    for (int i = 1; i <= n; i++)
        scanf("%d", w + i);
    Dfs1(1, 0);
    Dfs2(1, 1);
    Build(1, n, 1);
    int q;
    scanf("%d", &q);
    char str[10];
    int u, v;
    while (q--)
    {
        scanf("%s %d %d", str, &u, &v);
        if (strcmp(str, "CHANGE") == 0)
            Set(1, n, 1, dfn[u], v);
        else if (strcmp(str, "QMAX") == 0)
            printf("%d\n", QueryPath(u, v).max);
        else
            printf("%d\n", QueryPath(u, v).sum);
    }
    return 0;
}