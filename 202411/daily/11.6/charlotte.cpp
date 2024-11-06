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
    freopen("charlotte.in", "r", stdin);
    freopen("charlotte.out", "w", stdout);
    int T;
    readi(T);
    while (T--)
    {
        int n;
        readi(n);
        int x1 = 0, y1 = 0, t1 = 0;
        bool possible = true;
        while (n--)
        {
            int t, x, y;
            readi(t), readi(x), readi(y);
            int dis = abs(y - y1) + abs(x - x1);
            int interval = t - t1;
            if (dis > interval || (interval % 2 != dis % 2))
                possible = false;
            x1 = x, y1 = y, t1 = t;
        }
        puts(possible ? "Yes" : "No");
    }
    return 0;
}