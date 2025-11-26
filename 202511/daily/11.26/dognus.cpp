#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;
#define lowbit(x) ((x) & (-(x)))
struct Trray
{
    int *_data;
    int _n;
    Trray(int n)
    {
        _data = new int[n + 1];
        _n = n;
        memset(_data, 0, sizeof(int) * (n + 1));
    }
    void add(int x, int v)
    {
        for (; x <= _n; x += lowbit(x))
            (_data[x] += v) %= MOD;
    }
    void clear()
    {
        memset(_data, 0, sizeof(int) * (_n + 1));
    }
    int query(int x)
    {
        int res = 0;
        for (; x; x -= lowbit(x))
            (res += _data[x]) %= MOD;
        return res;
    }
    ~Trray()
    {
        delete[] _data;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("dognus.in", "r", stdin);
    freopen("dognus.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    Trray tree(n + m);
    while (m--)
    {
        tree.clear();
        int x, y, ans = 0;
        cin >> x >> y;
        swap(a[x], y);
        for (int i = 1; i <= n; i++)
        {
            int val = (tree.query(a[i]) + 1) % MOD;
            tree.add(a[i], val);
            (ans += val) %= MOD;
        }
        swap(a[x], y);
        cout << ans << '\n';
    }
    return 0;
}