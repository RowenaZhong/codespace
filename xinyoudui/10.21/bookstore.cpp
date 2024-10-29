#include <bits/stdc++.h>
using namespace std;
int T, n, m;
int x[100007], y[100007];

void solve()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d %d", x + i, y + i);
    if (n <= 10 && m <= 10)
    {
        for (int i = 1; i < (1 << m); i++)
        {
            for (int j = 1; j < (1 << m); j++)
            {
                if (i & j)
                    continue;
                int a = 0, b = 0;
                for (int k = 0; k < m; k++)
                {
                    if ((1 << k) & i)
                        a |= (1 << (x[k + 1] - 1)), a |= (1 << (y[k + 1] - 1));
                    if ((1 << k) & j)
                        b |= (1 << (x[k + 1] - 1)), b |= (1 << (y[k + 1] - 1));
                }
                if (a == b)
                {
                    printf("%d %d\n", __builtin_popcount(i), __builtin_popcount(j));
                    for (int k = 0; k < m; k++)
                        if ((1 << k) & i)
                            printf("%d ", k + 1);
                    putchar('\n');
                    for (int k = 0; k < m; k++)
                        if ((1 << k) & j)
                            printf("%d ", k + 1);
                    putchar('\n');
                    return;
                }
            }
        }
    }
    puts("-1");
}
int main()
{
    freopen("bookstore.in", "r", stdin);
    freopen("bookstore.out", "w", stdout);
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}