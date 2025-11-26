#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20000528;
int inv[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, p;
    cin >> n >> p;
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
        inv[i] = (long long)(p - p / i) * inv[p % i] % p;
    for (int i = 1; i <= n; ++i)
        printf("%d\n", inv[i]);
    return 0;
}