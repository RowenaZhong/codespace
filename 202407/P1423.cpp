#include <bits/stdc++.h>
using namespace std;
double n, n1 = 0;
int main()
{
    cin >> n;
    double step = 2;
    int cnt = 0;
    while (n1 <= n)
    {
        n1 += step;
        step *= 0.98;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}