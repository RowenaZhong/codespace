#include <bits/stdc++.h>
using namespace std;
int f[1 << 20][20];
int a[20][20];
int n;
int main()
{
    memset(f, 0x3f, sizeof(f));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", *(a + i) + j);
    f[1][0] = 0;
    for (int k = 0; k < (1 << n); k++)
    {
        for (int i = 0; i < n; i++)
        {
            if ((k >> i) & 1)
            {
                for (int j = 0; j < n; j++)
                {
                    if (!((k >> j) & 1))
                    {
                        f[k | (1 << j)][j] = min(f[k | (1 << j)][j], f[k][i] + a[i][j]);
                    }
                }
            }
        }
    }
    printf("%d\n", f[(1 << n) - 1][n - 1]);
    return 0;
}