#include <iostream>
#include <climits>
using namespace std;
int a[303], n, dpmin[303][303], dpmax[303][303];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        dpmin[i][i] = dpmax[i][i] = 0;
        dpmin[n + i][n + i] = dpmax[n + i][n + i] = 0;
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
        a[n + i] = a[n] + a[i];
    // a_i=sum{a_k,1<=k<=i}
    for (int s = 1; s < n; s++) // s = r - l
    {
        for (int l = 1; l + s < n * 2; l++)
        {
            dpmin[l][l + s] = dpmin[l][l] + dpmin[l + 1][l + s];
            dpmax[l][l + s] = dpmax[l][l] + dpmax[l + 1][l + s];
            for (int k = l + 1; k < l + s; k++)
                dpmin[l][l + s] = min(dpmin[l][l + s], dpmin[l][k] + dpmin[k + 1][l + s]),
                             dpmax[l][l + s] = max(dpmax[l][l + s], dpmax[l][k] + dpmax[k + 1][l + s]);
            dpmin[l][l + s] += a[l + s] - a[l - 1];
            dpmax[l][l + s] += a[l + s] - a[l - 1];
        }
    }
    int minn = INT_MAX;
    int maxn = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        minn = min(minn, dpmin[i][i + n - 1]);
        maxn = max(maxn, dpmax[i][i + n - 1]);
    }
    printf("%d\n%d\n", minn, maxn);
    return 0;
}