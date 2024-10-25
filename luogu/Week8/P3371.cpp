#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
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
P *e[MAXN];
bool vis[MAXN];
int dis[MAXN];
int n, m, s;
int main()
{
    scanf("%d %d %d", &n, &m, &s);
    while (m--)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        e[u] = new P(v, w, e[u]);
    }
    queue<int> que;
    que.push(s);
    vis[s] = 1;
    for (int i = 1; i <= n; i++)
        dis[i] = INT_MAX;
    dis[s] = 0;
    while (que.size())
    {
        int t = que.front();
        vis[t] = 0;
        que.pop();
        for (P *p = e[t]; p; p = p->next)
            if (dis[p->to] > dis[t] + p->weight)
            {
                dis[p->to] = dis[t] + p->weight;
                if (!vis[p->to])
                    que.push(p->to), vis[p->to] = true;
            }
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", dis[i], " \n"[i == n]);
    return 0;
}