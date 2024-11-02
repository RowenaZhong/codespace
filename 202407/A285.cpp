#include <iostream>
using namespace std;
int H[6005], I[6005], NI[6005], N, root;
bool v[6005];
class P
{
public:
    P *nxt;
    int child;
    P(P *p, int c)
    {
        this->nxt = p;
        this->child = c;
    }
};

P *childs[6005];
bool notroot[6005];
// int tag = 0;
// void putag()
// {
//     for (int i = 0; i < tag; i++)
//         putchar('\t');
// }
void dp(int p)
{
    // putag();
    // printf("node_%d\n", p);
    // tag++;
    if (v[p])
        return;
    v[p] = true;
    I[p] = H[p];
    NI[p] = 0;
    for (P *pc = childs[p]; pc; pc = pc->nxt)
    {
        dp(pc->child);
        I[p] += NI[pc->child];
        NI[p] += max(I[pc->child], NI[pc->child]);
    }
    // tag--;
    return;
}
int main()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
        scanf("%d", H + i);

    for (int i = 1; i < N; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        childs[b] = new P(childs[b], a);
        notroot[a] = true;
    }
    for (int i = 1; i <= N; i++)
        if (!notroot[i])
        {
            root = i;
            break;
        }
    dp(root);
    printf("%d\n", max(NI[root], I[root]));
    return 0;
}