#include <bits/stdc++.h>
using namespace std;
class Edge
{
public:
    int u, v, w;
    bool operator<(const Edge &e)
    {
        return this->w < e.w;
    }
};
int fa[5005];
Edge e[200007];
int n, m;
int getfa(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = getfa(fa[x]);
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);
    }
    sort(e + 1, e + m + 1);
    for (int i = 1; i <= n; i++)
        fa[i] = i;
    int tot = 0, w = 0;
    for (int i = 1; i <= m; i++)
    {
        if (getfa(e[i].u) != getfa(e[i].v))
            fa[getfa(e[i].u)] = getfa(e[i].v), tot++, w += e[i].w;
    }
    if (tot != n - 1)
        puts("orz");
    else
        printf("%d\n", w);
    return 0;
}