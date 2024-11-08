#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int n, k, a[MAXN], s[MAXN], f[MAXN];
int q[MAXN], h, t;
inline long long x(int i)
{
    return -s[i];
}
inline long long y(int i)
{
    return f[i] - (long long)s[i]*s[i];
}
inline long double calcSlope(int i, int j)
{
    long double dx = x(i) - x(j);
    if (x(i) == x(j))
        return (y(i) == y(j)) ? 0 : (y(i) > y(j)) ? 1e20 : -1e20;
    return (y(i) - y(j)) / dx;
}
int main()
{
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= k; i++) {
        h = t = 0;
        memset(q,0x00,sizeof(q));
        for(int j =1;j<=n;j++)
        {
            while(h<t&&calcSlope(h,h+1)<(long double)s[i])h++;
            f[j]=f[h]+s[h]*(s[j]-s[h]);
            while(h<t&&calcSlope(t,t-1)>calcSlope(t,j))t--;
            f[++t]=j;
        }
    }
    printf("%d\n",f[n]);
    return 0;
}
