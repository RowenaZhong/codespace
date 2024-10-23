#include <bits/stdc++.h>
using namespace std;
int dp[10][10][10][10][10];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        for (int k = 1; k <= 9; k++)
        {
            dp[(a + k) % 10][b][c][d][e]++;
            dp[a][(b + k) % 10][c][d][e]++;
            dp[a][b][(c + k) % 10][d][e]++;
            dp[a][b][c][(d + k) % 10][e]++;
            dp[a][b][c][d][(e + k) % 10]++;
            dp[(a + k) % 10][(b + k) % 10][c][d][e]++;
            dp[a][(b + k) % 10][(c + k) % 10][d][e]++;
            dp[a][b][(c + k) % 10][(d + k) % 10][e]++;
            dp[a][b][c][(d + k) % 10][(e + k) % 10]++;
        }
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            for (int k = 0; k < 10; k++)
                for (int s = 0; s < 10; s++)
                    for (int t = 0; t < 10; t++)
                        if (dp[i][j][k][s][t] == n)
                            ans++;
    cout << ans << endl;
    return 0;
}