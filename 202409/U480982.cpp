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
int m1[5012], m2[5012], a[5012];
int Ans;
int main()
{
    int n;
    readi(n);
    for (int i = 1; i <= n; i++)
        readi(a[i]);
    for (int i = 1; i <= n; i++)
    {
        m1[i] = 1;
        for (int j = 1; j < i; j++)
        {
            if (a[j] == a[i])
                m2[i] = max(m2[i], m1[j] + 1);
            else
                m1[i] = max(m1[i], m2[j] + 1);
        }
        Ans = max(Ans, m2[i]);
    }
    writei(Ans);
    return 0;
}