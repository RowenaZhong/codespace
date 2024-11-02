#include <bits/stdc++.h>
using namespace std;
void exgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return;
    }
    exgcd(b, a % b, x, y);
    int t = y;
    y = x - (a / b) * t;
    x = t;
    return;
}
int main()
{
    int a, b, c, d;
    scanf("%d %d", &a, &b);
    exgcd(a, b, c, d);
    printf("%d %d\n", c, d);
    return 0;
}