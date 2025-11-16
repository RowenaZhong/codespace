#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int a[MAXN];
long long sum[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i] = a[i] + sum[i - 1];
        }
        for (int i = 1; i < n; i++)
        {
            putchar('0' + (sum[i] * 2 > sum[n]));
        }
        putchar('\n');
    }
    return 0;
}