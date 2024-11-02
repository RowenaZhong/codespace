#include <iostream>
#include <climits>
using namespace std;
int N, S, l, r;
const int MAXN = 3e5 + 7;
long long st[MAXN], sc[MAXN], que[MAXN], dp[MAXN];
int binsearch(int l, int r, long long k)
{
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (__int128_t(dp[que[mid + 1]]) - dp[que[mid]] <= __int128_t(k) * __int128_t(sc[que[mid + 1]] - sc[que[mid]]))
            l = mid + 1;
        else
            r = mid;
    }
    return que[l];
}
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
    l = r = 0;
    que[l] = 0;
    for (int i = 1; i <= N; i++)
    {
        long long ki = st[i] + S;
        int j = binsearch(l, r, ki);
        dp[i] = dp[j] + st[i] * (sc[i] - sc[j]) + S * (sc[N] - sc[j]);
        while (l < r && __int128_t(dp[i] - dp[que[r]]) * __int128_t(sc[que[r]] - sc[que[r - 1]]) <= __int128_t(dp[que[r]] - dp[que[r - 1]]) * __int128_t(sc[i] - sc[que[r]]))
            r--;
        r++;
        que[r] = i;
    }
    printf("%lld\n", dp[N]);
    return 0;
}