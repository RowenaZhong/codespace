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
        putchar('-'), x = -x;
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
const int MAXN = 2e5 + 7;
int n, g[MAXN], s[MAXN], b[MAXN];
int gq[MAXN], sq[MAXN], bq[MAXN];
int gh[MAXN], sh[MAXN], bh[MAXN];
int rnkg[MAXN], rnks[MAXN], rnkb[MAXN];
int main()
{
    readi(n);
    for (int i = 1; i <= n; i++)
    {
        readi(g[i]);
        readi(s[i]);
        readi(b[i]);
        g[i] = -g[i];
        s[i] = -s[i];
        b[i] = -b[i];
        gq[i] = g[i];
        sq[i] = s[i];
        bq[i] = b[i];
    }
    sort(gq + 1, gq + n + 1);
    sort(sq + 1, sq + n + 1);
    sort(bq + 1, bq + n + 1);
    gq[0] = sq[0] = bq[0] = -1;
    int gi = 0, si = 0, bi = 0;
    for (int i = 1; i <= n; i++)
    {
        if (gq[i] != gq[i - 1])
        {
            gh[++gi] = gq[i];
            rnkg[gi] = i;
        }
        if (sq[i] != sq[i - 1])
        {
            sh[++si] = sq[i];
            rnks[si] = i;
        }
        if (bq[i] != bq[i - 1])
        {
            bh[++bi] = bq[i];
            rnkb[bi] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int min_rnk = n;
        min_rnk = min(min_rnk, rnkg[lower_bound(gh + 1, gh + gi + 1, g[i]) - gh]);
        min_rnk = min(min_rnk, rnks[lower_bound(sh + 1, sh + si + 1, s[i]) - sh]);
        min_rnk = min(min_rnk, rnkb[lower_bound(bh + 1, bh + bi + 1, b[i]) - bh]);
        writei(min_rnk);
        putchar('\n');
    }
}