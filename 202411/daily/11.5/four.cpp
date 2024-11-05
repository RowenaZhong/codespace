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
int a[21];
inline int count4(int x)
{
    int cnt = 0;
    while (x)
    {
        if (x % 10 == 4)
            cnt++;
        x /= 10;
    }
    return cnt;
}
int main()
{
    freopen("four.in", "r", stdin);
    freopen("four.out", "w", stdout);
    int n, ans = 0;
    readi(n);
    assert(n <= 20);
    for (int i = 1; i <= n; i++)
        readi(a[i]);
    for (int k = 1; k < (1 << n); k++)
    {
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            if(k & (1 << i) )
                sum += a[i + 1];
        }
        (ans += count4(sum)) %= 2000019;
    }
    writei(ans);
    putchar('\n');
    return 0;
}