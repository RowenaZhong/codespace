#include <bits/stdc++.h>
#include <ctime>
using namespace std;
typedef long double Data;
Data IntegralTest(Data l, Data r, Data (*f)(Data x))
{
    auto mid = (l + r) / 2;
    return (r - l) * (f(l) + 4 * f(mid) + f(r)) / 6;
}
Data Integral(Data l, Data r, Data (*f)(Data x))
{
    auto mid = (l + r) / 2;
    auto integral = IntegralTest(l, r, f);
    auto integralExact = IntegralTest(l, mid, f) + IntegralTest(mid, r, f);
    if (abs(integral - integralExact) < 1e-15)
        return integralExact;
    return Integral(l, mid, f) + Integral(mid, r, f);
}
Data f(Data x)
{
    return 1 / x;
}
Data myln(Data x)
{
    return Integral(1, x, f);
}
Data myiln(Data x)
{
    return Integral(1, x, myln);
}
const Data e = 2.7182818285;
Data Get(Data l, Data r, Data out, Data (*f)(Data x))
{
    for (int i = 1; i <= 100; i++) {
        cerr << i << endl;
        auto mid = (l + r) / 2;
        if (f(mid) < out)
            l = mid;
        else
            r = mid;
    }
    return (l + r) / 2;
}
const Data iln365 = 100.7557013105;
int main()
{
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cout << fixed << setprecision(10) << Get(100, 101, 365, myiln);
    return 0;
}