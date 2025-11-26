#include <bits/stdc++.h>
using namespace std;
const int MAXN = 505;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("animal.in", "r", stdin);
    freopen("animal.out", "w", stdout);
    int n, m, T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m;
        vector<int> A(n + 1), B(n + 1);
        vector<double> T(n + 1, 1e18);
        vector<vector<double>> G(n + 1, vector<double>(n + 1, -1));
        bitset<MAXN> informed;
        for (int i = 1; i <= n; i++)
            cin >> A[i];
        for (int i = 1; i <= n; i++)
            cin >> B[i];
        T[m] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (B[i] == B[j])
                    G[i][j] = 0;
                else
                    G[i][j] = double(A[i] - A[j]) / (B[j] - B[i]); // x1 - x2 = (v1 - v2) * t
                G[j][i] = G[i][j];
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j)
                        continue;
                    if (T[i] > T[j] && T[i] >= G[i][j] && G[i][j] >= T[j])
                        T[i] = G[i][j];
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (T[i] < 1e18)
                ans++;
        }
        cout << ans << "\n";
    }
    return 0;
}