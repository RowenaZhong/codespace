#include <iostream>
#include <algorithm>
using namespace std;
int T, n;
const int MAXN = 1e5 + 7;
int fa[MAXN << 1], record[MAXN][3], book[MAXN << 1];
int getf(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = getf(fa[x]);
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", *(record + i) + 0, *(record + i) + 1, *(record + i) + 2);
            book[i << 1] = record[i][0];
            book[(i << 1) | 1] = record[i][1];
        }
        sort(book, book + (n << 1));
        int m = unique(book, book + (n << 1)) - book;
        for (int i = 0; i < m; i++)
            fa[i] = i;
        for (int i = 0; i < n; i++)
            if (record[i][2] == 1)
                fa[getf(lower_bound(book, book + m, record[i][0]) - book)] = getf(lower_bound(book, book + m, record[i][1]) - book);
        bool flag = true;
        for (int i = 0; i < n; i++)
            if (record[i][2] == 0)
                if (getf(lower_bound(book, book + m, record[i][0]) - book) == getf(lower_bound(book, book + m, record[i][1]) - book))
                {
                    flag = false;
                    break;
                }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}