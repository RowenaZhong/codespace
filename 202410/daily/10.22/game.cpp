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
int n, T;
int a[100007], b[100007];
void solve()
{
    readi(n);
    for (int i = 1; i <= n; i++)
        readi(a[i]);
    sort(a + 1, a + n + 1);
    if (a[n / 2] == a[n / 2 + 1])
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == a[n / 2])
                sum++;
        }
        if (sum > n / 2)
            puts("Bob!");
        else
            puts("Alice!");
    }
    else
        puts("Alice!");
}
int main()
{
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    readi(T);
    while (T--)
        solve();
    return 0;
}