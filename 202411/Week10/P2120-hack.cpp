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
const int MAXN = 1e6 + 7;
typedef unsigned long long ull;
typedef long long ll;
int n;
ll x[MAXN], p[MAXN], c[MAXN];
ll sxp[MAXN],sp[MAXN], f[MAXN];
int q[MAXN], l, r;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> x[i] >> p[i] >> c[i];
        sp[i] = sp[i - 1] + p[i];
        sxp[i] = sxp[i - 1] + x[i] * p[i];
    }
    f[1] = (p[1] == 0)? 0 : c[1];
    for(int i = 2; i <= n; i++)
    {
        if(p[i] == 0)
        {
            f[i] = f[i - 1];
            continue;
        }
        f[i] = LONG_LONG_MAX;
        for(int j = 1; j < i; j++)
            f[i] = min(f[i], f[j] + x[i] * (sp[i] - sp[j]) - sxp[i] + sxp[j] + c[i]);
    }
    
    writei(f[n]);
    putchar('\n');
    return 0;
}