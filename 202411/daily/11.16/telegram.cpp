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
const int MAXN = 800;
typedef unsigned long long Data;
int n;
Data a[MAXN], ans;
priority_queue<Data, vector<Data>, greater<Data>> q;
const Data SHORT_INTERVAL = 1, LONG_INTERVAL = 2;
int main()
{
    freopen("telegram.in", "r", stdin);
    freopen("telegram.out", "w", stdout);
    readi(n);
    for (int i = 1; i <= n; i++)
        readi(a[i]), q.push(a[i]);
    while (q.size() > 1) {
        Data x = q.top();
        q.pop();
        Data y = q.top();
        q.pop();
        q.push(x + y);
        ans += x * LONG_INTERVAL + y * SHORT_INTERVAL;
    }
    writel(ans);
    return 0;
}