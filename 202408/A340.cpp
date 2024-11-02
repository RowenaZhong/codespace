#include <iostream>
#include <queue>
using namespace std;
int n, p, k;
class P
{
public:
    int child;
    int weight;
    P *next;
    P(P *n, int c, int w)
    {
        this->child = c;
        this->next = n;
        this->weight = w;
    }
};
inline int readi()
{
    char ch;
    do
    {
        ch = getchar();
    } while (!isdigit(ch) && ch != '-');
    int ret = 0, f;
    if (ch == '-')
        f = -1, ch = getchar();
    else
        f = 1;
    while (isdigit(ch))
    {
        ret = (ret << 3) + (ret << 1) + ch - 0x30;
        ch = getchar();
    }
    return ret * f;
}
inline void writei(int i)
{
    if (i < 0)
        putchar('-'), i = -i;
    if (i == 0)
        putchar('0');
    else
    {
        int t = 1;
        while (t <= i)
            t = (t << 3) + (t << 1);
        t /= 10;
        while (t > 0)
        {
            putchar(i / t + 0x30);
            i %= t;
            t /= 10;
        }
    }
}
P *e[1001];
bool vis[1001];
int bfs(int l)
{
    for (int i = 1; i <= n; i++)
        vis[i] = false;
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(1, 0));
    while (dq.size())
    {
        pair<int, int> t = dq.front();
        dq.pop_front();
        if (vis[t.first])
            continue;
        vis[t.first] = true;
        // printf("%d >", t.first);
        if (t.first == n)
            return t.second;
        for (P *p = e[t.first]; p; p = p->next)
            if (p->weight > l) //+1
                               // printf(" 1.%d", p->child),
                dq.push_back(make_pair(p->child, t.second + 1));
            else
                // printf(" 0.%d", p->child),
                dq.push_front(make_pair(p->child, t.second));
    }
    return -1;
}
int bq()
{
    int l = 0, r = 1e6;
    if (bfs(r) == -1)
        return -1;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (bfs(mid) <= k)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
int main()
{
    n = readi();
    p = readi();
    k = readi();
    while (p--)
    {
        int a, b, l;
        a = readi();
        b = readi();
        l = readi();
        e[a] = new P(e[a], b, l);
        e[b] = new P(e[b], a, l);
    }
    writei(bq());
    putchar('\n');
    return 0;
}