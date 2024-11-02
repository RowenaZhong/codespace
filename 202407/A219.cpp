#include <bits/stdc++.h>
using namespace std;
unsigned SG[205][205];
void presolve()
{
    for (int i = 2; i <= 200; i++)
    {
        for (int j = i; j <= 200; j++)
        {
            set<unsigned> t;
            for (int s = 2; s <= i - 2; s++)
                t.insert(SG[s][j] ^ SG[i - s][j]);
            for (int s = 2; s <= j - 2; s++)
                t.insert(SG[i][s] ^ SG[i][j - s]);
            for (SG[i][j] = 0u; t.count(SG[i][j]); SG[i][j]++)
                ;
            SG[j][i] = SG[i][j];
        }
    }
}
int main()
{
    presolve();
    int N, M;
    while (scanf("%d %d", &N, &M) == 2)
        puts(SG[N][M] ? "WIN" : "LOSE");
    return 0;
}