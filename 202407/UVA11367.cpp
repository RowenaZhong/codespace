#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
using namespace std;
int N, M;
vector<pair<int, int>> edge[1024];
unsigned p[1024];
unsigned d[1000][100];
class Statement
{
public:
    int city;
    unsigned fuel;
    unsigned cost;
    Statement(int ci, unsigned f, unsigned c)
    {
        city = ci;
        fuel = f;
        cost = c;
    }
};
bool operator<(Statement a, Statement b)
{
    return a.cost > b.cost;
}
void solve()
{
    int c, s, e;
    scanf("%d %d %d", &c, &s, &e);
    memset(d, 0xff, sizeof(d));
    priority_queue<Statement> pq;
    pq.push(Statement(s, 0, 0));
    while (pq.size())
    {
        Statement st = pq.top();
        pq.pop();
        if (d[st.city][st.fuel] != 0xffffffff)
            continue;
        if (st.city == e)
        {
            printf("%d\n", st.cost);
            return;
        }
        d[st.city][st.fuel] = st.cost;
        if (st.fuel < c)
            pq.push(Statement(st.city, st.fuel + 1, st.cost + p[st.city]));
        for (auto iter = edge[st.city].begin(); iter != edge[st.city].end(); iter++)
            if ((*iter).second <= st.fuel)
                pq.push(Statement((*iter).first, st.fuel - (*iter).second, st.cost));
    }
    printf("impossible\n");
    return;
}
int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++)
        scanf("%d", p + i);
    while (M--)
    {
        int s, t, w;
        scanf("%d %d %d", &s, &t, &w);
        edge[s].push_back(make_pair(t, w));
        edge[t].push_back(make_pair(s, w));
    }
    int q;
    scanf("%d", &q);
    while (q--)
        solve();
    return 0;
}