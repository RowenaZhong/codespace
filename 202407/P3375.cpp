#include <iostream>
#include <cstring>
using namespace std;
const int MAXN = 1e6 + 7;
char s1[MAXN], s2[MAXN];
int nxt[MAXN], f[MAXN];
int main()
{
    scanf("%s\n%s", s1 + 1, s2 + 1);
    nxt[1] = 0;
    int n = strlen(s2 + 1);
    for (int i = 2, j = 0; s2[i] != 0x00; i++)
    {
        while (j > 0 && s2[j + 1] != s2[i])
            j = nxt[j];
        if (s2[j + 1] == s2[i])
            j++;
        nxt[i] = j;
    }
    for (int i = 1, j = 0; s1[i] != 0x00; i++)
    {
        while (j > 0 && (j == n || s2[j + 1] != s1[i]))
            j = nxt[j];
        if (s2[j + 1] == s1[i])
            j++;
        f[i] = j;
        if (f[i] == n)
            printf("%d\n", i - n + 1);
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", nxt[i]);
    putchar('\n');
    return 0;
}