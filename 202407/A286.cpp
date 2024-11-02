#include <iostream>
using namespace std;
int N, M;
int s[307];
class P
{
public:
    P *next;
    int child;
    P(P *n, int c)
    {
        this->next = n;
        this->child = c;
    }
};
P *e[307];
int F[307][307];
void dfs(int x)
{
    F[x][0] = 0;
    for (P *p = e[x]; p; p = p->next)
    {
        dfs(p->child);
        for (int t = M + 1; t > 0; t--)
        {
            for (int j = 1; j <= t; j++)
            {
                F[x][t] = max(F[x][t], F[x][t - j] + F[p->child][j]);
            }
        }
    }
    for (int t = M + 1; t > 0; t--)
        F[x][t] = F[x][t - 1] + s[x];
}
int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        int k;
        scanf("%d %d", &k, s + i);
        e[k] = new P(e[k], i);
    }
    dfs(0);
    printf("%d\n", F[0][M + 1]);
    return 0;
}