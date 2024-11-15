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
int main()
{
    long long T, n;
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    readi(T);
    while (T--) {
        readi(n);
        if (n % 4) {
            puts("No");
            continue;
        }
        long long s1 = 0, s2 = 0;
        for (long long i = sqrt(n); i; i--) {
            if (n % i == 0) {
                if (s1 == 0)
                    s1 = i + n / i;
                else {
                    s2 = i + n / i;
                    break;
                }
            }
        }
        // writel(s1,s2);
        puts((s1 == s2 - 1) ? "Yes" : "No");
    }
    return 0;
}