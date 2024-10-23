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
class P
{
public:
    int to;
    P *next;
    P(int t, P *n)
    {
        this->to = t;
        this->next = n;
    }
};
const int MAXN = 1e6 + 7;
P *e[MAXN];
int n1, n, m;
int d[MAXN];
void dfs(int x, int fa, int t)
{
    d[x] = t;
    for (P *p = e[x]; p; p = p->next)
    {
        if (p->to == fa)
            continue;
        dfs(p->to, x, t + 1);
    }
}
int main()
{
    freopen("blocktree.in", "r", stdin);
    freopen("blocktree.out", "w", stdout);
    readi(n1);
    readi(n);
    readi(m);
    for (int i = 1; i < n1; i++)
    {
        int u, v;
        readi(u);
        readi(v);
        e[u] = new P(v, e[u]);
        e[v] = new P(u, e[v]);
    }
    dfs(1, 0, 1);
    for (int i =)
        puts("No");
    return 0;
}