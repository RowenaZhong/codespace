#include <iostream>
using namespace std;
const int MAXN = 6e5 + 7;
int xa = 0, N, M;
int his[MAXN * 25];
int e[MAXN * 25][2], tot = 0;
int roots[MAXN], rtot = 0;
void pre()
{
    int cur = roots[0] = ++tot;
    int p = 23;
    while (p >= 0)
    {
        his[cur] = rtot;
        cur = e[cur][0] = ++tot;
        p--;
    }
    his[cur] = rtot;
}
void Insert(int t)
{
    int pre = roots[rtot++];
    int cur = roots[rtot] = ++tot;
    int p = 23;
    while (p >= 0)
    {
        his[cur] = rtot;
        e[cur][0] = e[pre][0];
        e[cur][1] = e[pre][1];
        pre = e[pre][(t >> p) & 1];
        cur = e[cur][(t >> p) & 1] = ++tot;
        p--;
    }
    his[cur] = rtot;
}
int Query(int l, int r, int m)
{
    int cur = roots[r - 1];
    int Ans = 0;
    for (int p = 23; p >= 0; p--)
    {
        if (e[cur][((m >> p) & 1) ^ 1] && his[e[cur][((m >> p) & 1) ^ 1]] >= l - 1)
            cur = e[cur][((m >> p) & 1) ^ 1], Ans = (Ans << 1) | 1;
        else
            cur = e[cur][(m >> p) & 1], Ans <<= 1;
    }
    return Ans;
}
void dfs(int t)
{
    if (t == 0)
        return;
    printf("dfs(%d)-0-%d;-1-%d\n", t, e[t][0], e[t][1]);
    dfs(e[t][0]);
    dfs(e[t][1]);
}
int main()
{
    pre();
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        int t;
        scanf("%d", &t);
        xa ^= t;
        Insert(xa);
    }
    while (M--)
    {
        char s[2];
        scanf("%s", s);
        if (s[0] == 'A')
        {
            int t;
            scanf("%d", &t);
            xa ^= t;
            Insert(xa);
        }
        else
        {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            printf("%d\n", Query(l, r, xa ^ x));
        }
    }
    return 0;
}