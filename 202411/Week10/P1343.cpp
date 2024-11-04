#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205, MAXM = 2007;
int n, m, x;
int head[MAXN], to[MAXM], wei[MAXM], nxt[MAXM], now[MAXN], tot;
void add(int a, int b, int c)
{
    to[++tot] = b;
    wei[tot] = c;
    nxt[tot] = head[a];
    head[a] = tot;

    to[++tot] = a;
    wei[tot] = 0;
    nxt[tot] = head[b];
    head[b] = tot;
}
queue<int>q;
int d[MAXN];
bool bfs()
{
    memset(d, 0, sizeof(d));
    q = queue<int>();
    q.push(1);
    d[1] = 1;
    while(q.size())
    {
        int u = q.front();
        q.pop();
        now[u] = head[u];
        if(u == n)return true;
        for(int i = head[u]; i; i = nxt[i])
        {
            int v = to[i];
            if(wei[i] && !d[v])
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return false;
}
int dinic(int x, int flow)
{
    if(x == n)return flow;
    int ret = 0, k, rest = flow;
    for(; now[x]; now[x] = nxt[now[x]]) 
    {
        int v = to[now[x]];
        if(wei[now[x]] && d[v] == d[x] + 1)
        {
            k = dinic(v, min(rest, wei[now[x]]));
            rest -= k;
            wei[now[x]] -= k;
            wei[now[x] ^ 1] += k;
            if(!rest)return flow;
        }
    }
    return flow - rest;
}

int main()
{
    scanf("%d %d %d", &n, &m, &x);
    while(m--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        add(a, b, c);
    }
    int ans = 0, flow;
    while(bfs())
        while(flow = dinic(1, INT_MAX))
            ans += flow;
    if(ans == 0)
        puts("Orz Ni Jinan Saint Cow!");
    else
        printf("%d %d\n", ans, x / ans + (x % ans != 0));
    return 0;
}