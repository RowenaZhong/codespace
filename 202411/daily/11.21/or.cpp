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
typedef unsigned long long Data;
int T;
Data l, r;
void solve1()
{
    auto ans = Data();
    for (Data i = 1; i < 256; i++) {
        auto sum = Data();
        for (Data j = l; j <= r; j++)
            if (!(j & (~i)))
                sum |= j;
        if (sum == i)
            ans++;
    }
    IO::writel(ans);
}
void solve2()
{
    auto len = r - l + 1;
    auto ansSet = set<Data>();
    for (Data k = 1; k < (1 << len); k++) {
        auto sum = Data();
        for (Data i = 0; i < len; i++) {
            if (k & (1 << i))
                sum |= (l + i);
        }
        ansSet.insert(sum);
    }
    IO::writel(ansSet.size());
}
int main()
{
    freopen("or.in", "r", stdin);
    freopen("or.out", "w", stdout);
    IO::readi(T);
    while (T--) {
        IO::readl(l, r);
        if (r < 256)
            solve1();
        else if (r - l <= 5)
            solve2();
    }
}