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
int main()
{
    int T;
    readi(T);
    while (T--)
    {
        long long n, k, Ans;
        readi(n);
        readi(k);
        if (k == 0)
        {
            writei(1);
            putchar('\n');
            continue;
        }
        Ans = double(n / (k + 1) - n + (n / k * k) - (n % (k + 1) == 0)) / k + 1;
        writei(Ans);
        putchar('\n');
    }
}