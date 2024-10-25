#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7;
char s1[MAXN], s2[MAXN];
int next1[MAXN], next2[MAXN], l1, l2;
int main()
{
    scanf("%s\n%s", s1 + 1, s2 + 1);
    l1 = strlen(s1 + 1);
    l2 = strlen(s2 + 1);
    int j = 0;
    next2[1] = 0;
    for (int i = 2; i <= l2; i++)
    {
        while (j && s2[j + 1] != s2[i])
            j = next2[j];
        if (s2[j + 1] == s2[i])
            j++;
        next2[i] = j;
    }
    j = 0;
    for (int i = 1; i <= l1; i++)
    {
        while (j && s2[j + 1] != s1[i])
            j = next2[j];
        if (s2[j + 1] == s1[i])
            j++;
        next1[i] = j;
        if (j == l2)
            printf("%d\n", i - l2 + 1);
    }
    for (int i = 1; i <= l2; i++)
        printf("%d%c", next2[i], " \n"[i == l2]);
    return 0;
}