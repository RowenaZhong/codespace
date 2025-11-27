#include <iostream>
using namespace std;
typedef struct
{
    int first, second, dat, ld, rd, sum;
} node;
#define l(p) SegTree[p].l
#define r(p) SegTree[p].r
#define dat(p) SegTree[p].dat
#define ld(p) SegTree[p].ld
#define rd(p) SegTree[p].rd
#define sum(p) SegTree[p].sum
#define mid(l, r) ((l + r) >> 1)
node SegTree[200007];
int n, q, a[50007];
inline void update(int p)
{
    ld(p) = max(ld(p << 1), sum(p << 1) + ld((p << 1) | 1));
    rd(p) = max(rd((p << 1) | 1), sum((p << 1) | 1) + rd(p << 1));
    sum(p) = sum(p << 1) + sum((p << 1) | 1);
    dat(p) = max(rd(p << 1) + ld((p << 1) | 1), max(dat(p << 1), dat((p << 1) | 1)));
}
void build(int l, int r, int p)
{
    l(p) = l, r(p) = r;
    if (l == r)
    {
        dat(p) = ld(p) = rd(p) = sum(p) = a[l];
        return;
    }
    build(l, mid(l, r), p << 1);
    build(mid(l, r) + 1, r, (p << 1) | 1);
    update(p);
}
void Change(int p, int x, int y)
{
    if (l(p) == r(p))
    {
        dat(p) = ld(p) = rd(p) = sum(p) = y;
        return;
    }
    if (x <= mid(l(p), r(p)))
        Change(p << 1, x, y);
    else
        Change((p << 1) | 1, x, y);
    update(p);
}
node Query(int p, int l, int r)
{
    if (l == l(p) && r == r(p))
        return SegTree[p];
    if (r <= mid(l(p), r(p)))
        return Query(p << 1, l, r);
    else if (l > mid(l(p), r(p)))
        return Query((p << 1) | 1, l, r);
    node nl = Query(p << 1, l, mid(l(p), r(p)));
    node nr = Query((p << 1) | 1, mid(l(p), r(p)) + 1, r);
    node ans;
    ans.ld = max(nl.ld, nl.sum + nr.ld);
    ans.rd = max(nr.rd, nr.sum + nl.rd);
    ans.sum = nl.sum + nr.sum;
    ans.dat = max(nl.rd + nr.ld, max(nl.dat, nr.dat));
    return ans;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    build(1, n, 1);
    scanf("%d", &q);
    while (q--)
    {
        int c, x, y;
        scanf("%d %d %d", &c, &x, &y);
        if (c == 0)
            Change(1, x, y);
        else
            printf("%d\n", Query(1, x, y).dat);
    }
    return 0;
}