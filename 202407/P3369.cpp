#include <iostream>
#include <ctime>
#include <climits>
#include <cstdlib>
using namespace std;
typedef struct
{
    int l, r, val, priority, sum, cnt;
} nd;
const int MAXN = 1e5 + 7;
nd Treap[MAXN];
int sz = 0;
#define l(i) Treap[i].l
#define r(i) Treap[i].r
#define val(i) Treap[i].val
#define priority(i) Treap[i].priority
#define sum(i) Treap[i].sum
#define cnt(i) Treap[i].cnt
int root = 0;
inline void update(int x)
{
    sum(x) = sum(l(x)) + sum(r(x)) + cnt(x);
}
int New(int val)
{
    sz++;
    l(sz) = r(sz) = 0;
    val(sz) = val;
    priority(sz) = rand() % unsigned(1e9 + 7);
    sum(sz) = cnt(sz) = 1;
    return sz;
}
void zag(int &p)
{
    if (r(p) == 0)
        return;
    int t = r(p);
    r(p) = l(t);
    l(t) = p;
    update(p);
    update(t);
    p = t;
}
void zig(int &p)
{
    if (l(p) == 0)
        return;
    int t = l(p);
    l(p) = r(t);
    r(t) = p;
    update(p);
    update(t);
    p = t;
}
void Insert(int &p, int val)
{
    if (p == 0)
    {
        p = New(val);
        return;
    }
    sum(p)++;
    if (val(p) == val)
        cnt(p)++;
    else if (val < val(p))
    {
        Insert(l(p), val);
        if (priority(l(p)) > priority(p))
            zig(p);
    }
    else
    {
        Insert(r(p), val);
        if (priority(r(p)) > priority(p))
            zag(p);
    }
}
void Remove(int &p, int val)
{
    if (p == 0)
        return;
    if (val(p) == val)
    {
        if (cnt(p) == 1)
        {
            if (l(p) || r(p))
            {
                if (l(p) == 0 || priority(l(p)) < priority(r(p)))
                {
                    zag(p);
                    Remove(l(p), val);
                }
                else
                {
                    zig(p);
                    Remove(r(p), val);
                }
                update(p);
            }
            else
                p = 0;
        }
        else
            cnt(p)--;
    }
    else if (val < val(p))
        Remove(l(p), val);
    else
        Remove(r(p), val);
    update(p);
}
int getRank(int p, int val)
{
    if (p == 0)
        return 1;
    if (val == val(p))
        return sum(l(p)) + 1;
    if (val < val(p))
        return getRank(l(p), val);
    else
        return getRank(r(p), val) + sum(l(p)) + cnt(p);
}
int getVal(int p, int rank)
{
    if (rank <= sum(l(p)))
        return getVal(l(p), rank);
    rank -= sum(l(p)) + cnt(p);
    if (rank <= 0)
        return val(p);
    return getVal(r(p), rank);
}
int getPre(int val)
{
    int p = root, ans = INT_MIN;
    while (p)
    {
        if (val == val(p))
        {
            if (l(p))
            {
                p = l(p);
                while (r(p))
                    p = r(p);
                ans = val(p);
            }
            break;
        }
        if (val < val(p))
            p = l(p);
        else
        {
            ans = val(p);
            p = r(p);
        }
    }
    return ans;
}
int getNext(int val)
{
    int p = root, ans = INT_MIN;
    while (p)
    {
        if (val == val(p))
        {
            if (r(p))
            {
                p = r(p);
                while (l(p))
                    p = l(p);
                ans = val(p);
            }
            break;
        }
        if (val < val(p))
        {
            ans = val(p);
            p = l(p);
        }
        else
            p = r(p);
    }
    return ans;
}
void dfs(int r)
{
    if (r == 0)
        return;
    dfs(l(r));
    printf("Treap_%d:\t(l:%d\tr:%d\tval:%d\tsum:%d\tcnt:%d\tpriority:%d)\n", r, l(r), r(r), val(r), sum(r), cnt(r), priority(r));
    dfs(r(r));
}
int main()
{
    srand((unsigned)time(nullptr));
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int m, x;
        scanf("%d %d", &m, &x);
        switch (m)
        {
        case 1:
            Insert(root, x);
            break;
        case 2:
            Remove(root, x);
            break;
        case 3:
            printf("%d\n", getRank(root, x));
            break;
        case 4:
            printf("%d\n", getVal(root, x));
            break;
        case 5:
            printf("%d\n", getPre(x));
            break;
        case 6:
            printf("%d\n", getNext(x));
            break;
        default:
            break;
        }
        // dfs(root);
    }
    return 0;
}