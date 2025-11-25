#include <bits/stdc++.h>
using namespace std;
int m, q;
const int MAXM = 2e5 + 7, MAXQ = 2e5 + 7;
int A[MAXM], B[MAXM], sumA[MAXM], sumB[MAXM];
int add[MAXM];

#define INF (1 << 30)
// 70 pts
struct SegmentTree
{
    int *max;
    int *a;
    int n;
    void build(int l, int r, int node)
    {
        if (l == r)
        {
            max[node] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(node << 1, l, mid);
        build(node << 1 | 1, mid + 1, r);
        max[node] = std::max(max[node << 1], max[node << 1 | 1]);
    }
    SegmentTree(int _n, int *_a) : n(_n), a(_a)
    {
        max = new int[(n + 1) << 2];
        build(1, 1, n);
    }
    int query(int l, int r, int node, int ql, int qr)
    {
        if (ql <= l && r <= qr)
            return max[node];
        int mid = (l + r) >> 1;
        int res = -INF;
        if (ql <= mid)
            res = std::max(res, query(l, mid, node << 1, ql, qr));
        if (mid < qr)
            res = std::max(res, query(mid + 1, r, node << 1 | 1, ql, qr));
        return res;
    }
};
int main()
{
    freopen("max.in", "r", stdin);
    freopen("max.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> m >> q;
    for (int i = 1; i <= m; i++)
        cin >> A[i], sumA[i] = sumA[i - 1] + A[i];
    for (int i = 1; i <= m; i++)
        cin >> B[i], sumB[i] = sumB[i - 1] + B[i];
    for (int i = 1; i <= m; i++)
        add[i] = A[i] + B[i];
    SegmentTree ST(m, add);
    while (q--)
    {
        int ans = 0;
        // ans >= max{A[k=i]+B[k!=i],A[k!=i]+B[k=i]}
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int sum_A = sumA[r1] - sumA[l1 - 1], sum_B = sumB[r2] - sumB[l2 - 1];
        int ex = 0;
        /*
         * sum_A + exA = sum_B + exB = ans
         * A_i <= sum_B + exB - B_i -> exB >= A_i - sum_B + B_i
         * B_i <= sum_A + exA - A_i -> exA >= B_i - sum_A + A_i
         */
        if (l1 == l2)
        {
            printf("%d\n", max(ST.query(1, m, 1, l1, r1), max(sum_A, sum_B)));
            continue;
        }
        for (int i = 1; i <= r1 - l1 + 1; i++)
        {
            auto A_i = A[l1 + i - 1];
            auto B_i = B[l2 + i - 1];
            ex = max(ex, A_i + B_i);
        }

        ans = max(ex, max(sum_A, sum_B));
        printf("%d\n", ans);
    }
    return 0;
}