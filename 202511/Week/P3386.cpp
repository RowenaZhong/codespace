#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 7;
int n, m, e;
struct P
{
    int to;
    P *next;
    P(int t, P *n) : to(t), next(n) {}
};
P *head[MAXN];
int match[MAXN], reserved[MAXN], ans;
int ntr(int u)
{
    for (auto p = head[u]; p; p = p->next)
    {
        int v = p->to;
        if (!reserved[v])
        {
            reserved[v] = 1;
            if (!match[v] || ntr(match[v]))
            {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> e;
    for (int i = 1; i <= e; i++)
    {
        int u, v;
        cin >> u >> v;
        v += n;
        head[u] = new P(v, head[u]);
        head[v] = new P(u, head[v]);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(reserved, 0x00, sizeof(reserved));
        ans += ntr(i);
    }
    printf("%d\n", ans);
    return 0;
}