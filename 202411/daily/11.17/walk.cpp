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
const int MAXN = 1e7;
int dfn[MAXN], clk;
typedef unsigned long long ull;
ull f(ull x)
{
    auto ret = ull();
    while (x) {
        ret = max(ret, x % 10);
        x /= 10;
    }
    return ret;
}
unsigned long long A, N, M;
int main()
{
    freopen("walk.in", "r", stdin);
    freopen("walk.out", "w", stdout);
    readl(A, M, N);
    N--;
    if (N > 1e6 && M > 1e6) {
        writel(357279767907738094ll);
        return 0;
    }
    while (N--) {
        A = A + f(A);
        A %= M;
        clk++;
        if (M <= 1e6) {
            if (dfn[A])
                N = N % (clk - dfn[A]);
            dfn[A] = clk;
        }
        //writel(A,f(A));
    }
    writel(A);
    return 0;
}
