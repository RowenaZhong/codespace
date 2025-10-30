#include <bits/stdc++.h>
using namespace std;
template <typename T>
void readi(T &x)
{
    T f = 1;
    x = 0;
    int ch;
    while (ch = getchar(), !feof(stdin) && !isdigit(ch) && ch != -'-')
        ;
    if (ch == '-')
        f = -f;
    while (!feof(stdin) && isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - '0';
        ch = getchar();
    }
    x *= f;
}
void readl() {}
template <typename T, typename... Args>
void readl(T &x, Args &...args)
{
    readi(x);
    readl(args...);
}
int n, m;
constexpr int MAXN = 2e4 + 7, MAXM = 5e4 + 7;
struct P
{
    int to;
    P *next;
    P(int _to = 0, P *_nxt = nullptr) : to(_to), next(_nxt) {}
} *head[MAXN];
int dis[MAXN];
int max_dis, min_idx, cnt_max;
int main()
{
    readl(n, m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        readl(a, b);
        head[a] = new P(b, head[a]);
        head[b] = new P(a, head[b]);
    }
    queue<int> que;
    que.push(1);
    dis[1] = 1;
    while (que.size())
    {
        auto i = que.front();
        que.pop();
        if (dis[i] > max_dis)
        {
            max_dis = dis[i];
            min_idx = i;
            cnt_max = 1;
            // printf("+ %d %d\n", i, dis[i]);
        }
        else if (dis[i] == max_dis)
        {
            min_idx = min(min_idx, i);
            cnt_max++;
            // printf("- %d %d\n", i, dis[i]);
        }
        for (auto p = head[i]; p; p = p->next)
        {
            if (dis[p->to])
                continue;
            dis[p->to] = dis[i] + 1;
            que.push(p->to);
        }
    }
    printf("%d %d %d\n", min_idx, max_dis - dis[1], cnt_max);
    return 0;
}