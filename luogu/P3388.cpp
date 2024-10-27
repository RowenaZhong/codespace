#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 7;
int a[MAXN];
class P
{
public:
    int to;
    P *next;
    P(int t, P *n)
    {
        this->to = t;
        this->next = n;
    }
};
P *e[MAXN];
int n, m, dfn[MAXN], low[MAXN], tot;
set<int> Ans;
void tarjan(int x, int root)
{
    dfn[x] = low[x] = ++tot;
    int child = 0;
    for (P *p = e[x]; p; p = p->next)
    {
        if (dfn[p->to])
            low[x] = min(low[x], dfn[p->to]);
        else
        {
            tarjan(p->to, root);
            low[x] = min(low[x], low[p->to]);
            if (low[p->to] >= dfn[x] && x != root)
                Ans.insert(x);
            if (x == root)
                child++;
        }
    }
    if (child >= 2)
        Ans.insert(x);
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    while (m--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u] = new P(v, e[u]);
        e[v] = new P(u, e[v]);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i, i);
    printf("%ld\n", Ans.size());
    for (const auto &ans : Ans)
        printf("%d ", ans);
    return 0;
}