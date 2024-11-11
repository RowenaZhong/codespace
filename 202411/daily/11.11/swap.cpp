#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1;
int m;
vector<ll> pl[10];
#define int long long
ll p10[21];
signed main()
{
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    cin >> s1 >> m;
    int n = s1.size();
    s1 = " " + s1;
    p10[0] = 1;
    for (int i = 1; i <= 18; i++)
        p10[i] = p10[i - 1] * 10;
    ll sd = 0;
    ll now1, now2;
    for (int i = 9; i >= 1; i--) {
        for (int j = 1; j <= n; j++)
            if (s1[j] == i + '0')
                pl[i].push_back(j);
        for (int j = 0; j < pl[i].size(); j++) {
            now1 = now2 = 0;
            for (int k = sd + 1; k <= pl[i][j]; k++)
                now1 = now1 * 10 + s1[k] - '0';
            now2 = i;
            for (int k = sd + 1; k < pl[i][j]; k++)
                now2 = now2 * 10 + s1[k] - '0';
            if ((now2 - now1) * p10[n - pl[i][j]] < m * (pl[i][j] - sd - 1)) {
                for (int i = 1; i <= n; i++)
                    cout << s1[i];
                return 0;
            }
            sd++;
            for (int k = pl[i][j]; k >= sd + 1; k--)
                s1[k] = s1[k - 1];
            s1[sd] = i + '0';
        }
    }
    for (int i = 1; i <= n; i++)
        cout << s1[i];
    return 0;
}
