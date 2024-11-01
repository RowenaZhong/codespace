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
const int MAXN = 1000007;
int a[MAXN * 2], n;
long long sum;
int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    readi(n);
    for (int i = 1; i <= n; i++)
    {
        readi(a[i]);
        a[n + i] = a[i];
        sum += a[i];
    }
    if (sum % (n / 2))
    {
        puts("IMPOSSIBLE");
        return 0;
    }
    sum /= (n / 2);
    for (int i = 1; i <= n; i++)
    {
        bool flag1 = true;
        for (int j = 1; j <= n / 2; j++)
        {
            if (a[i + j - 1] + a[i + n - j] != sum)
            {
                flag1 = false;
                break;
            }
        }
        if (flag1)
        {
            writei(i - 1);
            putchar('\n');
            return 0;
        }
    }
    puts("IMPOSSIBLE");
    return 0;
}