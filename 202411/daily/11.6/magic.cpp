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
const int maxlen = 1e6 + 7, Mod = 998244353;
long long power(long long a, long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1)
            (ret *= a) %= Mod;
        (a *= a) %= Mod;
        b >>= 1;
    }
    return ret;
}
char str[maxlen];
long long n, len, rest;
int main()
{
    freopen("magic.in", "r", stdin);
    freopen("magic.out", "w", stdout);
    scanf("%lld\n%s", &n, str);
    long long sum = power(26, n);
    len = strlen(str);
    rest = n - len;
    long long ans1 = power(26, rest); // p s_1 s_2 (p s) (AABBBB)
    long long ans2 = power(26, rest); // s_1 s_2 p (s p) (BBBBAA)
    long long ans3 = power(26, rest); // s_1 p s_2
    int cross12 = 1;
    for (long long i = rest; i < len; i++)
    {
        if (str[i] != str[i - rest])
        {
            cross12 = false;
            break;
        }
    }
    writei((sum - ans1 - ans2 + cross12 + Mod * 2ll) % Mod);

    putchar('\n');
    return 0;
}