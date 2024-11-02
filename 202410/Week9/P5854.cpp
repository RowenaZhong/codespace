#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 9;
template <typename T>
inline void readi(T &x)
{
    T f = 1;
    x = 0;
    int ch;
    while (ch = getchar(), !feof(stdin) && !isdigit(ch) && ch != '-')
        ;
    if (ch == '-')
        f = -f, ch = getchar();
    while (!feof(stdin) && isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
template <typename T>
inline void writei(T x)
{
    if (x == 0)
    {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p)
    {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}

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
inline void add_node(int k, int p)
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
    readi(n);
    for (int i = 1; i <= n; i++)
    {
        int p;
        readi(p);
        add_node(i, p);
    }
    long long ansl = 0, ansr = 0;
    for (long long i = 1; i <= n; i++)
    {
        ansl ^= i * (tree[i].l + 1);
        ansr ^= i * (tree[i].r + 1);
    }
    writei(ansl);
    putchar(' ');
    writei(ansr);
    putchar('\n');
    return 0;
}