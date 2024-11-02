#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r;
template <typename T>
T gcd(T a, T b)
{
    while (b)
    {
        T r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void exgcd(ll a, ll b, ll &x, ll &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, y, x);
    y -= a / b * x;
}
int main()
{
    ll x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    long long a, b;
    a = m - n;
    b = y - x;
    if (a < 0)
        a = -a, b = -b;
    // a = (a + L) % L;
    // b = (b + L) % L;
    ll g = gcd(a, L);
    if (b % g != 0)
    {
        puts("Impossible");
        return 0;
    }
    ll t, q;
    exgcd(a, L, t, q);
    printf("%lld\n", (t * (b / g) % (L / g) + (L / g)) % (L / g));
    return 0;
}