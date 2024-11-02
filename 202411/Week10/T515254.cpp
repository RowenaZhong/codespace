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
const int MAXN = 2e5 + 7;
char str[MAXN];
int lasting_equal[MAXN];
int lasting_up[MAXN];
int lasting_down[MAXN];
int main()
{
    int T;
    readi(T);
    while (T--)
    {
        int n;
        readi(n);
        scanf("%s", str + 1);
        long long ans(0);
        for (int i = 2; i <= n; i++)
        {
            switch (str[i - 1])
            {
            case '=':
                lasting_equal[i] = lasting_equal[i - 1] + 1;
                lasting_up[i] = lasting_down[i] = 0;
                break;
            case '>':
                lasting_equal[i] = 0;
                lasting_up[i] = 0;
                lasting_down[i] = lasting_down[i - 1 - lasting_equal[i - 1]] + lasting_equal[i - 1] + 1;
                break;
            case '<':
                lasting_equal[i] = 0;
                lasting_down[i] = 0;
                lasting_up[i] = lasting_up[i - 1 - lasting_equal[i - 1]] + lasting_equal[i - 1] + 1;
                break;
            default:
                break;
            }
            ans += lasting_up[i - lasting_equal[i]] + lasting_down[i - lasting_equal[i]];
        }
        writei(ans);
        putchar('\n');
    }
    return 0;
}