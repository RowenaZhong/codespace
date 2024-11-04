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
int x[MAXN], p[MAXN], c[MAXN];
ll sxp[MAXN],sp[MAXN], f[MAXN];
deque<ull> q;
int main()
{
    readi(n);
    for(int i = 1; i <= n; i++)
    {
        readi(x[i]);
        readi(p[i]);
        readi(c[i]);
        sp[i] = sp[i - 1] + p[i];
        sxp[i] = sxp[i - 1] + ull(x[i]) * p[i];
    }
    // f_i = min{ f_j - x_i * sp_j + sxp_j} + x_i * sp_i - sxp_i + c_i;
    // f_j + sxp_i = x_i * sp_j + f_i - x_i * sp_i + sxp_i - c_i
    for(int i = 1; i <= n; i++)
    {
        if(q.size() == 0)
        {
            f[i] = x[i] * sp[i] - sxp[i] + c[i];
            q.push_back(i);
            continue;
        }
        while(q.size() > 1)
        {
            ll px1, px2, py1, py2;
            px1 = sp[q[0]];
            px2 = sp[q[1]];
            py1 = f[q[0]] + sxp[q[0]];
            py2 = f[q[1]] + sxp[q[1]];
            if((py2 - py1) / (px2 - px1) < x[i])
                q.pop_front();
            else
                break;
        }
        f[i] = f[q[0]]  + sxp[q[0]] - sxp[i] + x[i] * sp[i] - x[i] * sp[q[0]] + c[i];
        ll px3 = sp[i], py3 = f[i] + sxp[i];
        while(q.size() > 1)
        {
            ll px1, px2, py1, py2;
            px1 = sp[q[0]];
            px2 = sp[q[1]];
            py1 = f[q[0]] + sxp[q[0]];
            py2 = f[q[1]] + sxp[q[1]];
            if((py2 - py1) / (px2 - px1) > (py3 - py2) / (px3 - px2))
                q.pop_back();
            else
                break;
        }
        q.push_back(i);
    }
    ll ans = LONG_LONG_MAX;
    for(int i = n; i && !p[i + 1]; i--)
        ans = min(ans, f[i]);
    writei(ans);
    putchar('\n');
    return 0;
}