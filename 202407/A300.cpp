#include <iostream>
#include <climits>
using namespace std;
int N, S;
long long st[5007], sc[5007];
long long dp[5007];
int main()
{
    scanf("%d %d", &N, &S);
    for (int i = 1; i <= N; i++)
    {
        int Ti, Ci;
        scanf("%d %d", &Ti, &Ci);
        st[i] = st[i - 1] + Ti;
        sc[i] = sc[i - 1] + Ci;
    }
    for (int i = 1; i <= N; i++)
    {
        dp[i] = LONG_LONG_MAX;
        for (int j = 0; j < i; j++)
            dp[i] = min(dp[i], dp[j] - (st[i] + S) * sc[j]);
        dp[i] += sc[i] * st[i] + S * sc[N];
    }
    printf("%lld\n", dp[N]);
    return 0;
}