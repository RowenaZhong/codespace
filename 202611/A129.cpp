#include <bits/stdc++.h>
using namespace std;
int pa, a[21], stk[21], pstk;
int n, cnt;
void dfs(int i)
{
    if (pa == n)
    {
        s for (int i = 0; i < n; i++)
            printf("%d", a[i]);
        printf("\n");
        cnt++;
        return;
    }
    if (pstk != 0)
    {
        auto k = stk[pstk - 1];
        pstk--;
        a[pa++] = k;
        dfs(i);
        if (cnt == 20)
            return;
        pa--;
        stk[pstk++] = k;
    }
    if (i != n + 1)
    {
        stk[pstk++] = i;
        dfs(i + 1);
        if (cnt == 20)
            return;
        pstk--;
    }
}
int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}