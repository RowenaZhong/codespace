#include <bits/stdc++.h>
using namespace std;
const int MAXN=3007;
class P{
public:
    P* next;
    int to;
    int weight;
    P(int t, int w, P*n)
    {
        this->to = t;
        this->weight = w;
        this->next = n;
    }
};
P*child[MAXN];
int cost[MAXN];
int dp[MAXN][MAXN];
int n, m;
int dfs(int x)
{
    printf("%d\n",x);
    if(x > n - m)
    {
        dp[x][1] = cost[x];
        return 1;
    }
    int m = 0;
    for(P* p = child[x]; p; p = p -> next)
    {
        int t = dfs(p -> to);
        for(int i = m; i >= 0; i++)
            for(int j = 1; j <= t; j++)
                dp[x][i + j] = max(dp[x][i + j], dp[x][i] + dp[p -> to][j] - p -> weight);
        m = m + t;
    }
    return m;
}
int main()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n - m; i++)
    {
        int t;
        scanf("%d", &t);
        while(t--)
        {
            int a, c;
            scanf("%d %d", &a, &c);
            child[i] = new P(a, c, child[i]);
        }
    }
    for(int i = n - m + 1; i <= n; i++)scanf("%d", cost + i);
    dfs(1);
    for(int i = n - m; i >=0; i--)
        if(dp[1][i] >= 0)
        {
            printf("%d", i);
            break;
        }
    return 0;
}