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
const int MAXN = 100007, Mod = 1e9 + 9;
int a[MAXN];
long long n;
long long power(long long a, long long b)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % Mod;
        a = a * a % Mod;
        b >>= 1;
    }
    return res;
}
int main()
{
    freopen("product.in", "r", stdin);
    freopen("product.out", "w", stdout);
    readi(n);
    for (int i = 1; i <= n; i++)
        readi(a[i]);
    long long ans = 1;
    int public_gcd = a[1];
    for(int i = 2; i <= n; i++)
        public_gcd = __gcd(public_gcd, a[i]);
    for(int i = 1; i <= n; i++)
        a[i] /= public_gcd;
    ans = power(public_gcd, n * (n + 1) / 2);
    for(int i = 1; i <= n; i++)
    {
        int section_gcd = a[i];
        ans = ans * section_gcd % Mod;
        for(int j = i + 1; j <= n; j++)
        {
            section_gcd = __gcd(section_gcd, a[j]);
            if(section_gcd == 1)break;
            ans = ans * section_gcd % Mod;
        }
    }
    writei(ans);
    putchar('\n');
    return 0;
}