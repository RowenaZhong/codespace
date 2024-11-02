#include <bits/stdc++.h>
using namespace std;
int vecs[29];
int N, Ans;
void set1(int &n, int k)
{
    n |= (1 << k);
}
void set0(int &n, int k)
{
    n &= ~(1 << k);
}
bool get(int n, int k)
{
    return (n >> k) & 1;
}
void anti(int &n, int k)
{
    n ^= (1 << k);
}
void solve()
{
    scanf("%d", &N);
    Ans = 1;
    for (int i = 1; i <= N; i++)
        vecs[i] = 0;
    for (int i = 1; i <= N; i++)
    {
        set1(vecs[i], i);
        int t;
        scanf("%d", &t);
        if (t)
            set1(vecs[i], 0);
    }
    for (int i = 1; i <= N; i++)
    {
        int t;
        scanf("%d", &t);
        if (t)
            anti(vecs[i], 0);
    }
    int i, j;
    scanf("%d %d", &i, &j);
    while (i + j)
    {
        set1(vecs[j], i);
        scanf("%d %d", &i, &j);
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
            if (vecs[j] > vecs[i])
                swap(vecs[j], vecs[i]);
        if (vecs[i] == 0)
        {
            printf("%d\n", 1 << (N - i + 1));
            return;
        }
        if (vecs[i] == 1)
        {
            printf("Oh,it's impossible~!!\n");
            return;
        }
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;
            if (get(vecs[j], (int)log2(vecs[i])))
            {
                vecs[j] ^= vecs[i];
            }
        }
    }
    printf("1\n");
    return;
}
int main()
{
    int a = 0;
    int K;
    scanf("%d", &K);
    while (K--)
        solve();
    return 0;
}