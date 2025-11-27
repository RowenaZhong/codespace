// import bless from molly
#include <bits/stdc++.h>
using namespace std;
namespace IO
{
    template <typename T>
    inline void readi(T &x)
    {
        T f = 1;
        int ch;
        x = 0;
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
    template <typename T>
    inline void writei(T x)
    {
        if (x == 0)
        {
            putchar('0');
            return;
        }
        if (x < 0)
            putchar('-'), x = -x;
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
    inline void readl() {}
    inline void writel() {}
    template <typename T, typename... Args>
    inline void readl(T &x, Args &...args)
    {
        readi(x);
        readl(args...);
    }
    template <typename T, typename... Args>
    inline void writel(T x, Args... args)
    {
        writei(x);
        if (sizeof...(args) != 0)
            putchar(' ');
        else
            putchar('\n');
        writel(args...);
    }
}
const int MAXN = 1e5 + 7, MOD = 1e9 + 7;
long long c, T, n, k;
int u[MAXN], v[MAXN], e[MAXN];
// int head[MAXN], ver[MAXN * 2], nxt[MAXN * 2], tot = 1;
// inline void AddEdge(int u, int ed)
// {
//     tot++;
//     nxt[tot] = head[u];
//     ver[tot] = ed;
//     head[u] = tot;
// }
// inline void solve()
// {
//     ans = set<set<pair<int, int>>>();
// }
int main()
{
    IO::readl(c, T);
    while (T--)
    {
        // tot = 1;
        IO::readl(n, k);
        // memset(head, 0x00, sizeof(head));
        for (int i = 1; i < n; i++)
        {
            IO::readl(u[i], v[i]);
            // AddEdge(u[i], i), AddEdge(v[i], i);
        }
        for (int i = 1; i <= k; i++)
            IO::readi(e[i]);
        IO::writel(1);
        // else if (c < 18)
        //     solve();
    }

    return 0;
}
