#include <bits/stdc++.h>
using namespace std;
const int MAXN = 107;
class P
{
public:
    int to, weight;
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
    }
};
int c[MAXN], u[MAXN];
P *e[MAXN];
int n, m;
int degin[MAXN], degout[MAXN];
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d %d", c + i, u + i);
    while (m--)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        e[u] = new P(v, w, e[u]);
        degin[v]++;
        degout[u]++;
    }
    queue<int> que;
    for (int i = 1; i <= n; i++)
        if (degin[i] == 0)
            que.push(i);
    while (que.size())
    {
        int t = que.front();
        que.pop();
        c[t] -= u[t];
        for (P *p = e[t]; p; p = p->next)
        {
            if (c[t] > 0)
                c[p->to] += p->weight * c[t];
            if (--degin[p->to] == 0)
                que.push(p->to);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (degout[i] == 0 && c[i] > 0)
        {
            printf("%d %d\n", i, c[i]);
            cnt++;
        }
    }
    if (!cnt)
        puts("NULL");
    return 0;
}