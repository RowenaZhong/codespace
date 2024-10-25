#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7;
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
    ~P()
    {
        if (this->next)
            delete this->next;
    }
};
P *e[MAXN * 2];
int n, m;
bool instk[MAXN * 2];
stack<int> stk;
int dfn[MAXN * 2], low[MAXN * 2], tot;
int scc[MAXN * 2], scctot;
void tarjan(int x)
{
    dfn[x] = low[x] = ++tot;
    instk[x] = true;
    stk.push(x);
    for (P *p = e[x]; p; p = p->next)
    {
        if (dfn[p->to])
            if (instk[p->to])
                low[x] = min(low[x], dfn[p->to]);
            else
                ;
        else
            tarjan(p->to), low[x] = min(low[x], low[p->to]);
    }
    if (dfn[x] == low[x])
    {
        int sccid = ++scctot;
        while (stk.top() != x)
        {
            instk[stk.top()] = false;
            scc[stk.top()] = sccid;
            stk.pop();
        }
        instk[stk.top()] = false;
        scc[stk.top()] = sccid;
        stk.pop();
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    while (m--)
    {
        int u, a, v, b;
        scanf("%d %d %d %d", &u, &a, &v, &b);
        // g[a + n * (va & 1)].push_back(b + n * (vb ^ 1));
        // g[b + n * (vb & 1)].push_back(a + n * (va ^ 1));
        e[u + n * a] = new P(v + (1 - b) * n, e[u + n * a]);
        e[v + n * b] = new P(u + (1 - a) * n, e[v + n * b]);
    }
    for (int i = 1; i <= n * 2; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
    {
        if (scc[i] == scc[i + n])
        {
            puts("IMPOSSIBLE");
            return 0;
        }
    }
    puts("POSSIBLE");
    for (int i = 1; i <= n; i++)
    {
        printf("%d%c", int(scc[i] < scc[i + n]), " \n"[i == n]);
    }
    return 0;
}