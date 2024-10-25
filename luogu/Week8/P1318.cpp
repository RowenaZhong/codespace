#include <bits/stdc++.h>
using namespace std;
int n;
int a[10005], l[10005], r[10005];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        l[i] = max(l[i - 1], a[i]);
    }
    for (int i = n; i >= 1; i--)
        r[i] = max(r[i + 1], a[i]);
    unsigned long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += max(min(l[i - 1], r[i + 1]) - a[i], 0);
    }
    cout << ans << endl;
    return 0;
}