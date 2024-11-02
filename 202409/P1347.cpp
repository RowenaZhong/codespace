#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
bool satis[30][30];
int check()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                satis[i][j] |= (satis[i][k] && satis[k][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            if (satis[i][j] && satis[j][i])
                return -1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (satis[i][j] == 0 && satis[j][i] == 0)
                return 0;
    return 1;
}
bool cmp(int a, int b)
{
    return satis[a][b];
}
void dfs()
{
    int *a = new int[n]();
    for (int i = 0; i < n; i++)
        a[i] = i + 1;
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
        putchar(a[i] + 0x40);
}
int main()
{
    scanf("%d %d", &n, &m);
    if (m < n - 1)
    {
        printf("Sorted sequence cannot be determined.\n");
        return 0;
    }
    int flag = 0, keyi = -1;
    for (int i = 1; i <= m; i++)
    {
        char str[4];
        scanf("%s", str);
        satis[str[0] - 0x40][str[2] - 0x40] = true;
        int t = check();
        if (t == -1)
        {
            printf("Inconsistency found after %d relations.\n", i);
            return 0;
        }
        else if (t == 1)
        {
            printf("Sorted sequence determined after %d relations: ", i);
            dfs();
            putchar('.');
            putchar('\n');
            return 0;
        }
    }
    printf("Sorted sequence cannot be determined.\n");
    return 0;
}