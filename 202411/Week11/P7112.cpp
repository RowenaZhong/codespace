#include <bits/stdc++.h>
using namespace std;
const int MAXN = 600;
int a[MAXN][MAXN];
int n, p;
int main()
{
    scanf("%d %d", &n, &p);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    long long det = 1;
    for (int r = 0; r < n; r++) {
        int t;
        for (t = r; t < n; t++)
            if (a[t][r])
                break;
        if (t == n) {
            puts("0");
            return 0;
        }
        for (int c = 0; c < n; c++)
            swap(a[t][c],a[r][c];
        if(t!=r)
        {
                det *
    }   
    return 0;
    }
