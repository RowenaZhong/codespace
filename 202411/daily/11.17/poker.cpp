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
const int MAXN = 1e6 + 7;
int n;
int s[MAXN], r[MAXN], t[MAXN];
bool preSelected[MAXN];
bool bitOperator;
unsigned long long ans;
int main()
{
    freopen("poker.in", "r", stdin);
    freopen("poker.out", "w", stdout);
    readi(n);
    for (int i = 1; i <= n; i++)
        scanf("%1d", s + i);
    for (int i = 1; i <= n; i++)
        readi(r[i]);
    for (int i = 1; i <= n; i++)
        readi(t[i]);
    for (int i = 1; i <= n; i++) {
        s[i] ^= bitOperator;
        if (s[i])
            bitOperator ^= 1, ans += t[i], preSelected[r[i]] ^= 1;
        bitOperator ^= preSelected[i];
    }
    writel(ans);
    return 0;
}
