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
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, s));
    memset(dis, 0x3f, sizeof(dis));
    dis[s] = 0;
    while (pq.size())
    {
        pair<int, int> x = pq.top();
        pq.pop();
        if (vis[x.second])
            continue;
        vis[x.second] = true;
        x.first = -x.first;
        dis[x.second] = x.first;
        for (P *p = e[x.second]; p; p = p->next)
            if (dis[p->to] > x.first + p->weight)
                pq.push(make_pair(-x.first - p->weight, p->to));
    }
    for (int i = 1; i <= n; i++)
        printf("%d%c", dis[i], " \n"[i == n]);
    return 0;
}