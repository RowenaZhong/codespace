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
int n, k;
const int MAXN = 1e5;
int head[MAXN], ver[MAXN << 1], nxt[MAXN << 1], tot = 1;
pair<int, int> edges[25];
int deg[MAXN];
inline void AddEdge(int x, int y)
{
    tot++;
    ver[tot] = y;
    nxt[tot] = head[x];
    head[x] = tot;
}
namespace temp
{
    int head[MAXN], ver[MAXN << 1], nxt[MAXN << 1], tot = 1;
    inline void AddEdge(int x, int y)
    {
        tot++;
        ver[tot] = y;
        nxt[tot] = head[x];
        head[x] = tot;
    }
    bool visited[MAXN];
    int dfs(int x)
    {
        visited[x] = true;
        int cnt = 1;
        for (head[x]; head[x]; head[x] = nxt[head[x]])
        {
            int y = ver[head[x]];
            if (visited[y])
                continue;
            cnt += dfs(y);
        }
        return cnt;
    }
}
/* Accepted */
void Spj1()
{
    long long ans = LONG_LONG_MAX;
    for (int i = 0; i < (1 << n); i++)
    {
        if (__builtin_popcount(i) != k)
            continue;
        temp::tot = 1;
        for (int i = 1; i <= 20; i++)
            temp::head[i] = 0;
        for (int j = 0; j < n; j++)
        {
            if (!((i >> j) & 1))
                temp::AddEdge(edges[j].first, edges[j].second),
                    temp::AddEdge(edges[j].second, edges[j].first);
        }
        long long maxTot = 0;
        for (int j = 1; j <= n; j++)
            temp::visited[j] = false;
        for (int j = 1; j <= n; j++)
        {
            if (!temp::visited[j])
            {
                int tot = temp::dfs(j);
                maxTot = max<long long>(maxTot, tot);
            }
        }
        ans = min(ans, maxTot * (k + 1) - n);
    }
    IO::writel(ans);
}
void Spj2() // Accepted
{
    IO::writel((n / (k + 1) + (n % (k + 1) != 0)) * (k + 1) - n);
}
void Spj3()
{
    // cut for 1 time
    IO::writel((n - k - 1) * k);
}
bool visited[MAXN];
long long ans = LONG_LONG_MAX;
int dfs(int x)
{
    if (visited[x])
        return 0;
    visited[x] = true;
    long long tot = 1;
    for (head[x]; head[x]; head[x] = nxt[head[x]])
        tot += dfs(ver[head[x]]);
    ans = min<long long>(ans, abs(tot * 2 - n));
    return tot;
}
void Spj4()
{
    dfs(1);
    IO::writel(ans);
}
int main()
{
    freopen("penalty.in", "r", stdin);
    freopen("penalty.out", "w", stdout);
    IO::readl(n, k);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        IO::readl(x, y);
        if (n <= 20)
            edges[i - 1] = {x, y};
        deg[x]++, deg[y]++;
        AddEdge(x, y);
        AddEdge(y, x);
    }
    if (n <= 19)
    {
        Spj1();
        return 0;
    }
    int cntDegMoreThan1 = 0, maxDeg = 0;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] > 1)
            cntDegMoreThan1++;
        maxDeg = max(maxDeg, deg[i]);
    }
    if (maxDeg <= 2)
    {
        Spj2();
        return 0;
    }
    if (cntDegMoreThan1 == 1)
    {
        Spj3();
        return 0;
    }
    if (k == 0)
    {
        IO::writel(n);
        return 0;
    }
    if (k == 1)
    {
        Spj4();
        return 0;
    }
    return 0;
}
