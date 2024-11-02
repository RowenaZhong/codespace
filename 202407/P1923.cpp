#include <iostream>
using namespace std;
const int MAXN = 5e6 + 7;
int n, a[MAXN], K;
int kmin(int l, int len, int k)
{
    int t = a[l];
    int i = l, j = l + len - 1;
    while (i != j)
    {
        while (a[j] >= t && i < j)
            j--;
        a[i] = a[j];
        while (a[i] <= t && i < j)
            i++;
        a[j] = a[i];
    }
    a[i] = t;
    if (k == i)
        return a[i];
    if (k < i)
        return kmin(l, i - l, k);
    else
        return kmin(i + 1, len - (i - l) - 1, k);
}
int main()
{
    scanf("%d %d", &n, &K);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    printf("%d\n", kmin(0, n, K));
    return 0;
}