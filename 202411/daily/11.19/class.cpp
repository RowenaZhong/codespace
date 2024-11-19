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
const int MAXN = 1e4 + 7;
int n, a[MAXN];
bool check(int k)
{
    int i = 1, j = n, sum = 0;
    while (i < j) {
        if (a[i] + a[j] == k)
            i++, j--;
        else if (a[i] + a[j] < k) {
            i++;
            if ((++sum) > 2)
                return false;
        } else {
            j--;
            if ((++sum) > 2)
                return false;
        }
    }
    if (sum + (j - i) > 2)
        return false;
    return true;
}
inline void solve1()
{
    IO::readi(n);
    for (int i = 1; i <= n; i++)
        IO::readi(a[i]);
    sort(a + 1, a + n + 1);
    if (check(a[1] + a[n]))
        puts("Yes");
    else if (check(a[1] + a[n - 1]))
        puts("Yes");
    else if (check(a[1] + a[n - 2]))
        puts("Yes");
    else if (check(a[2] + a[n]))
        puts("Yes");
    else if (check(a[3] + a[n]))
        puts("Yes");
    else if (check(a[2] + a[n - 1]))
        puts("Yes");
    else
        puts("No");
}

int main()
{
    freopen("class.in", "r", stdin);
    freopen("class.out", "w", stdout);
    int T;
    IO::readi(T);
    while (T--)
        solve1();
    return 0;
}
