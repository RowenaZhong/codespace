#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2007;
double p[MAXN];
int main()
{
    freopen("vote.in", "r", stdin);
    freopen("vote.out", "w", stdout);
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", p + i);
    }
    sort(p + 1, p + n + 1);
    if (n == 2 && k == 2) {
        printf("%.6lf", p[1] + p[2] - 2 * p[1] * p[2]);
        return 0;
    }
    return 0;
}