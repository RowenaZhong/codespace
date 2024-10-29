#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 9;
class Node
{
public:
    int l, r;
    int p;
    Node()
    {
        this->l = this->r = this->p = 0;
    }
    Node(int _l, int _r, int _p)
    {
        this->l = _l;
        this->r = _r;
        this->p = _p;
    }
};
Node tree[MAXN];
int n;
int right_nodes[MAXN], tot = 0;
void add_node(int k, int p)
{
    tree[k].p = p;
    while (tot && tree[right_nodes[tot]].p > p)
    {
        tree[k].l = right_nodes[tot];
        tot--;
    }
    if (tot)
    {
        tree[k].l = tree[right_nodes[tot]].r;
        tree[right_nodes[tot]].r = k;
    }
    right_nodes[++tot] = k;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int p;
        scanf("%d", &p);
        add_node(i, p);
    }
    long long ansl = 0, ansr = 0;
    for (long long i = 1; i <= n; i++)
    {
        ansl ^= i * (tree[i].l + 1);
        ansr ^= i * (tree[i].r + 1);
    }
    printf("%lld %lld\n", ansl, ansr);
    return 0;
}