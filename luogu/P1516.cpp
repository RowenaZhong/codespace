#include <bits/stdc++.h>
using namespace std;
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
void exgcd(int a, int b, int &x, int &y, int r)
{
    if (b == 1)
    {
        x = 0;
        y = r;
        return;
    }
    int tx, ty;
    exgcd(b, a % b, tx, ty, r);
    x = ty;
    y = tx - a / b * ty;
}
int main()
{
    int x, y, m, n, L;
    cin >> x >> y >> m >> n >> L;
    unsigned long long a, b;
    a = m - n;
    b = y - x;
    a = (a + L) % L;
    b = (b + L) % L;
    auto g = gcd(a, b);
    if (L % g != 0)
    {
        puts("Impossible");
        return 0;
    }
    a /= g, b /= g, L /= g;
    int t, q;
    exgcd(a, L, t, q, b);
    printf("%llu\n", ((unsigned long long)t + L) % L);
    return 0;
}