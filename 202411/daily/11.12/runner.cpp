#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void readi(T &x)
{
    T f = 1;
    x = 0;
    int ch;
    while (ch = getchar(), !feof(stdin) && !isdigit(ch) && ch != '-')
        ;
    if (ch == '-')
        f = -f, ch = getchar();
    while (!feof(stdin) && isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
template <typename T>
inline void writei(T x)
{
    if (x == 0)
    {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p)
    {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}
const int MAXN=1e5+7;
class P{
public:
    int to;
    P* next;
    P(int _to, P* _next):to(_to),next(_next){}
};
P*e[MAXN];
int cntStation[MAXN];
int n,m;
int ans;
int dfs(int x,int fa)
{
    for(P*p=e[x];p;p=p->next)
    {
        if(p->to==fa)continue;
        cntStation[x]+=dfs(p->to,x);
    }
    if(cntStation[x]==1)return 1;
    if(cntStation[x]>1)ans++;
    return 0;
}
int main()
{
    freopen("runner.in", "r", stdin);
    freopen("runner.out", "w", stdout);
    readi(n);
    for(int i=1;i<n;i++)
    {
        int x,y;
        readi(x),readi(y);
        e[x]=new P(y,e[x]);
        e[y]=new P(x,e[y]);
    }
    readi(m);
    for(int i=1;i<=m;i++)
    {
        int x;
        readi(x);
        cntStation[x]=1;
    }
    dfs(1,0);
    writei(ans);
    putchar('\n');
    return 0;
}