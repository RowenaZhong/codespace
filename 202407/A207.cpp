#include <bits/stdc++.h>
using namespace std;
double P[15][15], vecs[15][15], exv[15];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            scanf("%lf", *(P + i) + j);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            vecs[i][j] = 2 * (P[i][j] - P[0][j]);
            exv[i] += P[i][j] * P[i][j] - P[0][j] * P[0][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (fabs(vecs[j][i]) > 1e-6)
            {
                if (i == j)
                    break;
                for (int k = 1; k <= n; k++)
                    swap(vecs[i][k], vecs[j][k]);
                swap(exv[i], exv[j]);
                break;
            }
        }
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                continue;
            double t = vecs[j][i] / vecs[i][i];
            for (int k = 1; k <= n; k++)
                vecs[j][k] -= vecs[i][k] * t;
            exv[j] -= exv[i] * t;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        exv[i] /= vecs[i][i];
        if (fabs(exv[i] - 0.0000) < 0.0005)
            printf("0.000 ");
        else
            printf("%.3lf ", exv[i]);
    }
    return 0;
}