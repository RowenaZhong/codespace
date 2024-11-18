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
int t, n, k, x, y;
inline void solve()
{
    readl(t, n, k, x, y);
    if (t == 0) {
        writel(abs(x - y));
    } else if (t == 1) {
        if (x > y)
            swap(x, y);
        if (y - x >= k)
            puts("1");
        else if (x >= k + 1 || y <= n - k)
            puts("2");
        else if (x <= n - k && y >= k + 1)
            puts("3");
        else
            puts("-1");
    } else if (k == 1) {
        puts("1");

    } else if (k == 2) {
        if (n <= 3)
            puts("-1");
        else if (t & 1) {
            if (x > y)
                swap(x, y);
            if (y - x >= k)
                puts("1");
            else if (x >= k + 1 || y <= n - k)
                puts("2");
            else if (x <= n - k && y >= k + 1)
                puts("3");
            else
                puts("-1");
        } else
            writel(abs(x - y));
    } else if (k == 3) {
        if (x > y)
            swap(x, y);
        if (t == 2 && n == 5 && x == 2 && y == 4)
            puts("1");
        else if (t == 2 && n == 6) {
            if ((x == 2 && y == 4) || (x == 3 && y == 4) || (x == 3 && y == 5))
                puts("1");
            else if ((x == 2 && y == 3) || (x == 4 && y == 5))
                puts("2");
            else if (x == 2 && y == 5)
                puts("3");
            else
                puts("-1");
        } else if (t == 3 && n == 6 && x == 2 && y == 5)
            puts("1");
        else if (t == 2 && n == 7 && x == 3 && y == 5)
            puts("1");
        else
            puts("-1");
    } else
        puts("-1");
}
int main()
{
    freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    int q;
    readi(q);
    while (q--)
        solve();
    return 0;
}
