#include <iostream>
using namespace std;
const int MAXN = 2e5 + 7;
class P
{
public:
    P *next;
    int weight;
    int child;
    P(P *n, int c, int w)
    {
        this->next = n;
        this->child = c;
        this->weight = w;
    }
    ~P()
    {
        if (this->next)
            delete this->next;
    }
};
P *e[MAXN];
int D[MAXN], F[MAXN], etot[MAXN];
void dfs(int x, int f)
{
    D[x] = 0;
    for (P *p = e[x]; p; p = p->next)
    {
        if (p->child == f)
            continue;
        dfs(p->child, x);
        if (etot[p->child] == 1)
            D[x] += p->weight;
        else
            D[x] += min(p->weight, D[p->child]);
    }
}
void dp(int x, int f, int w)
{
    if (f == -1)
        F[x] = D[x];
    else if (etot[f] == 1)
        F[x] = D[x] + w;
    else if (etot[x] == 1)
        F[x] = min(w, F[f] - w);
    else
        F[x] = D[x] + min(w, F[f] - min(w, D[x]));
    for (P *p = e[x]; p; p = p->next)
        if (p->child != f)
            dp(p->child, x, p->weight);
}
void solve()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        etot[i] = 0;
    for (int i = 1; i < N; i++)
    {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        e[x] = new P(e[x], y, z);
        e[y] = new P(e[y], x, z);
        etot[x]++;
        etot[y]++;
    }
    dfs(1, -1);
    dp(1, -1, 0);
    int maxf = 0;
    for (int i = 1; i <= N; i++)
    {
        maxf = max(maxf, F[i]);
        delete e[i];
        e[i] = nullptr;
    }
    printf("%d\n", maxf);
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
        solve();
    return 0;
}