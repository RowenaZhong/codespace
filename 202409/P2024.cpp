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
        putchar('-'), x = -x;
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
const int MAXN = 5e4 + 7;
int fa[MAXN * 3], n, m;
int getfa(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = getfa(fa[x]);
}
int main()
{
    readi(n);
    readi(m);
    for (int i = 1; i <= n * 3; i++)
    {
        fa[i] = i;
    }
    int Ans = 0;
    while (m--)
    {
        int q, a, b;
        readi(q);
        readi(a);
        readi(b);
        if (a > n || b > n)
        {
            Ans++;
            continue;
        }
        if (q == 1)
        {
            if (getfa(a) == getfa(n + b) || getfa(b) == getfa(n + a))
            {
                Ans++;
            }
            else
            {
                fa[getfa(a)] = getfa(b);
                fa[getfa(n + a)] = getfa(n + b);
                fa[getfa(n + n + a)] = getfa(n + n + b);
            }
        }
        else
        {
            if (getfa(a) == getfa(b) || getfa(a) == getfa(n + b))
                Ans++;
            else
            {
                fa[getfa(a)] = getfa(n + n + b);
                fa[getfa(n + a)] = getfa(b);
                fa[getfa(n + n + a)] = getfa(n + b);
            }
        }
    }
    writei(Ans);
    putchar('\n');
    return 0;
}