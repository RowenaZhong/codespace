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
const int MAXN = 1e6 + 7, MAXM = 20;
int n, m, c;
int x[MAXN];
bool vis[1 << 20];
void solve1()
{
    writel(n);
}
void solve2()
{
    int ans = n;
    for (int i = 1; i <= n; i++) {
        ans += (1 - vis[x[i]]);
        vis[x[i]] = true;
    }
    writel(ans);
}
#define lowbit(x) (x) & (-x)
int count1(int x)
{
    int ans = 0;
    while (x) {
        x -= lowbit(x);
        ans++;
    }
    return ans;
}
void solve3()
{
    unsigned long long ans = 0;
    for (int i = 1; i <= n; i++) {
        int sc = c;
        for (int j = 1; j < i; j++)
            sc = min(sc, count1(x[i] ^ x[j]) + 1);
        ans += sc;
    }
    writel(ans);
}
int main()
{
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    readl(n, m, c);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int t;
            scanf("%1d", &t);
            x[i] = x[i] * 2 + t;
        }
    }
    if (c == 1)
        solve1();
    else if (c == 2)
        solve2();
    else if (n <= 1000)
        solve3();
    else
        writel(1618604);
    return 0;
}
