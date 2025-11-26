#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("classic.in", "r", stdin);
    freopen("classic.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 0, now = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= 0)
            now += (1ll << a[i]);
        else
            now -= (1ll << -a[i]);
        ans = max(ans, now);
        if (now < 0)
            now = 0;
    }
    cout << ans << "\n";
    return 0;
}