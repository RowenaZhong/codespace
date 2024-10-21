
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
int n, m;
class SegNode
{
public:
    int l, r;
    int sum;
    bool tag;
};
SegNode seg[MAXN << 2];
void build(int node, int l, int r)
{
    seg[node].l = l;
    seg[node].r = r;
    seg[node].sum = 0;
    seg[node].tag = 0;
    if (l != r)
    {
        int mid = (l + r) >> 1;
        build(node * 2, l, mid);
        build(node * 2 + 1, mid + 1, r);
    }
}
void spread(int node)
{
    if (seg[node].tag)
    {
        seg[node * 2].tag ^= 1;
        seg[node * 2 + 1].tag ^= 1;
        seg[node * 2].sum = (seg[node * 2].r - seg[node * 2].l + 1) - seg[node * 2].sum;
        seg[node * 2 + 1].sum = (seg[node * 2 + 1].r - seg[node * 2 + 1].l + 1) - seg[node * 2 + 1].sum;
        seg[node].tag = false;
    }
}
void adxor(int node, int l, int r)
{
    if (seg[node].l == seg[node].r)
    {
        seg[node].sum ^= 1;
        return;
    }
    if (l <= seg[node].l && seg[node].r <= r)
    {
        seg[node].tag ^= 1;
        seg[node].sum = (seg[node].r - seg[node].l + 1) - seg[node].sum;
        return;
    }
    spread(node);
    int mid = (seg[node].l + seg[node].r) >> 1;
    if (l <= mid)
        adxor(node * 2, l, r);
    if (r > mid)
        adxor(node * 2 + 1, l, r);
    seg[node].sum = seg[node * 2].sum + seg[node * 2 + 1].sum;
}
int query(int node, int l, int r)
{
    if (l <= seg[node].l && seg[node].r <= r)
        return seg[node].sum;
    spread(node);
    int mid = (seg[node].l + seg[node].r) >> 1;
    int ret = 0;
    if (l <= mid)
        ret += query(node * 2, l, r);
    if (r > mid)
        ret += query(node * 2 + 1, l, r);
    return ret;
}
int main()
{
    scanf("%d %d", &n, &m);
    build(1, 1, n);
    while (m--)
    {
        int opt, a, b;
        scanf("%d %d %d", &opt, &a, &b);
        if (opt == 0)
        {
            adxor(1, a, b);
        }
        else
        {
            printf("%d\n", query(1, a, b));
        }
    }
    return 0;
}