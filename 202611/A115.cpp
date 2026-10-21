#include <bits/stdc++.h>
using namespace std;

int n, R;
struct Node
{
    int fa, real_self;
    int cnt, sum;
    int additional_sum;
};

Node nodes[1001];

int get_real_self(int u)
{
    if (nodes[u].real_self != u)
        nodes[u].real_self = get_real_self(nodes[u].real_self);
    return nodes[u].real_self;
}

class cmp
{
public:
    bool operator()(int a, int b)
    {
        /*
         * sum[a]/cnt[a]>sum[b]/cnt[b]
         */
        return nodes[a].sum * nodes[b].cnt < nodes[b].sum * nodes[a].cnt;
    }
};

void Merge(int u)
{
    u = get_real_self(u);
    int fa = nodes[u].fa = get_real_self(nodes[u].fa);
    if (fa == u)
        return;
    nodes[fa].additional_sum += nodes[u].additional_sum + nodes[u].sum * nodes[fa].cnt;
    nodes[fa].cnt += nodes[u].cnt;
    nodes[fa].sum += nodes[u].sum;
    nodes[u].real_self = fa;
}

int main()
{
    scanf("%d %d", &n, &R);
    for (int i = 1; i <= n; i++)
    {
        nodes[i].cnt = 1;
        nodes[i].additional_sum = 0;
        nodes[i].real_self = i;
        scanf("%d", &(nodes[i].sum));
    }
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        nodes[b].fa = a;
    }
    priority_queue<pair<double, int>> pq;
    for (int i = 1; i <= n; i++)
        pq.push(make_pair(nodes[i].sum, i));
    while (pq.size())
    {
        auto tp = pq.top();
        pq.pop();
        auto top = tp.second;
        if (nodes[top].real_self != top)
            continue;
        if (nodes[top].fa == 0)
            continue;
        Merge(top);
        top = nodes[top].fa;
        pq.push(make_pair((double)(nodes[top].sum) / nodes[top].cnt, get_real_self(top)));
    }
    for (int i = 1; i <= n; i++)
    {
        if (nodes[i].fa == 0 && nodes[i].real_self == i)
        {
            printf("%d\n", nodes[i].sum + nodes[i].additional_sum);
        }
    }
    return 0;
}