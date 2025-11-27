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
const int MAXN = 1e5 + 7;
// const int MAXN = 1e3 + 7;
int t, n;
bool a[MAXN], b[MAXN];
int ea[MAXN][3], eb[MAXN][3];
int cntA, cntB;
void solve()
{
    IO::readi(n);
    cntA = cntB = 1;
    int tmp;

    for (int i = 1; i <= n; i++)
        a[i] = b[i] = false;
    memset(ea, 0x00, sizeof(ea));
    memset(eb, 0x00, sizeof(eb));
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d", &tmp);
        a[i] = (tmp == 1);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d", &tmp);
        b[i] = (tmp == 1);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d", &tmp);
        if (!tmp)
        {
            cntA++;
            ea[cntA][a[i]] = 1;
            ea[cntA][2] = 1;
            cntA++;
        }
        else
            ea[cntA][a[i]]++, ea[cntA][2]++;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%1d", &tmp);
        if (!tmp)
        {
            cntB++;
            eb[cntB][b[i]] = 1;
            eb[cntB][2] = 1;
            cntB++;
        }
        else
            eb[cntB][b[i]]++, eb[cntB][2]++;
    }
    auto pA = 1, pB = 1;
    auto ans = 0;
    for (auto i = 1; i <= n; i++)
    {
        while (ea[pA][2] == 0)
            pA++;
        while (eb[pB][2] == 0)
            pB++;
        ea[pA][2]--;
        eb[pB][2]--;
        if (ea[pA][0] && eb[pB][0])
        {
            ea[pA][0]--;
            eb[pB][0]--;
            ans++;
        }
        else if (ea[pA][1] && eb[pB][1])
        {
            ea[pA][1]--;
            eb[pB][1]--;
            ans++;
        }
    }
    IO::writel(ans);
}
int main()
{
    IO::readi(t);
    while (t--)
        solve();
    return 0;
}
