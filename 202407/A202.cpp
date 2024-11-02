#include <bits/stdc++.h>
using namespace std;

int main()
{
    int L, T = 0;
    while (1)
    {
        scanf("%d", &L);
        if (!L)
            break;
        printf("Case %d: %d\n", ++T, solve(L));
    }
    return 0;
}