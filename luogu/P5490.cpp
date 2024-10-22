#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int n;
int dy[MAXN * 2], dys;
class Seg
{
public:
    int x, y1, y2, k;
    bool operator<(const Seg &b)
    {
        return this->x < b.x;
    }
};
class SegNode
{
public:
    int l, r;
    int len, cnt;
};
Seg segs[MAXN * 8];
SegNode segnodes[MAXN * 16];
int maxn = INT_MIN;
void build(int l, int r, int node)
{
    segnodes[node].l = l;
    segnodes[node].r = r;
    segnodes[node].len = 0;
    segnodes[node].cnt = 0;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(l, mid, node * 2);
    build(mid + 1, r, node * 2 + 1);
}
void update(int node)
{
    if (segnodes[node].l == maxn && segnodes[node].r == maxn)
        return;
    if (segnodes[node].cnt)
        segnodes[node].len = dy[segnodes[node].r + 1] - dy[segnodes[node].l];
    else
        segnodes[node].len = segnodes[node * 2].len + segnodes[node * 2 + 1].len;
}
void add(int l, int r, int node, int k)
{
    // printf("%d %d %d\n", l, r, node);
    if (l <= segnodes[node].l && segnodes[node].r <= r)
    {
        segnodes[node].cnt += k;
        update(node);
        return;
    }
    int mid = (segnodes[node].l + segnodes[node].r) >> 1;
    if (l <= mid)
        add(l, r, node * 2, k);
    if (r > mid)
        add(l, r, node * 2 + 1, k);
    update(node);
}

int c[MAXN * 2];
int lookupy(int x)
{
    int l = 1, r = dys;
    while (l != r)
    {
        int mid = (l + r) >> 1;
        if (dy[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        segs[i * 2].x = x1;
        segs[i * 2].y1 = y1;
        segs[i * 2].y2 = y2;
        segs[i * 2].k = 1;
        segs[i * 2 + 1].x = x2;
        segs[i * 2 + 1].y1 = y1;
        segs[i * 2 + 1].y2 = y2;
        segs[i * 2 + 1].k = -1;
        dy[i * 2 + 1] = y1;
        dy[i * 2 + 2] = y2;
    }
    sort(dy + 1, dy + n * 2 + 1);
    dys = unique(dy + 1, dy + n * 2 + 1) - dy - 1;
    sort(segs, segs + n * 2);
    build(1, dys, 1);
    // for (int i = 1; i <= dys; i++)
    //     printf("%d%c", dy[i], " \n"[i == dys]);
    for (int i = 0; i < n * 2; i++)
    {
        segs[i].y1 = lookupy(segs[i].y1);
        segs[i].y2 = lookupy(segs[i].y2);
        maxn = max(maxn, segs[i].y1);
        // printf("%d %d %d %d\n", segs[i].x, segs[i].y1, segs[i].y2, segs[i].k);
    }
    unsigned long long Ans = 0;
    for (int i = 0; i < n * 2 - 1; i++)
    {
        // printf("%d %d\n", segs[i].y1, segs[i].y2);
        add(segs[i].y1, segs[i].y2 - 1, 1, segs[i].k);
        // printf("%d\n", segnodes[1].len);
        Ans += (unsigned long long)(segnodes[1].len) * (segs[i + 1].x - segs[i].x);
    }
    printf("%llu\n", Ans);
    return 0;
}