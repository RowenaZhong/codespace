#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 7, MAXM = 107;
struct Painter
{
    int S, L, P;
} painters[MAXM];
bool operator<(const Painter &a, const Painter &b)
{
    return a.S < b.S;
}
int N, M;
int F[MAXN];
int calc(int i, int k)
{
    return F[k] - painters[i].P * k;
}
int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; i++)
    {
        scanf("%d %d %d", &painters[i].L, &painters[i].P, &painters[i].S);
    }
    sort(painters + 1, painters + M + 1);
    for (int i = 1; i <= M; i++)
    {
        deque<int> dq;
        for (int k = max(0, painters[i].S - painters[i].L); k <= painters[i].S - 1; k++)
        {
            while (dq.size() && calc(i, dq.back()) < calc(i, k))
                dq.pop_back();
            dq.push_back(k);
        }
        for (int j = painters[i].S; j <= min(painters[i].S + painters[i].L - 1, N); j++)
        {
            if (dq.front() == j - painters[i].L - 1)
                dq.pop_front();
            F[j] = max(F[j], painters[i].P * j + calc(i, dq.front()));
        }
        for (int j = 2; j <= N; j++)
            F[j] = max(F[j], F[j - 1]);
    }
    printf("%d\n", F[N]);
}