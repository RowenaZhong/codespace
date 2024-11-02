#include <bits/stdc++.h>
using namespace std;
typedef long long Number;
void exgcd(Number a, Number b, Number &c, Number &d)
{
    if (b == 0)
    {
        c = 1;
        d = 0;
        return;
    }
    exgcd(b, a % b, c, d);
    Number t = d;
    d = c - a / b * t;
    c = t;
}
int main()
{
    Number a, b, x, p;
    cin >> a >> b;
    exgcd(a, b, x, p);
    if (x < 0)
        x = x + ((-x) / b + 2) * b;
    cout << x % b << endl;
    return 0;
}