#include <bits/stdc++.h>
using namespace std;
int R, C, A, B;
int a[502][502], s[502][502];
bool check(int x)
{
    int rowcnt = 0, lastrow = 0;
    for (int r = 1; r <= R; r++)
    {
        int colcnt = 0, lastcol = 0;
        for (int c = 1; c <= C; c++)
        {
            if (s[r][c] - s[r][lastcol] - s[lastrow][c] + s[lastrow][lastcol] >= x)
            {
                colcnt++;
                lastcol = c;
            }
        }
        if (colcnt >= B)
            rowcnt++, lastrow = r;
    }
    return rowcnt >= A;
}
int main()
{
    scanf("%d %d %d %d", &R, &C, &A, &B);
    for (int i = 1; i <= R; i++)
    {
        for (int j = 1; j <= C; j++)
        {
            scanf("%d", *(a + i) + j);
            s[i][j] = a[i][j] + s[i - 1][j] - s[i - 1][j - 1] + s[i][j - 1];
        }
    }
    int l = 1, r = s[R][C];
    while (l != r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    printf("%d\n", l);
    return 0;
}