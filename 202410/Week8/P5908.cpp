/*
 *   https://www.luogu.com.cn/problem/P5908
 */
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
};
const int MAXN = 1e5 + 7;
int n;
P *e[MAXN];
int dfs(int n, int fa, int d)
{
    if (d == 0)
        return 1;
    int ret = 1;
    for (P *p = e[n]; p; p = p->next)
    {
        if (p->to == fa)
            continue;
        ret += dfs(p->to, n, d - 1);
    }
    return ret;
}
int main()
{
    int d;
    scanf("%d %d", &n, &d);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        e[u] = new P(v, e[u]);
        e[v] = new P(u, e[v]);
    }
    printf("%d\n", dfs(1, 0, d) - 1);
    return 0;
}