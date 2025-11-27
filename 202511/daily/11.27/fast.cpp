#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("fast.in", "r", stdin);
    freopen("fast.out", "w", stdout);
    int n, w;
    cin >> n >> w;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if (w == 1)
    {
        int pos = 0, ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans += abs(pos - i);
            pos = i;
            ans += a[i] - i;
            pos = a[i];
        }
        ans += pos - (n + 1);
        cout << ans << endl;
    }
    else if (w == n)
    {
        int maxi = 0;
        for (int i = 1; i <= n; i++)
            maxi = max(maxi, a[i]);
        cout << maxi * 2 - n - 1 << endl;
    }
    else
    {
        int maxi = 0, mini = 1e9 + 7;
        for (int i = 1; i <= n; i++)
            maxi = max(maxi, a[i]), mini = min(mini, a[i]);
        if (mini <= n)
            cout << maxi * 2 - n - 1 << endl;
        else
            cout << maxi * 2 - n + 1 << endl;
    }
    // a[j] = j
    // sum(a[i] - i + |a[i] - j|)
    return 0;
}