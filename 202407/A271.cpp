#include <iostream>
#include <cstring>
using namespace std;
int N[6];
long long p[31][16][11][8][7];
int main()
{
    int k;
    while (1)
    {
        scanf("%d", &k);
        if (k == 0)
            break;
        memset(N, 0x00, sizeof(N));
        for (int i = 1; i <= k; i++)
            scanf("%d", N + i);
        memset(p, 0x00, sizeof(p));
        p[0][0][0][0][0] = 1;
        for (int a1 = 0; a1 <= N[1]; a1++)
        {
            for (int a2 = 0; a2 <= N[2]; a2++)
            {
                for (int a3 = 0; a3 <= N[3]; a3++)
                {
                    for (int a4 = 0; a4 <= N[4]; a4++)
                    {
                        for (int a5 = 0; a5 <= N[5]; a5++)
                        {
                            if (a1 < N[1])
                                p[a1 + 1][a2][a3][a4][a5] += p[a1][a2][a3][a4][a5];
                            if (a2 < N[2] && a2 < a1)
                                p[a1][a2 + 1][a3][a4][a5] += p[a1][a2][a3][a4][a5];
                            if (a3 < N[3] && a3 < a2)
                                p[a1][a2][a3 + 1][a4][a5] += p[a1][a2][a3][a4][a5];
                            if (a4 < N[4] && a4 < a3)
                                p[a1][a2][a3][a4 + 1][a5] += p[a1][a2][a3][a4][a5];
                            if (a5 < N[5] && a5 < a4)
                                p[a1][a2][a3][a4][a5 + 1] += p[a1][a2][a3][a4][a5];
                        }
                    }
                }
            }
        }
        printf("%lld\n", p[N[1]][N[2]][N[3]][N[4]][N[5]]);
    }
    return 0;
}