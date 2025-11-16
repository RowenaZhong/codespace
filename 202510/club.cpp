#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a[4];
int cnt[4], v[4], pre[4] = {0, 3, 1, 2}, nxt[4] = {0, 2, 3, 1};
int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int ans = 0;
        cnt[1] = cnt[2] = cnt[3] = 0;
        a[1].clear();
        a[2].clear();
        a[3].clear();
        for (int i = 1; i <= n; i++)
        {
            cin >> v[1] >> v[2] >> v[3];
            int max_id;
            if (v[1] >= v[2] && v[1] >= v[3])
                max_id = 1;
            else if (v[2] >= v[1] && v[2] >= v[3])
                max_id = 2;
            else
                max_id = 3;
            cnt[max_id]++;
            ans += v[max_id];
            a[max_id].push_back(v[max_id] - max(v[pre[max_id]], v[nxt[max_id]]));
        }
        if (cnt[1] > n / 2)
        {
            sort(a[1].begin(), a[1].end());
            int rest = cnt[1] - n / 2;
            for (int i = 0; i < rest; i++)
                ans -= a[1][i];
        }
        if (cnt[2] > n / 2)
        {
            sort(a[2].begin(), a[2].end());
            int rest = cnt[2] - n / 2;
            for (int i = 0; i < rest; i++)
                ans -= a[2][i];
        }
        if (cnt[3] > n / 2)
        {
            sort(a[3].begin(), a[3].end());
            int rest = cnt[3] - n / 2;
            for (int i = 0; i < rest; i++)
                ans -= a[3][i];
        }
        printf("%d\n", ans);
    }
    return 0;
}