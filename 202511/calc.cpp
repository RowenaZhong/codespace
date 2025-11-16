#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
const long long INF = 1e18;
struct P
{
    vector<int> child;
    pair<long long, long long> edge;
    pair<long long, long long> accept;
    long long a, sum;
} node[MAXN];
map<long long, int> hsh;
vector<long long> ysc;
int n, q;
int pp[MAXN * 4];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> q;
    for (int i = 2; i <= n; i++)
    {
        int p;
        long long l, r;
        cin >> p >> l >> r;
        node[p].child.push_back(i);
        node[i].edge = {l, r};
    }
    for (int i = 1; i <= n; i++)
    {
        char op;
        long long a;
        cin >> op >> a;
        node[i].a = (op == '+') ? a : -a;
        node[i].accept = {0, -1};
    }
    queue<pair<int, int>> que;
    que.push({1, 0});
    node[0].accept = {-INF, INF};
    node[1].edge = {-INF, INF};
    while (que.size())
    {
        auto u = que.front().first, fa = que.front().second;
        que.pop();
        // tailor accept of fa with edge
        // auto acc = node[fa].accept;
        node[u].sum = node[fa].sum + node[u].a;
        node[u].accept = {node[u].edge.first - node[fa].sum,
                          node[u].edge.second - node[fa].sum};
        node[u].accept = {max(-INF, node[u].accept.first),
                          min(INF, node[u].accept.second)};
        node[u].accept = {max(node[u].accept.first, node[fa].accept.first),
                          min(node[u].accept.second, node[fa].accept.second)};
        if (node[u].accept.first <= node[u].accept.second)
        {
            ysc.push_back(node[u].accept.first);
            ysc.push_back(node[u].accept.second);
            ysc.push_back(node[u].accept.second + 1);
            // do something
            for (auto v : node[u].child)
                que.push({v, u});
        }
    }
    sort(ysc.begin(), ysc.end());
    auto ysc_size = unique(ysc.begin(), ysc.end()) - ysc.begin();
    ysc.resize(ysc_size);
    for (auto i = 0; i < ysc_size; i++)
        hsh[ysc[i]] = i + 1;
    for (int u = 1; u <= n; u++)
    {
        if (node[u].accept.first <= node[u].accept.second)
        {
            auto l = hsh[node[u].accept.first],
                 r = hsh[node[u].accept.second + 1];
            pp[l]++;
            pp[r]--;
        }
    }
    for (int i = 1; i <= ysc_size + 1; i++)
        pp[i] += pp[i - 1];
    while (q--)
    {
        long long x;
        cin >> x;
        auto i = upper_bound(ysc.begin(), ysc.end(), x) - ysc.begin();
        printf("%d\n", pp[i]);
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     cerr << node[i].accept.first << " " << node[i].accept.second << endl;
    // }
    return 0;
}