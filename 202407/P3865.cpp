#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - 48;
        ch = getchar();
    }
    return x * f;
}
const int MAXN = 1e5 + 5;
int A[MAXN], f[MAXN][21];
int N, M;
void build()
{
    for (int i = 1; i <= N; i++)
        f[i][0] = A[i];
    for (int k = 1; k <= log2(N); k++)
        for (int i = 1; i + (1 << k) - 1 <= N; i++)
            f[i][k] = max(f[i][k - 1], f[i + (1 << (k - 1))][k - 1]);
}
int Query(int l, int r)
{
    int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}
int main()
{
    N = read();
    M = read();
    for (int i = 1; i <= N; i++)
        A[i] = read();
    build();
    while (M--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", Query(l, r));
    }
    return 0;
}