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
int n;
int a[300005], kmp[300005], f[3000005];
bool dp[1005][1005];
int main()
{
    freopen("bracketplus.in", "r", stdin);
    freopen("bracketplus.out", "w", stdout);
    readi(n);
    for (int i = 1; i <= n; i++)
        readi(a[i]);
    long long ans = 0;

    for (int i = 1; i <= n; i++)
    {
        f[i] = i - 1;
        while (f[i] > 0 && a[i] != a[f[i]])
            f[i] = f[f[i]] - 1;
        if (f[i] > 0)
            kmp[i] = kmp[f[i] - 1] + 1;
        ans += kmp[i];
    }
    writei(ans);
    putchar('\n');
    return 0;
}