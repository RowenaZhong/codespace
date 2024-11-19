#include <bits/stdc++.h>
using namespace std;
class SegNode
{
public:
    SegNode *lp;
    SegNode *rp;
    char ch;
    SegNode()
    {
        this->lp = this->rp = nullptr;
        this->ch = 0;
    }
};
const int MAXN = 1e5 + 7, STDN = 1e5;
SegNode *nodes[MAXN];
int n, cur, size[MAXN];
SegNode *build(int l, int r)
{
    auto ret = new SegNode();
    if (l != r)
    {
        auto mid = l + r >> 1;
        ret->lp = build(l, mid);
        ret->rp = build(mid + 1, r);
    }
    return ret;
}
SegNode *Add(int l, int r, int x, char ch, SegNode *old)
{
    auto ret = new SegNode();
    if (l == r)
    {
        ret->ch = ch;
        return ret;
    }
    auto mid = l + r >> 1;
    if (x <= mid)
        ret->lp = Add(l, mid, x, ch, old->lp), ret->rp = old->rp;
    else
        ret->rp = Add(mid + 1, r, x, ch, old->rp), ret->lp = old->lp;
    return ret;
}
char Query(int l, int r, int x, SegNode *p)
{
    if (l == r)
        return p->ch;
    auto mid = l + r >> 1;
    if (x <= mid)
        return Query(l, mid, x, p->lp);
    return Query(mid + 1, r, x, p->rp);
}
int main()
{
    scanf("%d", &n);
    nodes[0] = build(1, STDN);
    while (n--)
    {
        int x;
        char opt, ch;
        scanf("\n%c ", &opt);
        switch (opt)
        {
        case 'T':
            scanf("%c", &ch);
            cur++;
            size[cur] = size[cur - 1] + 1;
            nodes[cur] = Add(1, STDN, size[cur], ch, nodes[cur - 1]);
            break;
        case 'U':
            scanf("%d", &x);
            cur++;
            size[cur] = size[cur - x - 1];
            nodes[cur] = nodes[cur - x - 1];
            break;
        case 'Q':
            scanf("%d", &x);
            putchar(Query(1, STDN, x, nodes[cur]));
            putchar('\n');
            break;
        }
    }
    return 0;
}