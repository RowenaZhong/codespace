#include <iostream>
using namespace std;
int n, a[17], last[17], pnext[17];
int f()
{
    int tot = 0;
    for (int i = pnext[0]; pnext[i] != 0; i = pnext[i])
        if (a[i] + 1 != a[pnext[i]])
            tot++;
    return (tot + 2) / 3;
}
int depth;
bool dfs(int dep)
{
    // printf("%d | ", dep);
    // for (int i = pnext[0]; i != 0; i = pnext[i])
    //     printf("%d ", a[i]);
    // printf("\n");
    if (dep + f() > depth)
        return false;
    if (f() == 0)
        return true;
    for (int l = pnext[0]; l != 0; l = pnext[l])
    {
        for (int r = l; r != 0; r = pnext[r])
        {
            // cut [l,r] to a new place
            for (int s = 0; pnext[s] != l; s = pnext[s])
            {
                int fore = last[l];
                last[pnext[r]] = fore;
                pnext[fore] = pnext[r];
                last[l] = s;
                pnext[r] = pnext[s];
                last[pnext[s]] = r;
                pnext[s] = l;
                if (dfs(dep + 1))
                    return true;
                last[pnext[r]] = s;
                pnext[s] = pnext[r];
                pnext[r] = pnext[fore];
                last[l] = fore;
                pnext[fore] = l;
                last[pnext[r]] = r;
            }
            for (int s = pnext[r]; s != 0; s = pnext[s])
            {
                int fore = last[l];
                last[pnext[r]] = fore;
                pnext[fore] = pnext[r];
                last[l] = s;
                pnext[r] = pnext[s];
                last[pnext[s]] = r;
                pnext[s] = l;
                if (dfs(dep + 1))
                    return true;
                last[pnext[r]] = s;
                pnext[s] = pnext[r];
                pnext[r] = pnext[fore];
                last[l] = fore;
                pnext[fore] = l;
                last[pnext[r]] = r;
            }
        }
    }
    return false;
}
void solve()
{
    scanf("%d", &n);
    int t;
    pnext[0] = 1;
    last[0] = n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        pnext[i] = i + 1;
        last[i] = i - 1;
    }
    pnext[n] = 0;
    last[1] = 0;
    for (depth = f(); depth <= 4; depth++)
    {
        if (dfs(0))
        {
            printf("%d\n", depth);
            break;
        }
    }
    if (depth == 5)
        printf("5 or more\n");
}
int main()
{
    // LuoguP10488 AcWing180
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}