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

int main()
{
    freopen("delete.in", "r", stdin);
    freopen("delete.out", "w", stdout);
    int T;
    readi(T);
    while (T--)
    {
        int n, x, cnt_g_1 = 0;
        readi(n);
        while (n--)
        {
            readi(x);
            if (x > 1)
                cnt_g_1++;
        }
        if (cnt_g_1 & 1)
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}