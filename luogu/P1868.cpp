#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXN = 1.5e5 + 7, MAXM = 3e6+7;
int dp[MAXM];
class P{
public:
    int to;
    P* next;
    P(int t, P* n):to(t), next(n){}
};
P* e[MAXM];
int main(){
    scanf("%d", &n);
    int mr = 0;
    while(n--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        e[r] = new P(l - 1, e[r]);
        mr = max(mr, r);
    }
    for(int i = 1; i <= mr; i++)
    {
        dp[i] = dp[i - 1];
        for(P* p = e[i]; p; p = p->next)
        {
            dp[i] = max(dp[i], dp[p->to] + i - p->to);
        }
    }
    printf("%d\n", dp[mr]);
}