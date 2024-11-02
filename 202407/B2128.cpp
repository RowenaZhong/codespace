#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 3;
int v[MAXN], prime[MAXN];
int cnt = 0;
void SiftPrime(int N)
{
    for (int i = 2; i <= N; i++)
    {
        if (v[i] == 0)
            prime[cnt++] = v[i] = i;
        for (int j = 0; j <= cnt && prime[j] <= v[i] && prime[j] * i <= N; j++)
            v[prime[j] * i] = prime[j];
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    SiftPrime(n);
    printf("%d\n", cnt);
    return 0;
}