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
inline int readc()
{
kel:
    int ch = getchar();
    switch (ch)
    {
    case 'X':
        return 0;
    case 'Y':
        return 1;
    case 'D':
        return 2;
    default:
        goto kel;
    }
}
int n;
int a[3002][3002], dp[3002][3002];
int main()
{
    freopen("match.in", "r", stdin);
    freopen("match.out", "w", stdout);
    readi(n);
    long long ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = readc();
            if (a[i][j] == 0)
                dp[i][j] = 1;
            if (a[i][j] == a[i][j - 1] + 1)
                dp[i][j] += dp[i][j - 1];
            if (a[i][j] == 2)
                ans1 += dp[i][j];
        }
    }
    memset(dp, 0x00, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i][j] == 0)
                dp[i][j] = 1;
            if (a[i][j] == a[i - 1][j] + 1)
                dp[i][j] += dp[i - 1][j];
            if (a[i][j] == 2)
                ans2 += dp[i][j];
        }
    }
    writei(max(ans1, ans2));
    putchar('\n');
    return 0;
}