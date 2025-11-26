#include <bits/stdc++.h>
#include <cstdint>
#include <climits>
using namespace std;
const int MAXN = 5e5 + 7;
vector<pair<int, int>> ques;
int adds[MAXN];
int n, k, q;
int a[MAXN], arr_lefted[MAXN], arr_righted[MAXN], a_ori[MAXN], a_sorted[MAXN];
bool cmp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}
class SegTree
{
    int *max;
    int *min;
    int n, *a;
    void build(int l, int r, int x)
    {
        if (l == r)
        {
            max[x] = min[x] = a[l];
            return;
        }
        build(l, (l + r) >> 1, x << 1);
        build(((l + r) >> 1) + 1, r, (x << 1) + 1);
        min[x] = ::min(min[x << 1], min[(x << 1) | 1]);
        max[x] = ::max(max[x << 1], max[(x << 1) | 1]);
    }

public:
    SegTree(int _n, int *_a)
    {
        n = _n, a = _a;
        max = new int[n << 2];
        min = new int[n << 2];
        a = _a;
        build(1, n, 1);
    }
    ~SegTree()
    {
        delete[] max;
        delete[] min;
    }
    int query_min(int L, int R, int l, int r, int x)
    {
        if (L <= l && r <= R)
            return min[x];
        int mid = (l + r) >> 1;
        int ans = INT_MAX;
        if (L <= mid)
            ans = ::min(query_min(L, R, l, mid, x << 1), ans);
        if (R > mid)
            ans = ::min(query_min(L, R, mid + 1, r, (x << 1) | 1), ans);
        return ans;
    }
    int query_max(int L, int R, int l, int r, int x)
    {
        if (L <= l && r <= R)
            return max[x];
        int mid = (l + r) >> 1;
        int ans = INT_MIN;
        if (L <= mid)
            ans = ::max(query_max(L, R, l, mid, x << 1), ans);
        if (R > mid)
            ans = ::max(query_max(L, R, mid + 1, r, (x << 1) | 1), ans);
        return ans;
    }
};
int my_lower_bound(int x, int a[])
{
    int l = 0, r = n;
    int mid;

    // if (q == 0)
    // {
    //     cerr << l << " " << r << endl;
    // }
    while (l < r)
    {
        if (r - l <= 5)
        {
            for (int t = l; t <= r; t++)
            {
                if (a[t] > x)
                    return t - 1;
            }
            return r;
        }
        mid = (l + r) >> 1;
        if (a[mid] < x)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("register.in", "r", stdin);
    freopen("register.out", "w", stdout);
    cin >> n >> k >> q;
    ques.resize(k);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 0; i < k; i++)
        cin >> ques[i].first;
    for (int i = 0; i < k; i++)
        cin >> ques[i].second;
    sort(ques.begin(), ques.end(), cmp);
    int cnt = 1;
    for (auto i : ques)
        for (int j = 0; j < i.first; j++)
            adds[cnt++] = i.second;
    memcpy(a_ori, a, (n + 1) * sizeof(int));
    sort(a + 1, a + n + 1);
    memcpy(a_sorted, a, (n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
    {
        arr_lefted[i - 1] = a[i] + adds[i - 1];
        arr_righted[i + 1] = a[i] + adds[i + 1];
        a[i] += adds[i];
    }
    SegTree origin(n, a), lefted(n, arr_lefted), righted(n, arr_righted);
    while (q--)
    {
        int x, v, _max = INT_MIN, _min = INT_MAX, ans;
        cin >> x >> v;
        int from_pos = my_lower_bound(a_ori[x], a_sorted);
        int to_pos = my_lower_bound(v, a_sorted);
        if (to_pos < from_pos)
            to_pos++;

        // cerr << "+" << from_pos << " " << to_pos << endl;
        if (from_pos == to_pos)
        {
            if (from_pos > 1)
                _max = max(_max, origin.query_max(1, from_pos - 1, 1, n, 1)),
                _min = min(_min, origin.query_min(1, from_pos - 1, 1, n, 1));
            if (to_pos < n)
                _max = max(_max, origin.query_max(to_pos + 1, n, 1, n, 1)),
                _min = min(_min, origin.query_min(to_pos + 1, n, 1, n, 1));
            _max = max(_max, v + adds[to_pos]);
            _min = min(_min, v + adds[to_pos]);
        }
        else if (from_pos < to_pos)
        {
            if (from_pos > 1)
                _max = max(_max, origin.query_max(1, from_pos - 1, 1, n, 1)),
                _min = min(_min, origin.query_min(1, from_pos - 1, 1, n, 1));
            if (to_pos < n)
                _max = max(_max, origin.query_max(to_pos + 1, n, 1, n, 1)),
                _min = min(_min, origin.query_min(to_pos + 1, n, 1, n, 1));
            _max = max(_max, v + adds[to_pos]);
            _min = min(_min, v + adds[to_pos]);
            _max = max(_max, lefted.query_max(from_pos, to_pos - 1, 1, n, 1));
            _min = min(_min, lefted.query_min(from_pos, to_pos - 1, 1, n, 1));
        }
        else
        {
            if (to_pos > 1)
                _max = max(_max, origin.query_max(1, to_pos - 1, 1, n, 1)),
                _min = min(_min, origin.query_min(1, to_pos - 1, 1, n, 1));
            if (from_pos < n)
                _max = max(_max, origin.query_max(from_pos + 1, n, 1, n, 1)),
                _min = min(_min, origin.query_min(from_pos + 1, n, 1, n, 1));
            _max = max(_max, v + adds[to_pos]);
            _min = min(_min, v + adds[to_pos]);
            _max = max(_max, righted.query_max(to_pos + 1, from_pos, 1, n, 1));
            _min = min(_min, righted.query_min(to_pos + 1, from_pos, 1, n, 1));
        }
        ans = _max - _min;
        printf("%d\n", ans);
    }
    return 0;
}