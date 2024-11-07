#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3 + 7, maxm = 5e4 + 7, inf = INT_MAX;
int n, m, s, t;
int head[maxn], to[maxm * 2], nxt[maxm * 2], wei[maxm * 2], cost[maxm * 2],
    dis[maxn], incf[maxn], tot = 1, vis[maxn], pre[maxn];
int sum_cost, sum_flow;
inline void add_edge(int u, int v, int w, int c)
{
    tot++;
    nxt[tot] = head[u];
    wei[tot] = w;
    cost[tot] = c;
    to[tot] = v;
    head[u] = tot;
}
inline void add(int u, int v, int w, int c)
{
    add_edge(u, v, w, c);
    add_edge(u, v, 0, -c);
}
bool spfa()
{
    memset(dis, 0x7f, sizeof dis);
    memset(vis, 0x00, sizeof vis);
    queue<int> q;
    dis[s] = 0;
    q.push(s);
    vis[s] = true;
    incf[s] = INT_MAX;
    while (q.size()) {
        auto u = q.front();
        q.pop();
        vis[u] = false;
        for (auto i = head[s]; i; i = nxt[i]) {
            auto v = to[i];
            if (dis[v] > dis[u] + cost[i]) {
                dis[v] = dis[u] + cost[i];
                incf[v] = min(incf[u], wei[i]);
                if (!vis[v])
                    vis[v] = true, q.push(v);
                pre[v] = i;
            }
        }
    }
    return dis[t] != 0x7f7f7f7f;
}
void update()
{
    auto u = t;
    while (u != s) {
        auto e = pre[u];
        sum_cost += cost[e] * incf[t];
        wei[e] -= incf[t];
        wei[e ^ 1] += incf[t];
        u = to[e ^ 1];
    }
    sum_flow += incf[t];
}
int main()
{
    scanf("%d %d %d %d", &n, &m, &s, &t);
    while (m--) {
        int u, v, w, c;
        scanf("%d %d %d %d", &u, &v, &w, &c);
        add(u, v, w, c);
    }
    while (spfa())
        update();
    printf("%d %d\n", sum_flow, sum_cost);
    return 0;
}
