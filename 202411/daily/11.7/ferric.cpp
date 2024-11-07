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
long long f[2][5002], g[2][5002], a[5002];
const int Mod = 19260817;
int n, k;
void solve()
{
    readi(n);
    readi(k);
    for(int i = 1; i <= n; i++)
        readi(a[i]),f[0][i] = a[i], g[0][i] = 1;
    for(int i = 1; i <= k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            g[i & 1][j] = (g[(i & 1) ^ 1][j - 1] + g[(i & 1) ^ 1][j + 1]) % Mod;
            f[i & 1][j] = f[(i & 1) ^ 1][j - 1] + f[(i & 1) ^ 1][j + 1] + (a[j] * g[i & 1][j]) % Mod;
            f[i & 1][j] %= Mod;
        }
    }
    long long Ans = 0;
    for(int i = 1; i <= n; i++)
        (Ans += f[k & 1][i]) %= Mod;
    writei(Ans);
    putchar('\n');
}
int main()
{
    freopen("ferric.in", "r", stdin);
    freopen("ferric.out", "w", stdout);
    int T;
    T = 1;
    while(T--)
        solve();
    fclose(stdout);
    return 0;
}