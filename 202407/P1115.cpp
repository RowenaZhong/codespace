#include <cstdio>
#include <climits>
#define max(a, b) ((a > b) ? a : b)
int main()
{
    int n, a, s = INT_MIN, Ans = INT_MIN;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a);
        s = a + max(s, 0);
        Ans = max(Ans, s);
    }
    printf("%d\n", Ans);
    return 0;
}