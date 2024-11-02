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
typedef unsigned long long LDim;
const LDim Mod = 998244353, Div2 = 499122177;
LDim power(LDim a, LDim b, LDim p)
{
    LDim ret = 1;
    while (b)
    {
        if (b & 1)
            (ret *= a) %= p;
        (a *= a) %= p;
        b >>= 1;
    }
    return ret;
}
LDim gcd(LDim a, LDim b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
void solve()
{
    LDim a, b, n, p;
    readi(n);
    readi(a);
    readi(b);
    // a = n - a + 1, b = n - b + 1;
    p = (a + b - 1) % Mod;
    LDim lSquare;
    if (p <= n + 1)
        lSquare = (p - 1) * (p - 2) % Mod * Div2 % Mod;
    else
        lSquare = (n * (n - 1) % Mod + (3 * n - p - 2) % Mod * ((p - n - 1) % Mod) % Mod) % Mod * Div2 % Mod;
    cerr << lSquare << endl;
    p = lSquare * power(n - 1, Mod - 2, Mod) % Mod;
    (++p) %= Mod;
    writei(p);
    putchar('\n');
}
int main()
{
    freopen("score.in", "r", stdin);
    freopen("score.out", "w", stdout);
    int T;
    readi(T);
    while (T--)
    {
        solve();
    }

    return 0;
}