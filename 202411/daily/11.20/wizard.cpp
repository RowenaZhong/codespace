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
inline void reada(size_t n, T *arr)
{
    for (auto i = 0; i < n; i++)
        readi(arr[i]);
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
template <typename T>
inline void writea(size_t n, T *arr)
{
    for (auto i = 0; i < n; i++)
        writei(arr[i]), putchar(" \n"[i == n - 1]);
}
} // namespace IO
int n, m;
int w[22][22], c[22][22], f[22][(1 << 18)], g[22][(1 << 18)], a[22], ans[22],
    minn;
void dfs(int vis, int now, int dep, int cst, int tm)
{
    if (tm >= minn)
        return;
    if (cst >= g[now][vis] && tm >= f[vis][now])
        return;
    if (cst < g[now][vis] && tm < f[vis][now])
        g[vis][now] = cst, f[vis][now] = tm;
    if (cst > m)
        return;
    a[dep] = now;
    if (dep == n) {
        minn = tm;
        for (int i = 1; i <= n; i++)
            ans[i] = a[i];
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!((vis >> (i - 1)) & 1))
            dfs(vis ^ (1 << (i - 1)), i, dep + 1, cst + c[now][i],
                tm + w[now][i]);
}
int main()
{
    freopen("wizard.in", "r", stdin);
    freopen("wizard.out", "w", stdout);
    IO::readl(n, m);
    memset(f, 0x3f, sizeof(f));
    memset(g, 0x3f, sizeof(g));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            IO::readi(w[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            IO::readi(c[i][j]);
    minn = INT_MAX;
    for (int i = 1; i <= n; i++)
        dfs((1 << (i - 1)), i, 1, 0, 0);
    IO::writel(minn);
    IO::writea(n, ans + 1);
    return 0;
}
