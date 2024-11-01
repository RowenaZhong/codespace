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
const int MAXN = 1e3 + 7, Mod = 998244353;
int n, a[MAXN], pre_sum[MAXN];
int main()
{
    freopen("seq.in", "r", stdin);
    freopen("seq.out", "w", stdout);
    readi(n);
    for (int i = 1; i <= n; i++)
    {
        readi(a[i]);
        pre_sum[i] = pre_sum[i - 1] + a[i];
    }
    long long ans = n;
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len <= n + 1; l++)
        {
            int r = l + len - 1, sum_l_to_r = pre_sum[r] - pre_sum[l - 1];
            for (int k = 0; k < (1 << (len - 2)); k++)
            {
                int sum = a[l] + a[r];
                for (int i = 0; i < (len - 2); i++)
                {
                    if ((k >> i) & 1)
                    {
                        sum += a[l + i + 1];
                    }
                }
                if (sum == sum_l_to_r)
                    (ans += 1) %= Mod;
            }
        }
    }
    writei(ans);
    return 0;
}