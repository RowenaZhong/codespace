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
} // namespace IO
typedef long long ll;
typedef unsigned long long ull;
ll a, b, n;
ull ans1, ans2;
const ll p = 1e9 + 7;
ll power(ll a, ll b, ll p)
{
    ll res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
inline void solve()
{
    IO::readl(a, b, n);
    ll cnt = 0;
    while (!(a & 1) & !(b & 1))
        cnt++, a /= 2, b /= 2;
    if ((a + b) & 1) {
        IO::writel(power(2, cnt * n, p));
        return;
    }
    ll ans = cnt * n;
    ans1 = ans2 = 1;
    ll d = n;
    for (; d; d >>= 1) {
        if (d & 1)
            ans1 *= a;
        a *= a;
    }
    d = n;
    for (; d; d >>= 1) {
        if (d & 1)
            ans2 *= b;
        b *= b;
    }
    for (int i = 0; i <= 63; i++) {
        if ((ans1 >> i & 1) ^ (ans2 >> i & 1)) {
            ans += i;
            break;
        }
    }
    IO::writel(power(2, ans, p));
}
signed main()
{
    freopen("journey.in", "r", stdin);
    freopen("journey.out", "w", stdout);
    int t;
    IO::readi(t);
    while (t--)
        solve();
    return 0;
}
