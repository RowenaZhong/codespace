#include <iostream>
using namespace std;
int a[200007], n, c[100007], h[100007];
void rm(int x)
{
    for (; x <= n; x += x & (-x))
        c[x]--;
}
int Query(int x)
{
    int Ans = 0;
    for (; x; x -= x & (-x))
        Ans += c[x];
    return Ans;
}
int BQuery(int x) // to those still in array, which is the K-th smallest height
{
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (Query(mid) < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int main()
{
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i += 2)
        c[i] = 1;
    for (int i = 2; i <= n; i += 2)
        c[i] = c[i >> 1] << 1;
    for (int i = n; i > 1; i--)
    {
        h[i] = BQuery(a[i] + 1);
        rm(h[i]);
    }
    h[1] = BQuery(1);
    for (int i = 1; i <= n; i++)
        printf("%d\n", h[i]);
    return 0;
}