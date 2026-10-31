#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1007;
int N, M, K;
struct P
{
    int v;
    int w;
    P *nxt;
    P(int _v, int _w, P *_nxt)
    {
        v = _v, w = _w, nxt = _nxt;
    }
} *head[MAXN];
int d[MAXN], vis[MAXN];
void add(int u, int v, int w)
{
    head[u] = new P(v, w, head[u]);
    head[v] = new P(u, w, head[v]);
}

bool check(int mid)
{
    memset(d, 0x37, sizeof(d));
    memset(vis, 0x00, sizeof(vis));
    deque<int> dq;
    dq.push_back(1);
    d[1] = 0;
    while (dq.size())
    {
        auto u = dq.front();
        dq.pop_front();
        if (vis[u])
            continue;
        // printf("%d %d\n", u, d[u]);
        if (u == N)
            return d[u] <= K;
        vis[u] = true;
        for (auto e = head[u]; e; e = e->nxt)
        {
            if (!vis[e->v])
                if (e->w > mid)
                    d[e->v] = min(d[e->v], d[u] + 1), dq.push_back(e->v);
                else
                    d[e->v] = min(d[e->v], d[u]), dq.push_front(e->v);
        }
    }
    return false;
}

int main()
{
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 1; i <= M; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add(u, v, w);
    }
    int l = 0, r = 1000001;
    while (l < r)
    {
        auto mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if (r == 1000001)
        printf("-1\n");
    else
        printf("%d\n", r);
}