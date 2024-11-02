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
stack<int> stk;
bool instk[MAXN];
namespace SCC
{
    int cnt;
    int idx[MAXN];
    int deg[MAXN];
    P *e[MAXN];
    int a[MAXN];
    int dp[MAXN];
}
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
        SCC::cnt++;
        while (stk.top() != x)
        {
            instk[stk.top()] = false;
            SCC::idx[stk.top()] = SCC::cnt;
            SCC::a[SCC::cnt] += a[stk.top()];
            stk.pop();
        }
        instk[stk.top()] = false;
        SCC::idx[stk.top()] = SCC::cnt;
        SCC::a[SCC::cnt] += a[stk.top()];
        stk.pop();
    }
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
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
        for (P *p = e[i]; p; p = p->next)
            if (SCC::idx[i] != SCC::idx[p->to])
                SCC::e[SCC::idx[i]] = new P(SCC::idx[p->to], SCC::e[SCC::idx[i]]),
                SCC::deg[SCC::idx[p->to]]++;
    queue<int> que;
    for (int i = 1; i <= SCC::cnt; i++)
        if (SCC::deg[i] == 0)
            que.push(i);
    int Ans = 0;
    while (que.size())
    {
        int x = que.front();
        que.pop();
        SCC::dp[x] += SCC::a[x];
        Ans = max(Ans, SCC::dp[x]);
        for (P *p = SCC::e[x]; p; p = p->next)
        {
            SCC::dp[p->to] = max(SCC::dp[p->to], SCC::dp[x]);
            if (--SCC::deg[p->to] == 0)
                que.push(p->to);
        }
    }
    printf("%d\n", Ans);
    return 0;
}