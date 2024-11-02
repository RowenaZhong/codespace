#include <iostream>
#include <cstring>
using namespace std;
int n, m, maxc;
inline int readi()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch) && ch != '-')
        ch = getchar();
    if (ch == '-')
        f = -1, ch = getchar();
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    return x * f;
}
inline void writei(int x)
{
    if (x < 0)
        putchar('-'), x = -x;
    else if (x == 0)
    {
        putchar('0');
        return;
    }
    int t = 1;
    while (t <= x)
        t = (t << 3) + (t << 1);
    t = t / 10;
    while (t)
    {
        putchar(x / t + 0x30);
        x = x % t;
        t = t / 10;
    }
    return;
}
class P
{
public:
    P *next;
    int child;
    int angry;
    P(P *n, int c, int a)
    {
        this->next = n,
        this->child = c,
        this->angry = a;
    }
};
P *e[20007];
int color[20007];
int gang;
bool dfs(int x, int c)
{
    color[x] = c;
    for (P *p = e[x]; p; p = p->next)
        if (p->angry > gang)
            if (color[p->child])
                if (color[p->child] == c)
                    return false;
                else
                    ;
            else if (!dfs(p->child, 3 - c))
                return false;
    return true;
}
bool check(int ang)
{
    gang = ang;
    memset(color, 0x00, sizeof(color));
    for (int i = 1; i <= n; i++)
        if (color[i] == 0)
            if (!dfs(i, 1))
                return false;
    return true;
}
int main()
{
    n = readi();
    m = readi();
    while (m--)
    {
        int a, b, c;
        a = readi();
        b = readi();
        c = readi();
        e[a] = new P(e[a], b, c);
        e[b] = new P(e[b], a, c);
        maxc = max(maxc, c);
    }
    int l = 0, r = maxc;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    writei(l);
    putchar('\n');
    return 0;
}