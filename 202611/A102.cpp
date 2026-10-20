#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int N, F;
int a[MAXN];
double b[MAXN], sum[MAXN];
inline bool check(double avg)
{
    for (int i = 1; i <= N; i++)
        b[i] = a[i] - avg, sum[i] = sum[i - 1] + b[i];
    double min_val = 1e10;
    for (int i = F; i <= N; i++)
    {
        min_val = min(min_val, sum[i - F]);
        if (sum[i] - min_val >= 0)
            return true;
    }
    return false;
}
int main()
{
    scanf("%d %d", &N, &F);
    double l, r = 0;
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", a + i);
    }
    l = -1e6, r = 1e6;
    double eps = 1e-6;
    while (l + eps < r)
    {
        auto mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%d\n", (int)(r * 1000));
}