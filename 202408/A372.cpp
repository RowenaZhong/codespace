#include <iostream>
#include <cstring>
using namespace std;
int n, t;
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
P *e[10005];
bool invis[101][101];
int match[101][101];
bool vis[101][101];
bool dfs(int x)
{
    int i = x / 101, j = x % 101;
    if (i > 1 && !vis[i - 1][j] && !invis[i - 1][j])
    {
        vis[i - 1][j] = true;
        if ((match[i - 1][j] == 0 || dfs(match[i - 1][j])))
        {
            match[i - 1][j] = x;
            return true;
        }
    }
    if (j > 1 && !invis[i][j - 1] && !vis[i][j - 1])
    {
        vis[i][j - 1] = true;
        if ((match[i][j - 1] == 0 || dfs(match[i][j - 1])))
        {
            match[i][j - 1] = x;
            return true;
        }
    }
    if (i < n && !invis[i + 1][j] && !vis[i + 1][j])
    {
        vis[i + 1][j] = true;
        if ((match[i + 1][j] == 0 || dfs(match[i + 1][j])))
        {
            match[i + 1][j] = x;
            return true;
        }
    }
    if (j < n && !invis[i][j + 1] && !vis[i][j + 1])
    {
        vis[i][j + 1] = true;
        if ((match[i][j + 1] == 0 || dfs(match[i][j + 1])))
        {
            match[i][j + 1] = x;
            return true;
        }
    }
    return false;
}
int main()
{
    n = readi();
    t = readi();
    while (t--)
    {
        int x, y;
        x = readi();
        y = readi();
        invis[x][y] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (((i + j) & 1) == 0 && !invis[i][j])
            {
                memset(vis, 0x00, sizeof(vis));
                vis[i][j] = true;
                if (dfs(i * 101 + j))
                    ans++;
            }
        }
    }
    writei(ans);
    putchar('\n');
    return 0;
}