#include <iostream>
#include <cstring>
using namespace std;
short row[9];
short col[9];
short squ[3][3];
int vis[9][9];
short count1[1 << 9];
inline int countit(short t)
{
    return count1[t >> 1];
}
inline void setit(short *s, int l)
{
    (*s) |= 1 << l;
}
inline void unsetit(short *s, int l)
{
    (*s) &= ~(1 << l);
}
inline bool getit(short s, int l)
{
    return (s >> l) & 1;
}
inline int read()
{
    int ch = getchar();
    if (!isdigit(ch) && ch != 'e' && ch != '.')
        return read();
    return ch;
}
bool dfs()
{
    int r = -1, c = -1, maxn = 0;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!vis[i][j])
            {
                int t = countit(row[i] | col[j] | squ[i / 3][j / 3]);
                if (t > maxn)
                {
                    maxn = t;
                    r = i;
                    c = j;
                }
            }
        }
    }
    // printf("(%d, %d) = %d\n", r, c, maxn);
    if (maxn == 0)
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
                printf("%d ", vis[i][j]);
            putchar('\n');
        }
        return true;
    }
    if (maxn == 9)
        return false;
    short t = row[r] | col[c] | squ[r / 3][c / 3];
    for (int k = 1; k <= 9; k++)
    {
        if (getit(t, k))
            continue;
        setit(row + r, k);
        setit(col + c, k);
        setit(squ[r / 3] + (c / 3), k);
        vis[r][c] = k;
        if (dfs())
            return true;
        vis[r][c] = 0;
        unsetit(row + r, k);
        unsetit(col + c, k);
        unsetit(squ[r / 3] + (c / 3), k);
    }
    return false;
}
int main()
{
    for (int i = 1; i < (1 << 9); i++)
        count1[i] = count1[i >> 1] + (i & 1);
    // while (1)
    // {
    memset(row, 0x00, sizeof(row));
    memset(col, 0x00, sizeof(col));
    memset(squ, 0x00, sizeof(squ));
    memset(vis, 0x00, sizeof(vis));
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int ch = read();
            if (ch == '0')
                continue;
            ch -= 0x30;
            setit(row + i, ch);
            setit(col + j, ch);
            setit(*(squ + (i / 3)) + (j / 3), ch);
            vis[i][j] = ch;
        }
    }
    // printf("Hello!\n");
    dfs();
    return 0;
}