#include <bits/stdc++.h>
using namespace std;
int v[1024], phi[1024], prime[1024], prefix[1024], m;
void Phi()
{
    phi[1] = 1;
    for (int i = 2; i <= 1000; i++)
    {
        if (v[i] == 0)
        {
            prime[m++] = i;
            v[i] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; j < m; j++)
        {
            if (prime[j] > v[i])
                break;
            if (prime[j] * i > 1000)
                break;
            phi[prime[j] * i] = phi[i] * ((i % prime[j] == 0) ? prime[j] : (prime[j] - 1));
            v[prime[j] * i] = prime[j];
        }
    }
    return;
}
void Prefix()
{
    prefix[1] = 0;
    for (int i = 2; i <= 1000; i++)
        prefix[i] = prefix[i - 1] + phi[i];
    return;
}
int T = 0;
void solve()
{
    int N;
    scanf("%d", &N);
    printf("%d %d %d\n", ++T, N, 2 * prefix[N] + 3);
}
int main()
{
    Phi();
    Prefix();
    int C;
    scanf("%d", &C);
    while (C--)
        solve();
    return 0;
}