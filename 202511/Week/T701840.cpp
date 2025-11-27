#include <bits/stdc++.h>
using namespace std;
class Segmentree
{
    long long *sum;
    long long *lazy;
    long long *bind;
    int n;
    void build(int l, int r, int x)
    {
        if (l == r)
        {
            sum[x] = bind[l];
            return;
        }
        build(l, (l + r) >> 1, x << 1);
        build(((l + r) >> 1) + 1, r, (x << 1) + 1);
        sum[x] = sum[x << 1] + sum[(x << 1) | 1];
    }
    void pushdown(int l, int r, int x)
    {
        if (lazy[x])
        {
            int mid = (l + r) >> 1;
            sum[x << 1] += (mid - l + 1) * lazy[x];
            sum[(x << 1) | 1] += (r - mid) * lazy[x];
            lazy[x << 1] += lazy[x];
            lazy[(x << 1) | 1] += lazy[x];
            lazy[x] = 0;
        }
    }

public:
    Segmentree(int n, long long *a) : n(n), bind(a)
    {
        sum = new long long[(n + 1) << 2]();
        lazy = new long long[(n + 1) << 2]();
        build(1, n, 1);
    }
    void add(int L, int R, long long X, int l, int r, int x)
    {
        if (L <= l && r <= R)
        {
            sum[x] += X * (r - l + 1);
            lazy[x] += X;
            return;
        }
        int mid = (l + r) >> 1;
        pushdown(l, r, x);
        if (L <= mid)
            add(L, R, X, l, mid, x << 1);
        if (mid < R)
            add(L, R, X, mid + 1, r, (x << 1) | 1);
        sum[x] = sum[x << 1] + sum[(x << 1) | 1];
    }
    long long query(int L, int R, int l, int r, int x)
    {
        if (L <= l && r <= R)
            return sum[x];
        long long ans = 0;
        int mid = (l + r) >> 1;
        pushdown(l, r, x);
        if (L <= mid)
            ans += query(L, R, l, mid, x << 1);
        if (mid < R)
            ans += query(L, R, mid + 1, r, (x << 1) | 1);
        return ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    long long *a = new long long[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Segmentree st(n, a);
    while (m--)
    {
        int op, x, y;

        long long k;
        cin >> op;
        if (op == 1)
        {
            cin >> x >> y >> k;
            st.add(x, y, k, 1, n, 1);
        }
        else
        {
            cin >> x >> y;
            k = st.query(x, y, 1, n, 1);
            cout << k << endl;
        }
    }
    return 0;
}