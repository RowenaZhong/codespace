#include <bits/stdc++.h>
using namespace std;
int a[102][102];
const int BLANK = 0;
const int WHITE = 1;
const int BLACK = 2;
inline int getc_legal()
{
kel:
    int ch = getchar();
    switch (ch)
    {
    case 'X':
        return BLANK;
    case '0':
        return WHITE;
    case '1':
        return BLACK;
    default:
        goto kel;
    }
}
int d[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
void dfs(int x, int y)
{
    a[x][y] = BLANK;
    for (int k = 0; k < 4; k++)
        if (a[x + d[k][0]][y + d[k][1]] != BLANK)
            dfs(x + d[k][0], y + d[k][1]);
}
void solve()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            a[i][j] = getc_legal();
        }
    }
    int xsum = 0, cnt_illegal_black = 0, cnt_neighbor, cnt_block = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            switch (a[i][j])
            {
            case WHITE:
                xsum ^= 1;
                break;
            case BLACK:
                cnt_neighbor = 0;
                for (int k = 0; k < 4; k++)
                    if (a[i + d[k][0]][j + d[k][1]] != BLANK)
                        cnt_neighbor++;
                if (cnt_neighbor == 1)
                    cnt_illegal_black++;
                break;
            default:
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] != BLANK)
                dfs(i, j), cnt_block++;
        }
    }
    if (xsum == 1 && cnt_block == 1 && cnt_illegal_black <= 1)
        puts("YES");
    else
        puts("NO");
}
int main()
{
    freopen("chess.in", "r", stdin);
    freopen("chess.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }
    return 0;
}