#include <bits/stdc++.h>
using namespace std;

int a[20005];
struct Index
{
    int ndx, step, u, v;
    bool operator<(const Index &a) const
    {
        return ndx < a.ndx;
    }
};
int P;
priority_queue<Index> pq;

inline void check_and_add(Index index)
{
    if (index.u >= 40000)
        return;
    // if (M[index.u][index.v] <= index.step)
    //     return;
    if (P % __gcd(index.u + index.v, index.u) != 0)
        return;
    pq.push(index);
}
int main()
{
    cin >> P;
    pq.push({-(int)log2(P), 0, 1, 0});
    // memset(M[0], 0x37, sizeof(int) * 20001 * 20001);
    while (pq.size())
    {
        Index index = pq.top();
        pq.pop();
        // if (M[index.u][index.v] <= index.step)
        //     continue;
        // M[index.u][index.v] = index.step;
        // printf("expected:%d\tsteps:%d\tu:%d\tv:%d\n", -index.ndx, index.step, index.u, index.v);
        if (index.u == P)
        {
            printf("%d\n", index.step);
            break;
        }
        if (index.u * 2 <= P)
        {
            check_and_add({-((int)log2((double)P / (index.u * 2)) + index.step + 1),
                           index.step + 1,
                           index.u * 2, index.v});
            check_and_add({-((int)log2((double)P / (index.u * 2)) + index.step + 1),
                           index.step + 1,
                           index.u * 2, index.u});
        }
        if (index.v * 2 <= P && index.v != 0)
        {
            check_and_add({-((int)log2((double)P / (index.v * 2)) + index.step + 1),
                           index.step + 1,
                           index.v * 2, index.v});
            check_and_add({-((int)log2((double)P / (max(index.v * 2, index.u))) + index.step + 1),
                           index.step + 1,
                           max(index.v * 2, index.u), min(index.v * 2, index.u)});
        }
        if (index.u + index.v <= P)
        {
            check_and_add({-((int)log2((double)P / (index.u + index.v)) + index.step + 1),
                           index.step + 1,
                           index.u + index.v, index.v});
            check_and_add({-((int)log2((double)P / (index.u + index.v)) + index.step + 1),
                           index.step + 1,
                           index.u + index.v, index.u});
        }
        check_and_add({-((int)log2((double)P / (index.u)) + index.step + 1),
                       index.step + 1,
                       index.u, 0});
        if (index.v != 0)
            check_and_add({-((int)log2((double)P / (index.v)) + index.step + 1),
                           index.step + 1,
                           index.v, 0});

        check_and_add({-((int)log2((double)P / max(index.u - index.v, index.u)) + index.step + 1),
                       index.step + 1,
                       max(index.u - index.v, index.u), min(index.u - index.v, index.u)});
        check_and_add({-((int)log2((double)P / max(index.u - index.v, index.v)) + index.step + 1),
                       index.step + 1,
                       max(index.u - index.v, index.v), min(index.u - index.v, index.v)});
    }
    return 0;
}