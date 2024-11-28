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
int n;
int l, r, u, d;
typedef struct
{
    int x, y;
} COORD;
COORD positions[105];
inline bool IsSafe(COORD pos)
{
    return pos.x >= l && pos.x <= r && pos.y <= d && pos.y >= u;
}
inline int CalcDistance(COORD pos1, COORD pos2)
{
    return abs(pos1.x - pos2.x) + abs(pos1.y - pos2.y);
}
inline int CalcDistanceFromSafeReact(COORD pos)
{
    if (pos.x >= l && pos.x <= r)
        if (pos.y <= d && pos.y >= u)
            return 0;
        else
            return min(abs(pos.y - d), abs(pos.y - u));
    else if (pos.y <= d && pos.y >= u)
        return min(abs(pos.x - l), abs(pos.x - r));
    else
        return min({CalcDistance(pos, (COORD){l, d}),
                    CalcDistance(pos, (COORD){l, u}),
                    CalcDistance(pos, (COORD){r, d}),
                    CalcDistance(pos, (COORD){r, u})});
}
void solve()
{
    IO::readl(l, u, r, d);
    for (int i = 0; i <= n; i++)
        IO::readl(positions[i].x, positions[i].y);
    unsigned long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (IsSafe(positions[i - 1]))
            if (IsSafe(positions[i]))
                continue;
            else
                ans += CalcDistanceFromSafeReact(positions[i]);
        else if (IsSafe(positions[i]))
            ans += CalcDistanceFromSafeReact(positions[i - 1]) - 1;
        else
            ans += min(CalcDistanceFromSafeReact(positions[i - 1]) + CalcDistanceFromSafeReact(positions[i]) - 1, CalcDistance(positions[i - 1], positions[i]));
    }
    IO::writel(ans);
}
int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    while (IO::readi(n), n)
        solve();
    return 0;
}
