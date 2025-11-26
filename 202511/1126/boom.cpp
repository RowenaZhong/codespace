#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("boom.in", "r", stdin);
    freopen("boom.out", "w", stdout);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    bitset<MAXN> clicked;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        int t = i;
        while (clicked[t] == 0)
        {
            clicked[t] = 1;
            t = a[t];
            ans--;
        }
        cout << ans << " \n"[i == n];
    }
    return 0;
}