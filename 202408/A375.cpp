#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
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

int n;
pair<int, int> bp[101], wp[101];
double dis[101][101]; // wb
int match[101], last[101];
bool vw[101], vb[101];
double lw[101], lb[101], upd[101];
bool equal(double a, double b)
{
    return (a - b) < 1e-6 && (b - a) < 1e-6;
}
bool dfs(int x, int fa)
{
    vw[x] = true;
    for (int y = 1; y <= n; y++)
        if (!vb[y])
        {
            if (equal(lw[x] + lb[y], dis[x][y]))
            {
                vb[y] = true;
                last[y] = fa;
                if (!match[y] || dfs(match[y], y))
                {
                    match[y] = x;
                    return true;
                }
            }
            else if (upd[y] > lw[x] + lb[y] - dis[x][y])
            {
                upd[y] = lw[x] + lb[y] - dis[x][y];
                last[y] = fa;
            }
        }
    return false;
}
int main()
{
    n = readi();
    for (int i = 1; i <= n; i++)
    {
        bp[i].first = readi();
        bp[i].second = readi();
    }
    for (int i = 1; i <= n; i++)
    {
        wp[i].first = readi();
        wp[i].second = readi();
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dis[i][j] = -sqrt((wp[i].first - bp[j].first) * (wp[i].first - bp[j].first) + (wp[i].second - bp[j].second) * (wp[i].second - bp[j].second));
    for (int i = 1; i <= n; i++)
    {
        lw[i] = -(1 << 30);
        for (int j = 1; j <= n; j++)
            lw[i] = max(lw[i], dis[i][j]);
    }
    for (int i = 1; i <= n; i++)
    {
        memset(vw, 0x00, sizeof(vw));
        memset(vb, 0x00, sizeof(vb));
        memset(last, 0x00, sizeof(last));
        for (int i = 1; i <= n; i++)
            upd[i] = 0x7f7f7f7f;
        int st = 0;
        match[0] = i;
        while (match[st])
        {
            double delta = 1 << 30;
            if (dfs(match[st], st))
                break;
            for (int j = 1; j <= n; j++)
                if (!vb[j] && upd[j] < delta)
                    delta = upd[j], st = j;
            for (int j = 1; j <= n; j++)
            {
                if (vw[j])
                    lw[j] -= delta;
                if (vb[j])
                    lb[j] += delta;
                else
                    upd[j] -= delta;
            }
            vb[st] = true;
        }
        while (st)
        {
            match[st] = match[last[st]];
            st = last[st];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        writei(match[i]);
        putchar('\n');
    }
    return 0;
}