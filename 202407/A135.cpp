#include <cstdio>
#include <iostream>
#include <climits>
int n, m;
const int MAXN = 3e5 + 7;
int A[MAXN], l, r;
long long S[MAXN], Ans = LONG_LONG_MIN;
int que[MAXN];
template <typename T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", A + i);
    for (int i = 1; i <= n; i++)
        S[i] = A[i] + S[i - 1];
    l = 0, r = 0;
    que[r] = S[0];
    for (int i = 1; i <= n; i++)
    {
        if (l <= r)
        {
            if (que[l] < i - m)
                l++;
            if (l <= r)
                Ans = max(Ans, S[i] - S[que[l]]);
        }
        while (l <= r && S[que[r]] > S[i])
            r--;
        que[++r] = i;
    }
    printf("%lld\n", Ans);
    return 0;
}