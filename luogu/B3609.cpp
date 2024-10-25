#include <bits/stdc++.h>
using namespace std;
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
const int MAXN = 1e4 + 7;
P *e[MAXN];
int dfn[MAXN], low[MAXN], tot;
stack<int> stk;
bool instk[MAXN];
vector<vector<int>> ans;
int n, m;
bool operator<(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}
void tarjan(int x)
{
    dfn[x] = low[x] = ++tot;
    stk.push(x);
    instk[x] = true;
    for (P *p = e[x]; p; p = p->next)
    {
        if (dfn[p->to])
            if (instk[p->to])
                low[x] = min(low[x], dfn[p->to]);
            else
                ;
        else
        {
            tarjan(p->to);
            low[x] = min(low[x], low[p->to]);
        }
    }
    if (dfn[x] == low[x])
    {
        vector<int> scc;
        while (stk.top() != x)
        {
            instk[stk.top()] = false;
            scc.push_back(stk.top());
            stk.pop();
        }
        instk[stk.top()] = false;
        scc.push_back(stk.top());
        stk.pop();
        sort(scc.begin(), scc.end());
        ans.push_back(scc);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    while (m--)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u] = new P(v, e[u]);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            tarjan(i);
    sort(ans.begin(), ans.end());
    printf("%lu\n", ans.size());
    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < ans[i].size(); j++)
            printf("%d%c", ans[i][j], " \n"[j == ans[i].size() - 1]);
    return 0;
}