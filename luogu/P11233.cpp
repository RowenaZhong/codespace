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
const int MAXN = 2e5 + 7, MAXA = 1e6 + 7;
int T, a[MAXN], n, last_x[MAXA];
long long dp[MAXN];
int main()
{
    readi(T);
    while (T--)
    {
        memset(last_x, 0, sizeof(last_x));
        int t, ans = 0;
        n = 0;
        readi(t);
        while(t--)
        {
            int x;
            readi(x);
            if(n && x == a[n])
                ans++;
            else
                a[++n] = x;
        }
        for(int i = 1; i <= n; i++)
        {
            dp[i] = dp[i - 1];
            if(last_x[a[i]])
                dp[i] = max(dp[i], dp[last_x[a[i]] + 1] + a[i]);
            last_x[a[i]] = i;
        }
        writei(ans + dp[n]);
        putchar('\n');
    }
    return 0;
}