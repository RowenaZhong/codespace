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
const int MAXN = 1e5 + 7, MAXM = 2e5 + 7;
int n, m;
int root[MAXM], l[MAXM * 8], r[MAXM * 8], a[MAXM * 8], cnt = 1, cur;
int build(int lp, int rp)
{
    int nd = cnt++;
    if (lp == rp)
    {
        a[nd] = lp;
        return nd;
    }
    l[nd] = build(lp, (lp + rp) >> 1);
    r[nd] = build(((lp + rp) >> 1) + 1, rp);
    return nd;
}
int setx(int lp, int rp, int ndold, int x, int s)
{
    int nd = cnt++;
    if (lp == rp)
    {
        a[nd] = s;
        return nd;
    }
    int mid = (lp + rp) >> 1;
    if (x <= mid)
        l[nd] = setx(lp, mid, l[ndold], x, s),
        r[nd] = r[ndold];
    else
        l[nd] = l[ndold],
        r[nd] = setx(mid + 1, rp, r[ndold], x, s);
    return nd;
}
int setfa(int x, int s)
{
    // cerr << root[cur] << " " << l[root[cur]] << " " << r[root[cur]] << endl;
    root[cur] = setx(1, n, root[cur], x, s);
    return s;
}
int query(int lp, int rp, int nd, int x)
{
    if (lp == rp)
        return a[nd];
    int mid = (lp + rp) >> 1;
    if (x <= mid)
        return query(lp, mid, l[nd], x);
    else
        return query(mid + 1, rp, r[nd], x);
}
int getfa(int x)
{
    int fa = query(1, n, root[cur], x);
    if (fa == x)
        return x;
    return setfa(x, getfa(fa));
}
int main()
{
    readi(n);
    readi(m);
    root[0] = build(1, n);
    // for (int i = 1; i <= n; i++)
    //     printf("%d%c", query(1, n, root[cur], i), " \n"[i == n]);
    for (cur = 1; cur <= m; cur++)
    {
        int cmd, a, b, k;
        readi(cmd);
        root[cur] = cnt++;
        l[root[cur]] = l[root[cur - 1]];
        r[root[cur]] = r[root[cur - 1]];
        switch (cmd)
        {
        case 1:
            readi(a);
            readi(b);
            setfa(getfa(a), getfa(b));
            break;
        case 2:
            readi(k);
            root[cur] = root[k];
            break;
        case 3:
            readi(a);
            readi(b);
            printf("%d\n", int(getfa(a) == getfa(b)));
        default:
            break;
        }
        // for (int i = 1; i <= n; i++)
        //     printf("%d%c", query(1, n, root[cur], i), " \n"[i == n]);
    }
    return 0;
}