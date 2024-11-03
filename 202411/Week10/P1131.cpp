#include <bits/stdc++.h>
using namespace std;
class P
{
public:
    int to;
    long long weight;
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
        this->next = nullptr;
    }
};
P *e[500007];

long long ans;
long long dfs(int x, int fa)
{
    P *store = nullptr;
    long long max_depth = 0;
    for (P *p = e[x]; p; p = p->next)
    {
        if (p->to == fa)
            continue;
        store = new P(p->to, dfs(p->to, x) + p->weight, store);
        max_depth = max(max_depth, store->weight);
    }
    for (P *p = store; p; p = p->next)
        ans = ans + max_depth - p->weight;
    return max_depth;
}
int n, s, a, b, t;
int main()
{
    scanf("%d\n%d\n", &n, &s);
    while (--n)
    {
        scanf("%d %d %d", &a, &b, &t);
        e[a] = new P(b, t, e[a]);
        e[b] = new P(a, t, e[b]);
    }
    dfs(s, 0);
    cout << ans << endl;
    return 0;
}