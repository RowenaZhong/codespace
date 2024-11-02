#include <bits/stdc++.h>
using namespace std;
int MOD = 1e4; // diff 1
long long f[2] = {0, 1};
long long trans[2][2] = {{0, 1}, {1, 1}};
//[F(n) F(n+1)]=[F(n-1) F(n)]*[ 0 1 ]
//                            [ 1 1 ]
void mul_ft()
{
    long long tmp[2];
    tmp[0] = f[0], tmp[1] = f[1];
    f[0] = ((tmp[0] * trans[0][0]) % MOD + (tmp[1] * trans[1][0]) % MOD) % MOD;
    f[1] = ((tmp[0] * trans[0][1]) % MOD + (tmp[1] * trans[1][1]) % MOD) % MOD;
}
void mul_tt()
{
    long long tmp[2][2];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            tmp[i][j] = trans[i][j];
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            trans[i][j] = ((tmp[i][0] * tmp[0][j]) % MOD + (tmp[i][1] * tmp[1][j]) % MOD) % MOD;
}
int solve(unsigned long long n)
{
    f[0] = 0ll;
    f[1] = 1ll;
    trans[0][0] = 0ll;
    trans[0][1] = trans[1][0] = trans[1][1] = 1ll;
    while (n)
    {
        if (n & 1)
            mul_ft();
        mul_tt();
        n >>= 1;
    }
    printf("%lld\n", f[0]);
    return 0;
}
int main()
{
kel:
    unsigned long long n;
    scanf("%lld", &n);
    if (n == -1)
        return 0;
    solve(n);
    goto kel;
}