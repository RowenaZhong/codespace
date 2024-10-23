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
bool accept[1000007];
int s[1007][1007];
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int main()
{
    freopen("unnamed.in", "r", stdin);
    freopen("unnamed.out", "w", stdout);
    for (int i = 1; i <= 1000; i++)
        for (int j = i * i; j <= 1e6; j *= i)
            accept[j] = true;
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            s[i][j] = s[i][j - 1] + s[i - 1][j] - s[i - 1][j - 1] + accept[i * j / gcd(i, j)];
    cerr << __LINE__ << endl;
    int T;
    readi(T);
    while (T--)
    {
        cerr << T << endl;
        int a, b, c, d;
        readi(a);
        readi(b);
        readi(c);
        readi(d);
        writei(s[b][d] - s[a - 1][d] + s[a - 1][c - 1] - s[b][c - 1]);
        putchar('\n');
    }
    return 0;
}