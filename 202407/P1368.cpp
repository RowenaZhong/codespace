#include <iostream>
using namespace std;
const int MAXN = 3e5 + 7;
int n, a[MAXN << 1];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    for (int i = 1; i <= n; i++)
        a[n + i] = a[i];
    int i = 1, j = 2;
    while (i <= n && j <= n)
    {
        int k;
        for (k = 0; k < n; k++)
            if (a[i + k] != a[j + k])
                break;
        if (k == n)
            break;
        if (a[i + k] > a[j + k])
        {
            i += k + 1;
            if (i == j)
                i++;
        }
        else
        {
            j += k + 1;
            if (i == j)
                j++;
        }
    }
    for (int k = min(i, j); k < min(i, j) + n; k++)
        printf("%d ", a[k]);
    putchar('\n');
    return 0;
}