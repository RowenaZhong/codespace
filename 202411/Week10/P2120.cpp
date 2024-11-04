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
long double que_k(int p1,int p2)
{
    if(sp[p1] == sp[p2])
    {
        if(f[p1] + sxp[p1] == f[p2] + sxp[p2])return 0;
        else if(f[p1] + sxp[p1] < f[p2] + sxp[p2]) return 1e20;
        return -1e20;
    }
    return (long double)(f[p1] + sxp[p1] - f[p2] - sxp[p2]) / (sp[p1] - sp[p2]);
}
int main()
{
    readi(n);
    for(int i = 1; i <= n; i++)
    {
        readi(x[i]);
        readi(p[i]);
        readi(c[i]);
        sp[i] = sp[i - 1] + p[i];
        sxp[i] = sxp[i - 1] + ll(x[i]) * p[i];
    }
    // f_i = min{ f_j - x_i * sp_j + sxp_j} + x_i * sp_i - sxp_i + c_i;
    // f_j + sxp_i = x_i * sp_j + f_i - x_i * sp_i + sxp_i - c_i

    // X : sp
    // Y : f - sxp
    l = r = 1;
    for(int i = 1; i <= n; i++)
    {
        while(l < r && que_k(q[l], q[l + 1]) <= (long double)x[i])
            l++;
        f[i] = f[q[l]] + x[i] * (sp[i] - sp[q[l]]) - sxp[i] + sxp[q[l]] + c[i];
        while(l < r && que_k(q[r - 1], q[r]) >= que_k(q[r - 1], i))
            r--;
        q[++r] = i;
    }
    ll ans = LONG_LONG_MAX;
    for(int i = n; i && !p[i + 1]; i--)
        ans = min(ans, f[i]);
    writei(ans);
    putchar('\n');
    return 0;
}