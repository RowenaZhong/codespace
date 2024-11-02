#include <iostream>
using namespace std;
int a[303], n, dp[303][303];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        dp[i][i] = 0;
        a[i] += a[i - 1];
    }
    // a_i=sum{a_k,1<=k<=i}
    for (int s = 1; s < n; s++) // s = r - l
    {
        for (int l = 1; l + s <= n; l++)
        {
            dp[l][l + s] = dp[l][l] + dp[l + 1][l + s];
            for (int k = l + 1; k < l + s; k++)
                dp[l][l + s] = min(dp[l][l + s], dp[l][k] + dp[k + 1][l + s]);
            dp[l][l + s] += a[l + s] - a[l - 1];
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}