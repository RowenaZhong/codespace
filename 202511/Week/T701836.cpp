#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
int N, M, S;
struct P
{
    int to;
    P *next;
    P(int to, P *next) : to(to), next(next) {}
};
P *head[MAXN];
int fa[MAXN][20], dep[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M >> S;
    for (int i = 1; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        head[x] = new P(y, head[x]);
        head[y] = new P(x, head[y]);
    }
    queue<int> q;
    q.push(S);
    fa[S][0] = 0;
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        auto f = fa[u][0];
        dep[u] = dep[f] + 1;
        for (int i = 1; i < 20; i++)
            fa[u][i] = fa[fa[u][i - 1]][i - 1];
        for (auto p = head[u]; p; p = p->next)
        {
            int v = p->to;
            if (v == f)
                continue;
            fa[v][0] = u;
            q.push(v);
        }
    }
    while (M--)
    {
        int a, b;
        cin >> a >> b;
        if (dep[a] < dep[b])
            swap(a, b);
        for (int i = 19; i >= 0; i--)
            if (dep[fa[a][i]] >= dep[b])
                a = fa[a][i];
        if (a != b)
        {
            for (int i = 19; i >= 0; i--)
                if (fa[a][i] != fa[b][i])
                {
                    a = fa[a][i];
                    b = fa[b][i];
                }
            a = fa[a][0];
        }
        cout << a << "\n";
    }
    return 0;
}