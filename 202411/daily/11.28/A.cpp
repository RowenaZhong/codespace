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
int digits[10];
int a[1024], b[1024];
int n, m;
void CountDigits(int x)
{
    while (x)
    {
        digits[x % 10]++;
        x /= 10;
    }
}
void solve()
{
    memset(digits, 0, sizeof(digits));
    IO::readl(n, m);
    for (int i = 0; i < n; i++)
        IO::readi(a[i]);
    for (int i = 0; i < m; i++)
        IO::readi(b[i]);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            CountDigits(a[i] * b[j]);
    for (int i = 0; i < 10; i++)
        IO::writei(digits[i]), putchar(" \n"[i == 9]);
}
int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    int T;
    IO::readi(T);
    while (T--)
        solve();
    return 0;
}
