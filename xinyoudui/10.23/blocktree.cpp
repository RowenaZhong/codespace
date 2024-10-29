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
int n1, n, m;
P *e[100005];
int deg[100005], d[100005];
int tt[100005];
int dy[100005];
int ans[100005];
vector<pair<int, int>> e2;
void dfs(int x, int fa, int dep)
{
    tt[dep]++;
    d[x] = dep;
    for (P *p = e[x]; p; p = p->next)
    {
        if (p->to == fa)
            continue;
        dfs(p->to, x, dep + 1);
    }
}
int main()
{
    readi(n1);
    readi(n);
    readi(m);
    for (int i = 1; i < n1; i++)
    {
        int u, v;
        readi(u);
        readi(v);
        deg[u]++, deg[v]++;
        e[u] = new P(v, e[u]);
        e[v] = new P(u, e[v]);
    }
    dfs(1, 0, 1);
    int tot1 = 0, tot2 = 0, flag1 = true, flag2 = true;
    for (int i = 1; i <= n1; i++)
    {
        if (d[i] & 1)
        {
            if (deg[i] == 1)
                flag1 = false;
            tot1++;
        }
        else
        {
            if (deg[i] == 1)
                flag2 = false;
            tot2++;
        }
    }
    int ks = n1 - n;
    if ((!flag1 || tot1 != ks) && (!flag2 || tot2 != ks))
    {
        puts("No");
        return 0;
    }
    int tote = 0;
    if (tot2 == ks)
    {
        for (int i = 1; i <= n1; i++)
            d[i]--;
    }
    for (int i = 1; i <= n1; i++)
    {
        if (d[i] & 1)
            if (deg[i] == 2)
                tote++;
            else
                tote += deg[i];
    }
    if (tote > m)
    {
        puts("No");
        return 0;
    }
    int tt = 0;
    for (int i = 1; i <= n1; i++)
    {
        if (d[i] & 1)
        {
            if (deg[i] != 2)
            {
                P *p = e[i];
                for (p = e[i]; p->next; p = p->next)
                    e2.push_back(make_pair(p->to, p->next->to));
                e2.push_back(make_pair(e[i]->to, p->to));
            }
            else
                e2.push_back(make_pair(e[i]->to, e[i]->next->to));
        }
        else
        {
            tt++;
            ans[i] = tt;
        }
    }
    int mt = m - tote;
    for (int i = 1; i <= n1; i++)
    {
        if (mt == 0)
            break;
        if (d[i] & 1)
        {
            if (deg[i] > 3)
            {
                for (P *p1 = e[i]; p1; p1 = p1->next)
                {
                    if (p1->next == nullptr)
                        continue;
                    for (P *p2 = p1->next->next; p2; p2 = p2->next)
                    {
                        if (p1 == e[i])
                            if (p2->next == nullptr)
                                continue;
                        if (mt)
                        {
                            e2.push_back(make_pair(p1->to, p2->to));
                            mt--;
                        }
                        else
                            break;
                    }
                }
            }
        }
    }
    if (mt != 0)
    {
        puts("No");
        return 0;
    }
    puts("Yes");
    for (int i = 1; i <= n1; i++)
    {
        writei(ans[i]);
        putchar(" \n"[i == n1]);
    }
    for (int i = 0; i < m; i++)
    {
        writei(ans[e2[i].first]);
        putchar(' ');
        writei(ans[e2[i].second]);
        putchar('\n');
    }
    return 0;
}