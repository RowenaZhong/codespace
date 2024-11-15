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
    while (!feof(stdin) && isdigit(ch)) {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
inline void readl() {}
template <typename T, typename... Args>
inline void readl(T &x, Args &...args)
{
    readi(x);
    readl(args...);
}
template <typename T>
inline void writei(T x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p) {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}
inline void writel() {}
template <typename T, typename... Args>
inline void writel(T x, Args... args)
{
    writei(x);
    putchar(" \n"[sizeof...(args) == 0]);
    writel(args...);
}
const int MAXN=1e5+7;
int n,m,r,p;
class P{
public:
    int ver;
    P*next;
    P(int ver,P*next):ver(ver),next(next){}
}
int a[MAXN],fa[MAXN],hson[MAXN],size[MAXN],top[MAXN];
P *e[MAXN];
void dfs1(int u, int f)
{
    size[u]=1;
    fa[u]=fa;
    for(P*p=e[u];p;p=p->next)
        if(p->ver!=f)
        {
            dfs1(p->ver,u);
            size[u]+=size[p->ver];
            if(!hson[u]||size[p->ver]>size[hson[u]])
                hson[u]=p->ver;
        }
}
void dfs2(int u, int t)
{
    top[u]=t;
    if(!hson[u])
        return;
    dfs2(hson[u],t);
    for(P*p=e[u];p;p=p->next)
        if(p->ver!=fa[u]&&p->ver!=hson[u])
            dfs2(p->ver,p->ver);
}
void AddPath(int x,int y,int z)
{

}
int main()
{
    readl(n,m,r,p);
    return 0;
    for(int i=1;i<=n;i++)
        readi(a[i]);

}