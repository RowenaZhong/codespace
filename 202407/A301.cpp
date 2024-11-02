#include <iostream>
#include <climits>
using namespace std;
int N, S, l, r;
const int MAXN = 3e5 + 7;
long long st[MAXN], sc[MAXN], que[MAXN], k[MAXN], dp[MAXN];
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
    k[MAXN - 1] = LONG_LONG_MAX;
    que[r + 1] = MAXN - 1;
    k[0] = LONG_LONG_MIN;
    for (int i = 1; i <= N; i++)
    {
        long long ki = st[i] + S;
        while (ki > k[que[l + 1]])
            l++;
        int j = que[l];
        k[que[l]] = LONG_LONG_MIN;
        dp[i] = dp[j] + st[i] * (sc[i] - sc[j]) + S * (sc[N] - sc[j]);
        k[i] = (dp[i] - dp[que[r]]) / (sc[i] - sc[que[r]]);
        while (k[i] < k[que[r]])
        {
            r--;
            k[i] = (dp[i] - dp[que[r]]) / (sc[i] - sc[que[r]]);
        }
        r++;
        que[r] = i;
        que[r + 1] = MAXN - 1;
    }
    printf("%lld\n", dp[N]);
    return 0;
}