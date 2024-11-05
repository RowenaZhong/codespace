#include <bits/stdc++.h>
using namespace std;
int n, m, s, t;
const int MAXN = 201, MAXM = 5007;
int head[MAXN], nxt[MAXM << 1], to[MAXM << 1],  cnt = 1;
long long wei[MAXM << 1];
void add(int x, int y, int w)
{
    cnt++, nxt[cnt] = head[x], to[cnt] = y, wei[cnt] = w, head[x] = cnt;
    cnt++, nxt[cnt] = head[y], to[cnt] = x, wei[cnt] = 0, head[y] = cnt;
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &s, &t);
    while (m--)
    {
        int x, y, w;
        scanf("%d %d %d", &x, &y, &w);
        add(x, y, w);
    }
    long long flow = 0, ans = 0;
    while(bfs())
        while(flow = dfs(s, LONG_LONG_MAX))
            ans += flow;
    printf("%d\n", ans);
    return 0;
}
