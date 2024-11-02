#include <iostream>
using namespace std;
const int MAXN = 5e5 + 7;

typedef struct
{
    int lmax, rmax, sum, dat, lp, rp;
} node;
node SegTree[MAXN << 2];
#define lmax(p) SegTree[p].lmax
#define rmax(p) SegTree[p].rmax
#define sum(p) SegTree[p].sum
#define dat(p) SegTree[p].dat
#define lp(p) SegTree[p].lp
#define rp(p) SegTree[p].rp

int n, m;
int A[MAXN];
void update(node &p, node &l, node &r)
{
    p.lmax = max(l.lmax, l.sum + r.lmax);
    p.rmax = max(r.rmax, l.rmax + r.sum);
    p.sum = l.sum + r.sum;
    p.dat = max(l.rmax + r.lmax, max(l.dat, r.dat));
}
void build(int l, int r, int p)
{
    lp(p) = l, rp(p) = r;
    if (l == r)
    {
        sum(p) = dat(p) = lmax(p) = rmax(p) = A[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, p << 1);
    build(mid + 1, r, (p << 1) | 1);
    update(SegTree[p], SegTree[p << 1], SegTree[(p << 1) | 1]);
}

node Query(int l, int r, int p)
{
    if (l == lp(p) && r == rp(p))
        return SegTree[p];
    int mid = (lp(p) + rp(p)) >> 1;
    if (r <= mid)
        return Query(l, r, p << 1);
    else if (l > mid)
        return Query(l, r, (p << 1) | 1);
    else
    {
        node left = Query(l, mid, p << 1);
        node right = Query(mid + 1, r, (p << 1) | 1);
        node ret;
        update(ret, left, right);
        return ret;
    }
}
void Set(int x, int y, int p)
{
    if (lp(p) == rp(p))
        lmax(p) = rmax(p) = sum(p) = dat(p) = y;
    else
    {
        if (x <= ((lp(p) + rp(p)) >> 1))
            Set(x, y, p << 1);
        else
            Set(x, y, (p << 1) | 1);
        update(SegTree[p], SegTree[p << 1], SegTree[(p << 1) | 1]);
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", A + i);
    build(1, n, 1);
    while (m--)
    {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (a == 1)
        {
            if (b > c)
                swap(b, c);
            printf("%d\n", Query(b, c, 1).dat);
        }
        else
        {
            Set(b, c, 1);
        }
    }
    return 0;
}