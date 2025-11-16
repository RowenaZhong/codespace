#include <bits/stdc++.h>
using namespace std;
struct P
{
    int v, w;
    P *next;
    P(int _v, int _w, P *_n) : v(_v), w(_w), next(_n) {}
};
const int MAXN = 1e4 + 7;
const int MAXK = 10;
const int MAXM = 1e6 + 7;
P *head[MAXN];
P *head_new[MAXN * 2];
int c[MAXK], vis[MAXN * 2], dis[MAXN * 2];
int n, m, k;
long long curans, ans = 1e18;
int upgrade;
#define town_to_city(town) ((town) + MAXN)
#define allowed(city) (((city) < MAXN) || ((city) >= MAXN && ((upgrade >> ((city) - MAXN)) & 1)))

int count_upgrade()
{
    int ret = 0, x = upgrade;
    while (x)
    {
        x -= x & (-x);
        ret++;
    }
    return ret;
}
void process0()
{
    curans = 0;
    int to_be_included = n;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({0, {1, 0}});
    memset(vis, 0x00, sizeof(vis));
    memset(dis, 0x37, sizeof(dis));
    while (pq.size() && to_be_included)
    {
        int d = -pq.top().first, u = pq.top().second.first, fu = pq.top().second.second;
        pq.pop();
        if (vis[u])
            continue;
        if (fu != 0)
        {
            head_new[u] = new P(fu, d, head_new[u]);
            head_new[fu] = new P(u, d, head_new[fu]);
        }
        vis[u] = true;
        curans += d;
        to_be_included--;
        // if (curans > ans)
        //     return;
        for (P *p = head[u]; p; p = p->next)
        {
            if (vis[p->v] || p->w >= dis[p->v])
                continue;
            dis[p->v] = p->w;
            pq.push({-p->w, {p->v, u}});
        }
    }
    // ans = min(ans, curans);
    ans = curans;
}
void process1()
{
    curans = 0;
    for (int i = 0; i < k; i++)
    {
        if ((upgrade >> i) & 1)
            curans += c[i];
    }
    int to_be_included = n + count_upgrade();
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    memset(vis, 0x00, sizeof(vis));
    while (pq.size() && to_be_included)
    {
        int d = -pq.top().first, u = pq.top().second;
        pq.pop();
        if (vis[u])
            continue;
        vis[u] = true;
        curans += d;
        to_be_included--;
        // if (curans > ans)
        //     return;
        for (P *p = head_new[u]; p; p = p->next)
        {
            if (vis[p->v] || !allowed(p->v))
                continue;
            pq.push({-p->w, p->v});
        }
    }
    ans = min(ans, curans);
    // ans = curans;
}

int main()
{
    // freopen("club.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        head[u] = new P(v, w, head[u]);
        head[v] = new P(u, w, head[v]);
    }
    for (int i = 0; i < k; i++)
    {
        cin >> c[i];
        for (int v = 1; v <= n; v++)
        {
            int w;
            cin >> w;
            int u = town_to_city(i);
            head_new[u] = new P(v, w, head_new[u]);
            head_new[v] = new P(u, w, head_new[v]);
        }
    }
    process0();
    for (upgrade = 1; upgrade < (1 << k); upgrade++)
    {
        process1();
    }
    printf("%lld\n", ans);
    return 0;
}