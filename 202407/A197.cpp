#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 3;
int v[MAXN], prime[MAXN], cnt;
void Prime(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (v[i] == 0)
            v[i] = i, prime[cnt++] = i;
        for (int j = 0; j < cnt && prime[j] <= v[i] && prime[j] * i <= n; j++)
        {
            v[prime[j] * i] = prime[j];
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    Prime(n);
    for (int i = 0; i < cnt; i++)
    {
        int p = prime[i];
        int _cnt = 0;
        long long l = p;
        while (l <= (long long)n)
        {
            // printf(">%lld\n", l);
            _cnt += n / l;
            l *= p;
        }
        printf("%d %d\n", p, _cnt);
    }
    return 0;
}