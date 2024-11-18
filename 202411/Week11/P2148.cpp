#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 7;
int n, a[MAXN];
void solve()
{
    scanf("%d", &n);
    int ans = 0;
    for (int i = 1; i <= n / 2; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        x--, y--;
        int subAns = 0;
        while ((1 << subAns) & (x | y))
            subAns++;
        ans ^= subAns;
    }
    puts(ans ? "YES" : "NO");
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}