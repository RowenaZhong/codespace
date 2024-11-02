#include <iostream>
using namespace std;
const int MAXN = 1e5 + 7;
char a[MAXN << 2], buf[73];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n / 72 + (n % 72 > 0); i++)
    {
        scanf("%s", a + i * 72);
    }
    for (int i = 0; i < n; i++)
        a[n + i] = a[i];
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        int k;
        for (k = 0; k < n; k++)
            if (a[i + k] != a[j + k])
                break;
        if (k == n)
            break;
        if (a[i + k] < a[j + k])
        {
            j += k + 1;
            if (i == j)
                j++;
        }
        else
        {
            i += k + 1;
            if (i == j)
                i++;
        }
    }
    printf("%d\n", min(i, j));
    return 0;
}