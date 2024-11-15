#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void readi(T &x)
{
    T f = 1;
    x = 0;
    int ch;
    while (ch = getchar(), !feof(stdin) && !isdigit(ch) && ch != '-')
        ;
    if (ch == '-')
        f = -f, ch = getchar();
    while (!feof(stdin) && isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
inline void readl()
{
}
template<typename T,typename ...Args>
inline void readl(T &x,Args &...args)
{
    readi(x);
    readl(args...);
}
template <typename T>
inline void writei(T x)
{
    if (x == 0)
    {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p)
    {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}
inline void writel()
{
}
template<typename T,typename ...Args>
inline void writel(T x, Args ...args)
{
    writei(x);
    putchar(" \n"[sizeof...(args)==0]);
    writel(args...);
}
const int MAXN=2007;
long long dp[MAXN],c[MAXN],y[MAXN],a[MAXN],sumA[MAXN],ans=0;
int n,m;
int main()
{
    freopen("coin.in", "r", stdin);
    freopen("coin.out", "w", stdout);
    readl(n,m);
    for(int i=1;i<=n;i++)readi(a[i]),sumA[i]=sumA[i-1]+a[i];
    for(int i=1;i<=m;i++)readl(c[i],y[i]);
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        dp[i]=dp[i-1]+a[i];
        for(int j=1;j<=m;j++)
            if(i>=c[j])
                dp[i]=max(dp[i],dp[i - c[j] - 1] + y[j] + sumA[i] - sumA[i - c[j]]);
        ans=max(ans,dp[i]);
    }
    writei(ans);
    return 0;
}