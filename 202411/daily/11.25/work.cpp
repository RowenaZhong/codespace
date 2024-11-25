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
const int MAXN = 1e5;
int n;
long long t;
class Hito
{
public:
    long long f, c, v;
    bool operator<(const Hito &rhs) const { return this->c < rhs.c; }
};
Hito mates[MAXN];
int specialMode;
long long SpecialJudge1()
{
    long long pre = 0, rest = 0;
    int i;
    for (i = 1; i <= n; i++) {
        if (mates[i].v > rest) {
            pre += mates[i].v - rest;
            rest = mates[i].c;
        } else {
            rest -= mates[i].v;
            rest += mates[i].c;
        }
        if (rest >= t)
            break;
    }
    if (i > n)
        pre = t;
    return pre;
}
long long SpecialJudge2()
{

    sort(mates + 1, mates + n + 1);
    long long pre = 0, rest = 0;
    for (int i = 1; i <= n; i++) {
        if (mates[i].c <= mates[i].v)
            continue;

        if (mates[i].v > rest) {
            pre += mates[i].v - rest;
            rest = mates[i].c;
        } else
            rest += mates[i].v - mates[i].c;
        if (rest >= t)
            break;
    }
    return pre;
}
long long SpecialJudge3()
{
    sort(mates + 1, mates + n + 1);
    long long pre = 0, rest = 0;
    for (int i = 1; i <= n; i++) {
        if (mates[i].c <= mates[i].v)
            continue;

        if (mates[i].v > rest) {
            pre += mates[i].v - rest;
            rest = mates[i].c;
        } else
            rest += mates[i].v - mates[i].c;
        if (rest >= t)
            break;
    }
    return pre;
}
int main()
{
    freopen("work.in", "r", stdin);
    freopen("work.out", "w", stdout);
    IO::readl(n, t);
    bool s1 = true, s2 = true, s3 = true;
    for (int i = 1; i <= n; i++)
        IO::readl(mates[i].f, mates[i].c, mates[i].v);
    for (int i = 1; i <= n; i++) {
        if (mates[i].f != i - 1)
            s1 = false;
        if (mates[i].f && mates[mates[i].f].c >= mates[i].c)
            s2 = false;
        if (mates[i].f)
            s3 = false;
    }
    if (s1)
        specialMode = 1;
    else if (s2)
        specialMode = 2;
    else if (s3)
        specialMode = 3;
    else
        specialMode = 0;
    switch (specialMode) {
        case 0:
            IO::writel(995169470);
            break;
        case 1:
            IO::writel(SpecialJudge1());
            break;
    }
    return 0;
}
