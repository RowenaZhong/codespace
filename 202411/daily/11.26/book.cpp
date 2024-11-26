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
typedef long long ll;
const int MAXN = 1e5 + 7;
int n, l;
int h[MAXN], w[MAXN];
ll f[MAXN], cnt;
int ql, qr;
int que[MAXN];
int main()
{
    freopen("book.in", "r", stdin);
    freopen("book.out", "w", stdout);
    IO::readl(n, l);
    for (int i = 1; i <= n; i++)
        IO::readl(h[i], w[i]);
    int lp = 1;
    ql = qr = 1;

    for (int i = 1; i <= n; i++)
    {
        cnt += w[i];
        while (cnt > l)
            cnt -= w[lp++];
        while (ql <= qr && que[ql] < lp)
            ql++;
        while (ql <= qr && h[que[qr]] <= h[i])
            qr--;
        que[++qr] = i;
        f[i] = f[lp - 1] + h[que[ql]];
        for (int j = ql; j < qr; j++)
            f[i] = min(f[i], f[que[j]] + h[que[j + 1]]);
    }
    IO::writel(f[n]);
    return 0;
}
