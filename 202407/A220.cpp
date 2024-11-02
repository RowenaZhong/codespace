#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5;
int v[MAXN], phi[MAXN];
long long pre[MAXN];
int prime[MAXN], cnt;
int n;
void presolve()
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 0)
        {
            v[i] = i;
            prime[cnt++] = i;
            phi[i] = i - 1;
        }
        for (auto j = 0; j != cnt; j++)
        {
            if ((prime[j]) * i > 1e7)
                break;
            if (v[i] < prime[j])
                break;
            phi[i * prime[j]] = phi[i] * (prime[j] - (v[i] != prime[j]));
            v[i * prime[j]] = prime[j];
        }
        pre[i] = phi[i] + pre[i - 1];
    }
}
int main()
{
    scanf("%d", &n);
    presolve();
    long long Ans = 0ll;
    for (auto i = 0; i != cnt; i++)
    {
        if (prime[i] > n)
            break;
        Ans += (pre[n / prime[i]] << 1) + 1;
    }
    printf("%lld\n", Ans);
    return 0;
}