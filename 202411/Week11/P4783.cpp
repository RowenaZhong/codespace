#include <bits/stdc++.h>
using namespace std;
long long a[400][800];
const int MAXN = 400, MOD = 1e9 + 7;
int n;
long long power(long long a, int b, int p)
{
    long long la = a, ret = 1;
    while (b) {
        if (b & 1)
            (ret *= la) %= p;
        (la *= la) %= p;
        b >>= 1;
    }
    return ret;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            scanf("%lld", &a[i][j]);
        a[i][n + i] = 1ll;
    }
    for (int r = 0; r < n; r++) {
        int t = r;
        for (t = r; t < n; t++)
            if (a[t][r])
                break;
        if (a[t][r] == 0) {
            puts("No Solution");
            return 0;
        }
        for (int i = 0; i < n * 2; i++)
            swap(a[t][i], a[r][i]);
        long long d = a[r][r];
        for (int i = r; i < n * 2; i++)
            a[r][i] = a[r][i] * power(d, MOD - 2, MOD) % MOD;
        for (int j = 0; j < n; j++) {
            if (j == r)
                continue;
            d = a[j][r] * power(a[r][r], MOD - 2, MOD) % MOD;
            for (int i = r; i < n * 2; i++)
                a[j][i] = (a[j][i] - (d * a[r][i]) % MOD + MOD) % MOD;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = n; j < n * 2; j++)
            printf("%lld%c", a[i][j], " \n"[j == n * 2 - 1]);
    return 0;
}
