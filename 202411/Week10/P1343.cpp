#include <bits/stdc++.h>
using namespace std;
const int MAXN = 205, MAXM = 2007;
int n, m, x;
int head[MAXN], to[MAXM], wei[MAXM], nxt[MAXM], now[MAXN], tot = 1;
/*
 *
 * Highlight!!!
 * 使用 ^1 建立反向边时边要从偶数开始编号
 *
*/
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
    now[1] = head[1];
    while(q.size())
    {
        int u = q.front();
        q.pop();
        for(int i = head[u]; i; i = nxt[i])
        {
            int v = to[i];
            if(wei[i] && !d[v])
            {
                q.push(v);
                now[v] = head[v];
                d[v] = d[u] + 1;
                if(v == n)return true;
            }
        }
    }
    return false;
}
int dinic(int x, int flow)
{
    if(x == n)return flow;
    int k, rest = flow;
    for(; now[x] && rest; now[x] = nxt[now[x]]) 
    {
        int v = to[now[x]];
        if(wei[now[x]] && d[v] == d[x] + 1)
        {
            k = dinic(v, min(rest, wei[now[x]]));
            if(!k)d[v] = 0;
            wei[now[x]] -= k;
            wei[now[x] ^ 1] += k;
            rest -= k;
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