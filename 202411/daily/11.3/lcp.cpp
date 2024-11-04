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
int n, m;
int s[5005], t[5005], max_s_i;
int s[5005], t[5005], max_s_i = 0; // Initialize max_s_i to 0
int main()
{
    freopen("lcp.in", "r", stdin);
    freopen("lcp.out", "w", stdout);
    readi(n), readi(m);
    for (int i = 1; i <= n; i++)
        readi(s[i]),max_s_i = max(max_s_i, s[i]);
    int tot = 1;
    for(int i = 1; i <= m; i++)
        tot = tot * 5;
    int ans = 0;
    for(int k = 0; k < tot; k++)
    {
        int tk = k;
        for(int i = 1; i <= m; i++)
        {
            t[i] = tk % 5;
            tk /= 5;
        }
        int sum = 0;
        for(int i = 1; i <= m; i++)
        {
            int j = 0;
            for(j = 0; j < n && i + j <= m && s[j + 1] == t[i + j]; j++);
            sum += j;
        }
        ans = max(ans, sum);
    }
    writei(ans);
    putchar('\n');
    return 0;
}
