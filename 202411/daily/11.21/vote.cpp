#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2007;
double p[MAXN];
double a[MAXN][MAXN / 2], b[MAXN][MAXN / 2];
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
    a[0][0] = b[n + 1][0] = 1;
    for (int i = 1; i <= n; i++) {
        a[i][0] = 1;
        for (int j = 1; j <= k / 2; j++)
            a[i][j] = a[i - 1][j - 1] * p[i] + a[i - 1][j] * (1 - p[i]);
    }
    for (int i = n; i >= 1; i--) {
        b[i][0] = 1;
        for (int j = 1; j <= k / 2; j++)
            b[i][j] = b[i + 1][j - 1] * p[i] + b[i + 1][j] * (1 - p[i]);
    }
    double maxn = 0;
    for (int i = 0; i <= n; i++) {
        double sum = 0;
        for (int j = 0; j <= k / 2; j++) {
            sum = max(sum, a[i][j] * b[i + 1][k / 2 - j]);
        }
        maxn = max(maxn, sum);
    }
    printf("%.7lf\n", maxn);
    return 0;
}