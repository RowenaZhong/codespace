#include <iostream>
#include <set>
using namespace std;
int n, m, a[100007];
typedef struct
{
    set<int> arr;
    int first, second;
} node[400007];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    while (m--)
    {
        char str[2];
        scanf("%s", str);
        if (str[0] == 'Q')
        {
            int l, r, k;
            scanf("%d %d %d", &l, &r, &k);
            printf("%d\n", Query(1, l, r, k));
        }
        else
        {
            int x, y;
            scanf("%d %d", &x, &y);
        }
    }

    return 0;
}