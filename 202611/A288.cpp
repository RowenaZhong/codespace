#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4000;
int N, B, U[MAXN];
int F[2][MAXN][2];
const int INF = 0x37373737;

int main()
{
    scanf("%d %d", &N, &B);
    for (int i = 1; i <= N; i++)
        scanf("%d", U + i);
    memset(F, 0xC0, sizeof(F));
    F[1][0][0] = 0;
    F[1][1][1] = 0;
    for (int t = 2; t <= N; t++)
    {
        auto t1 = t & 1;
        F[t1][0][0] = max(F[1 - t1][0][0], F[1 - t1][0][1]);
        F[t1][0][1] = -INF;
        for (int n = 1; n <= B; n++)
        {
            F[t1][n][0] = max(F[1 - t1][n][0], F[1 - t1][n][1]);
            F[t1][n][1] = max(F[1 - t1][n - 1][0], F[1 - t1][n - 1][1] + U[t]);
            // printf("day %d\ttot:%d\tns: %d\tslp:%d\n", t, n, F[t1][n][0], F[t1][n][1]);
        }
    }
    auto ans = max(F[N & 1][B][0], F[N & 1][B][1]);

    memset(F, 0xC0, sizeof(F));
    F[1][1][1] = U[1];
    for (int t = 2; t <= N; t++)
    {
        auto t1 = t & 1;
        F[t1][0][0] = max(F[1 - t1][0][0], F[1 - t1][0][1]);
        F[t1][0][1] = -INF;
        for (int n = 1; n <= B; n++)
        {
            F[t1][n][0] = max(F[1 - t1][n][0], F[1 - t1][n][1]);
            F[t1][n][1] = max(F[1 - t1][n - 1][0], F[1 - t1][n - 1][1] + U[t]);
            // printf("day %d\ttot:%d\tns: %d\tslp:%d\n", t, n, F[t1][n][0], F[t1][n][1]);
        }
    }
    ans = max(ans, F[N & 1][B][1]);
    printf("%d\n", ans);
    return 0;
}