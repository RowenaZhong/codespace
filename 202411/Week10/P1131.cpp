#include <bits/stdc++.h>
using namespace std;
class P
{
public:
    int to;
    long long weight;
    P *next;
    P(int t, int w, P *n)
    {
        this->to = t;
        this->weight = w;
        this->next = n;
    }
    ~P()
    {
        if (this->next)
            delete this->next;
        this->next = nullptr;
    }
};
P *e[500007];

long long ans, dep[500007];
bool vis[500007];
int stk_x[500007];
int stk_cnt[500007];
int stk_mode[500007];
int tot = 0;
void dfs(int x)
{
    // cerr << x << endl;
    int cnt = 0;
    vis[x] = true;
    for (P *p = e[x]; p; p = p->next)
    {
        if (vis[p->to])
            continue;
        dfs(p->to);
        if (dep[p->to] + p->weight > dep[x])
        {
            ans += (dep[p->to] + p->weight - dep[x]) * cnt;
            dep[x] = dep[p->to] + p->weight;
        }
        else
            ans += dep[x] - (dep[p->to] + p->weight);
        cnt++;
    }
}
int n, s, a, b, t;
int main()
{
    scanf("%d\n%d\n", &n, &s);
    while (--n)
    {
        scanf("%d %d %d", &a, &b, &t);
        e[a] = new P(b, t, e[a]);
        e[b] = new P(a, t, e[b]);
    }
    dfs(s);
    cout << ans << endl;
    return 0;
}