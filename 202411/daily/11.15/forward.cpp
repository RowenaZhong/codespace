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
    while (!feof(stdin) && isdigit(ch)) {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
inline void readl() {}
template <typename T, typename... Args>
inline void readl(T &x, Args &...args)
{
    readi(x);
    readl(args...);
}
template <typename T>
inline void writei(T x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p) {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}
inline void writel() {}
template <typename T, typename... Args>
inline void writel(T x, Args... args)
{
    writei(x);
    putchar(" \n"[sizeof...(args) == 0]);
    writel(args...);
}
int sumAnd[5002],sumXor[5002],n,a[5002];
int main()
{
    freopen("forward.in", "r", stdin);
    freopen("forward.out", "w", stdout);
    readi(n);
    for(int i=1;i<=n;i++)
    {
        readi(a[i]);
    }
    long long ans=0;
    for(int l=1;l<=n;l++)
    {
        sumAnd[l-1]=INT_MAX;
        sumXor[l-1]=0;
        for(int r=l;r<=n;r++)
        {
            sumAnd[r]=sumAnd[r-1]&a[r];
            sumXor[r]=sumXor[r-1]^a[r];
            if(sumAnd[r]==sumXor[r])ans++;
        }
    }
    writel(ans);
    return 0;
}