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
const int MAXN = 2e5 + 7;
long long n, q, l, r;
long long a[MAXN];
long long opt[MAXN], x[MAXN], s[MAXN], t[MAXN];
bool checkl(long long u)
{
    for (int i = 1; i <= q; i++) {
        if (opt[i] == 1) {
            if (u >= x[i])
                u = t[i] * (u + s[i]);
        } else {
            if (u <= x[i])
                u = (u - s[i]) / t[i];
        }
    }
    return l <= u;
}
bool checkr(long long u)
{
    for (int i = 1; i <= q; i++) {
        if (opt[i] == 1) {
            if (u >= x[i])
                u = t[i] * (u + s[i]);
        } else {
            if (u <= x[i])
                u = (u - s[i]) / t[i];
        }
    }
    return u <= r;
}
int main()
{
    freopen("arithmetic.in", "r", stdin);
    freopen("arithmetic.out", "w", stdout);
    readl(n, q, l, r);
    for (int i = 1; i <= n; i++)
        readi(a[i]);
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= q; i++)
        readl(opt[i], x[i], s[i], t[i]);
    int l = 1, r = n;
    int ql, qr;
    while (l < r) {
        auto mid = l + r >> 1;
        if (checkl(a[mid]))
            r = mid;
        else
            l = mid + 1;
    }
    ql = l;
    l = 1, r = n;
    while (l < r) {
        auto mid = (l + r + 1) >> 1;
        if (checkr(a[mid]))
            l = mid;
        else
            r = mid - 1;
    }
    qr = r;
    writel(max(qr - ql + 1, 0));
    return 0;
}
