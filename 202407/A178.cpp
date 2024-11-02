#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int N, M, S, T, K;
vector<pair<int, int>> redge[1024];
vector<pair<int, int>> edge[1024];
int count[1024];
int disT[1024];
class D
{
public:
    int s;
    int weight;
    int dist;
    D(int _s, int _w, int _d)
    {
        this->s = _s;
        this->weight = _w;
        this->dist = _d;
    }
};
bool operator>(D a, D b)
{
    return a.weight > b.weight;
}
int main()
{
    scanf("%d %d", &N, &M);
    while (M--)
    {
        int s, t, l;
        scanf("%d %d %d", &s, &t, &l);
        edge[s].push_back(make_pair(t, l));
        redge[t].push_back(make_pair(s, l));
    }
    scanf("%d %d %d", &S, &T, &K);
    if (S == T)
        K++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    memset(disT, 0x3f, sizeof(disT));
    pq.push(make_pair(0, T));
    while (pq.size())
    {
        pair<int, int> t = pq.top();
        pq.pop();
        if (disT[t.second] < t.first)
            continue;
        disT[t.second] = t.first;
        for (auto iter = redge[t.second].begin(); iter != redge[t.second].end(); iter++)
            if (disT[(*iter).first] > t.first + (*iter).second)
                pq.push(make_pair(t.first + (*iter).second, (*iter).first));
    }
    priority_queue<D, vector<D>, greater<D>> work;
    work.push(D(S, disT[S], 0));
    while (work.size())
    {
        D t = work.top();
        work.pop();
        if (count[t.s] >= K)
            continue;
        count[t.s]++;
        if (t.s == T && count[T] == K)
        {
            printf("%d\n", t.dist);
            return 0;
        }
        for (auto iter = edge[t.s].begin(); iter != edge[t.s].end(); iter++)
            work.push(D((*iter).first, t.dist + (*iter).second + disT[(*iter).first], t.dist + (*iter).second));
    }
    printf("-1\n");
    return 0;
}