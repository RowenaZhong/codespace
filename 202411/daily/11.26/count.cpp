#include <bits/stdc++.h>
using namespace std;
namespace IO
{
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
    inline void writel() {}
    template <typename T, typename... Args>
    inline void writel(T x, Args... args)
    {
        writei(x);
        putchar(" \n"[sizeof...(args) == 0]);
        writel(args...);
    }
}
const int MAXN = 2e5 + 7, MAXA = 1e6 + 7;
int n, a[MAXN];
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
inline bool check(int l, int r)
{
    for (int i = l; i < r; i++)
        if (gcd(a[i], a[r]) != 1)
            return false;
    return true;
}
int main()
{
    freopen("count.in", "r", stdin);
    freopen("count.out", "w", stdout);
    IO::readi(n);
    bool spj = true;
    for (int i = 1; i <= n; i++)
    {
        IO::readi(a[i]);
        if (a[i] > 2)
            spj = false;
    }
    if (spj)
    {
        long long ans = 0;
        int last2 = 0, lastlast2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 2)
            {
                ans += i - last2;
                lastlast2 = last2;
                last2 = i;
            }
            else
            {
                ans += i - lastlast2;
            }
        }
        IO::writel(ans);
        return 0;
    }
    int l = 1;
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (!check(l, i))
            l++;
        ans += i - l + 1;
    }
    IO::writel(ans);
    return 0;
}
