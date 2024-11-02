#include <bits/stdc++.h>
using namespace std;
double a[100][100], b[100];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%lf", *(a + i) + j);
        scanf("%lf", b + i);
    }
    for (int i = 0; i < n; i++)
    {
        int j;
        for (j = i; j < n; j++)
        {
            if (fabs(a[j][i]) > 1e-4)
            {
                if (i == j)
                    break;
                for (int k = 0; k < n; k++)
                    swap(a[i][k], a[j][k]);
                swap(b[i], b[j]);
                break;
            }
        }
        if (j == n)
        {
            printf("No Solution\n");
            return 0;
        }
        for (j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            double t = a[j][i] / a[i][i];
            for (int k = 0; k < n; k++)
                a[j][k] -= a[i][k] * t;
            b[j] -= b[i] * t;
        }
    }
    for (int i = 0; i < n; i++)
    {
        b[i] /= a[i][i];
        printf("%.2lf\n", b[i]);
    }
    return 0;
}