#include <bits/stdc++.h>
using namespace std;
int n, k, q;
const int MAXN = 1e5 + 7, MOD = 1e9 + 7;
int factorial[MAXN], inv_factorial[MAXN];
int exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return r;
}

void init()
{
    factorial[0] = 1;
    for (int i = 1; i < MAXN; i++)
        factorial[i] = 1LL * factorial[i - 1] * i % MOD;
    int x, y;
    exgcd(factorial[MAXN - 1], MOD, x, y);
    inv_factorial[MAXN - 1] = (x % MOD + MOD) % MOD;
    for (int i = MAXN - 2; i >= 0; i--)
        inv_factorial[i] = 1LL * inv_factorial[i + 1] * (i + 1) % MOD;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("sum.in", "r", stdin);
    freopen("sum.out", "w", stdout);
    init();
    cin >> n >> k >> q;
    while (q--)
    {
        int x, r;
        cin >> x >> r;
        int ans = 0;
        if (k == 1)
        {
            if (n >= x)
                ans = factorial[n + 1] * inv_factorial[x + 1] % MOD * inv_factorial[n + 1 - (x + 1)] % MOD; // ans = C(n+1,x+1)
            cout << ans << "\n";
            continue;
        }
        for (int i = r; i <= n; i += k)
        {
            if (x <= i)
            {
                // ans += C(i,x)
                ans = (ans + 1LL * factorial[i] * inv_factorial[x] % MOD * inv_factorial[i - x] % MOD) % MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}