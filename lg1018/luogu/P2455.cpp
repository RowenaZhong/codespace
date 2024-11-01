#include <bits/stdc++.h>
using namespace std;
double a[51][51], b[51], c[51], eps = 1e-5;
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            scanf("%lf", *(a + i) + j);
        scanf("%lf", b + i);
    }
    int r = 1, c = 1;
    cerr << __LINE__ << endl;
    for (; c <= n; c++)
    {
        cerr << ":" << c << endl;
        int t = r;
        for (int i = r; i <= n; i++)
            if (fabs(a[i][c]) > fabs(a[t][c]))
                t = i;
        if (fabs(a[t][c]) < eps)
            continue;
        for (int i = 1; i <= n; i++)
            swap(a[t][i], a[r][i]);
        swap(b[t], b[r]);
        for(int i = c + 1; i <= n; i++)
            a[r][i] /= a[r][c];
        b[r] /= a[r][c];
        a[r][c] = 1;
        for (int i = 1; i <= n; i++)
        {
            double d = a[i][c];
            for (int j = c; j <= n; j++)
                a[i][j] -= a[r][j] * d;
            b[i] -= b[r] * d;
        }
        r++;
    }
    if(r != n + 1)
    {
        while(r != n + 1)
        {
            if(fabs(b[r]) < eps)
            {
                puts("-1");
                return 0;
            }
            r++;
        }
        puts("0");
        return 0;
    }
    for(int i = 1; i <= n; i++)
        printf("x%d=%.2lf\n", i, b[i]);
    return 0;
}
