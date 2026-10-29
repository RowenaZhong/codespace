#include <bits/stdc++.h>
using namespace std;
int nim[201][201];
int main()
{
    int N, M;
    N = M = 200;
    unordered_set<int> S;
    for (int i = 2; i <= N; i++)
        nim[1][i] = 0;
    for (int i = 2; i <= M; i++)
        nim[i][1] = 0;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= M; j++)
        {
            S.clear();
            for (int k = 2; k <= i - 2; k++)
                S.insert(nim[k][j] ^ nim[i - k][j]);
            for (int k = 2; k <= j - 2; k++)
                S.insert(nim[i][k] ^ nim[i][j - k]);
            for (int k = 0;; k++)
                if (!S.count(k))
                {
                    nim[i][j] = k;
                    break;
                }
        }
    }
    while (cin >> N >> M)
    {
        cout << (nim[N][M] ? "WIN\n" : "LOSE\n");
    }
}