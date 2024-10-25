#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
int n, m;
int a[MAXN];
#define lowbit(x) (x) & (-x)
void add(int x, int k)
{
    for (; x <= n; x += lowbit(x))
        a[x] += k;
}
int query(int x)
{
    int ret = 0;
    for (; x; x -= lowbit(x))
        ret += a[x];
    return ret;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int t;
        scanf("%d", &t);
        add(i, t);
    }
    while (m--)
    {
        int opt, x, y;
        scanf("%d %d %d", &opt, &x, &y);
        if (opt == 1)
            add(x, y);
        else
            printf("%d\n", query(y) - query(x - 1));
    }
    return 0;
}