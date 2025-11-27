#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<int> a[100005];
struct tree
{
    int l, r, v;
} t[4000005];
void build(int p, int l, int r)
{
    t[p].l = l, t[p].r = r;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
}
void update(int p, int x, int k)
{
    if (t[p].l == t[p].r)
    {
        t[p].v = max(t[p].v, k);
        return;
    }
    if (x <= t[p * 2].r)
        update(p * 2, x, k);
    else
        update(p * 2 + 1, x, k);
    t[p].v = max(t[p * 2].v, t[p * 2 + 1].v);
}
int query(int p, int l, int r)
{
    if (t[p].l >= l && t[p].r <= r)
        return t[p].v;
    int ans = 0;
    if (l <= t[p * 2].r)
        ans = max(ans, query(p * 2, l, r));
    if (r >= t[p * 2 + 1].l)
        ans = max(ans, query(p * 2 + 1, l, r));
    return ans;
}
pair<int, int> nd(int a, int b)
{
    pair<int, int> res;
    res.first = a, res.second = b;
    return res;
}
vector<pair<int, int>> b[100005];
pair<int, int> qz[100005];
int p[100005], A, B, len[1000005];
int d[100005];
bool f[100005];
void solve()
{
    for (int i = 1; i <= m; i++)
        if (p[i] >= qz[i].first && p[i] <= qz[i].second)
            B++;
    cout << A << ' ' << B << endl;
}
int main()
{
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        a[i].push_back(1919810);
        b[i].push_back(nd(0, 0));
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &k);
            a[i].push_back(k);
            b[i].push_back(nd(0, 0));
        }
    }
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            if (a[j][i] != 0)
            {
                if (p[i] != 0 && a[j][i] != p[i])
                {
                    p[i] = -1;
                    break;
                }
            }
            if (p[i] == 0)
                p[i] = a[j][i];
        }
    int lst = 0;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1;
        lst = 0;
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] == 0)
                continue;
            if (a[i][j] < lst)
            {
                f[i] = 0;
                break;
            }
            lst = a[i][j];
        }
        if (f[i])
            A++;
    }
    for (int i = 1; i <= n; i++)
    {
        lst = 0;
        if (f[i])
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j])
                    lst = a[i][j];
                else
                    b[i][j].first = lst;
            }
            lst = 1919810;
            for (int j = m; j >= 1; j--)
            {
                if (a[i][j])
                    lst = a[i][j];
                else
                    b[i][j].second = lst;
            }
        }
        else
        {
            for (int j = 1; j <= m; j++)
                b[i][j].first = 1, b[i][j].second = 1000000;
        }
    }
    for (int i = 1; i <= m; i++)
        qz[i].first = 1, qz[i].second = 1000000;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (f[i] && !a[i][j])
                qz[j].first = max(qz[j].first, b[i][j].first), qz[j].second = min(qz[j].second, b[i][j].second);
    if (!A)
    {
        solve();
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        if (p[i] >= qz[i].first && p[i] <= qz[i].second)
            ;
        else
            p[i] = -1;
    }
    k = 0;
    build(1, 1, 1000000);
    for (int i = 1; i <= m; i++)
        if (p[i] != -1)
            d[++k] = p[i];
    for (int i = 1; i <= k; i++)
    {
        len[d[i]] = query(1, 1, d[i]) + 1;
        update(1, d[i], len[d[i]]);
        B = max(B, len[d[i]]);
    }
    cout << A << ' ' << B << endl;
    return 0;
}
