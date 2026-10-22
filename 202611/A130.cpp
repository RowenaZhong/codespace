#include <bits/stdc++.h>
using namespace std;
const int MAXN = 6e4 + 1;
long long f[MAXN];
int main()
{
    f[0] = 1;
    f[1] = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            f[i] += f[j - 1] * f[i - j];
        }
    }
    cout << f[n] << endl;
    return 0;
}