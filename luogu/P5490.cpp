#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int n;
int dx[MAXN * 2], dxs, dy[MAXN * 2], dys;
class Seg
{
public:
    int x, y1, y2, k;
    bool operator<(const Seg &b)
    {
        return this->x < b.x;
    }
};
Seg segs[MAXN * 2];
int c[MAXN * 2];
int lookupx(int x)
{
    int l = 0, r = dxs - 1;
    while (l != r)
    {
        int mid = (l + r) >> 1;
        if (dx[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int lookupy(int x)
{
    int l = 0, r = dys - 1;
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
        dx[i * 2] = x1;
        dx[i * 2 + 1] = x2;
        dy[i * 2] = y1;
        dy[i * 2 + 1] = y2;
    }
    sort(dx, dx + n * 2);
    dxs = unique(dx, dx + n * 2) - dx;
    sort(dy, dy + n * 2);
    dys = unique(dy, dy + n * 2) - dy;
    sort(segs, segs + n * 2);
    for (int i = 0; i < n * 2; i++)
    {
        segs[i].x = lookupx(segs[i].x);
        segs[i].y1 = lookupy(segs[i].y1);
        segs[i].y2 = lookupy(segs[i].y2);
        // printf("%d %d %d %d\n", segs[i].x, segs[i].y1, segs[i].y2, segs[i].k);
    }
    unsigned long long Ans = 0;
    for (int i = 0; i < n * 2; i++)
    {
        for (int j = segs[i].y1; j < segs[i].y2; j++)
            c[j] += segs[i].k;
        if (i < n * 2 - 1)
        {
            unsigned long long h = 0;
            for (int j = 1; j < dys; j++)
            {
                if (c[j - 1])
                    h += dy[j] - dy[j - 1];
            }
            Ans += h * (dx[i + 1] - dx[i]);
        }
    }
    printf("%llu\n", Ans);
    return 0;
}