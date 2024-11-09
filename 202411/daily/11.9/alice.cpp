#include <bits/stdc++.h>
using namespace std;
const long long Mod = 1e9 + 7, Div2 = 500000004;
long long QueryM2E0(long long x)
{
    x /= 2;
    x %= Mod;
    //-8n^3-6n^2-n
    return (Mod - (8 * x % Mod * x % Mod * x % Mod + 6 * x % Mod * x % Mod + x) % Mod) % Mod;
}
long long QueryM2E1(long long x)
{
    long long ret = QueryM2E0(x - 1);
    x %= Mod;
    (ret += (2 * x % Mod * x % Mod * x % Mod + x) % Mod) %= Mod;
    return ret;
}
long long power(long long a, long long b)
{
    long long ret = 1;
    while (b)
    {
        if (b & 1)
            (ret *= a) %= Mod;
        (a *= a) %= Mod;
        b >>= 1;
    }
    return ret;
}
int main()
{
    freopen("alice.in", "r", stdin);
    freopen("alice.out", "w", stdout);
    long long l, r;
    scanf("%lld %lld", &l, &r);
    long long yl, yr;
    long long sl = 1, sr = sqrt(r) + 1;
    while (sl != sr)
    {
        long long mid = sl + sr >> 1;
        if (mid * mid - mid + 1 < l)
            sl = mid + 1;
        else
            sr = mid;
    }
    yl = sl;
    sl = 1, sr = sqrt(r) + 1;
    while (sl != sr)
    {
        long long mid = (sl + sr + 1) >> 1;
        if (mid * mid + mid > r)
            sr = mid - 1;
        else
            sl = mid;
    }
    yr = sr;
    long long ansl, ansr;
    ansl = ((yl - 1) & 1) ? QueryM2E1(yl - 1) : QueryM2E0(yl - 1);
    ansr = (yr & 1) ? QueryM2E1(yr) : QueryM2E0(yr);
    long long ansMid = (ansr - ansl + Mod) % Mod;
    long long beginRight = yr * yr + yr + 1;
    ansr = (beginRight + r) % Mod * ((r - beginRight + 1) % Mod) % Mod * Div2 % Mod;
    long long endLeft = yl * yl - yl;
    ansl = (endLeft + l) % Mod * ((endLeft - l + 1) % Mod) % Mod * Div2 % Mod;
    // yl is not odd:  yl - 1 is odd
    if (yl & 1)
        ansl = (Mod - ansl) % Mod;
    // yr is not odd: yr+1 isodd
    if (yr & 1)
        ansr = (Mod - ansr) % Mod;
    long long ans = (ansl + ansr + ansMid) % Mod;
    printf("%lld\n", ans);
    return 0;
}
