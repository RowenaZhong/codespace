#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7, M = 205;
long long n, k, a[MAXN], s[MAXN], f[MAXN], g[MAXN];
long long q[MAXN], h, t;
int pre[MAXN][M];
inline long long x(int i)
{
    return -s[i];
}
inline long long y(int i)
{
    return g[i] - (long long) s[i] * s[i];
}
inline long double calcSlope(int i, int j)
{
    long double dx = x(i) - x(j);
    if (x(i) == x(j))
        return -1e20;
    return (y(i) - y(j)) / dx;
}
int main()
{
    scanf("%lld %lld", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", a + i);
        s[i] = s[i - 1] + a[i];
    }
    for (int i = 1; i <= k; i++) {
        h = t = 0;
        q[0] = 0;
        h = t = 1;
        q[1] = 1;
        memcpy(g, f, sizeof(f));
        for (int j = 1; j <= n; j++) {
            while (h < t && calcSlope(q[h], q[h + 1]) <= (long double) s[i])
                h++;
            f[j] = g[q[h]] + s[q[h]] * (s[j] - s[q[h]]);
            pre[j][i] = q[h];
            while (h < t && calcSlope(q[t - 1], q[t]) >= calcSlope(q[t], j))
                t--;
            q[++t] = j;
        }
    }
    printf("%lld\n", f[n]);
    for (int x = n, i = k; i >= 1; i--)
        x = pre[x][i], printf("%d%c", x, " \n"[i == 1]);
    return 0;
}
