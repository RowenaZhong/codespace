#include <bits/stdc++.h>
using namespace std;
namespace IO
{
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
    while (!feof(stdin) && isdigit(ch)) {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
inline void readl() {}
template <typename T, typename... Args>
inline void readl(T &x, Args &...args)
{
    readi(x);
    readl(args...);
}
template <typename T>
inline void writei(T x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p) {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}
inline void writel() {}
template <typename T, typename... Args>
inline void writel(T x, Args... args)
{
    writei(x);
    putchar(" \n"[sizeof...(args) == 0]);
    writel(args...);
}
} // namespace IO
class Node
{
public:
    int lp, rp, fa, x, max, min, cntBst, bst;
    Node() {};
    Node(int _lp, int _rp, int _fa, int _x, int _max, int _min)
    {
        this->lp = _lp;
        this->rp = _rp;
        this->fa = _fa;
        this->x = _x;
        this->max = _max;
        this->min = _min;
    }
};
const int MAXN = 2e5 + 7;
int n, q;
Node node[MAXN];
#define prop(p, idx) node[idx].p

inline void Update(int u)
{
    prop(max, u) = prop(min, u) = prop(x, u);
    if (prop(lp, u))
        prop(max, u) = max(prop(max, u), prop(max, prop(lp, u))),
                  prop(min, u) = min(prop(min, u), prop(min, prop(lp, u)));
    if (prop(rp, u))
        prop(max, u) = max(prop(max, u), prop(max, prop(rp, u))),
                  prop(min, u) = min(prop(min, u), prop(min, prop(rp, u)));
    prop(bst, u) = (!prop(lp, u) || prop(bst, prop(lp, u)) &&
                                        prop(max, prop(lp, u)) <= prop(x, u)) &&
                   (!prop(rp, u) || prop(bst, prop(rp, u)) &&
                                        prop(min, prop(rp, u)) >= prop(x, u));
    prop(cntBst, u) =
        prop(cntBst, prop(lp, u)) + prop(cntBst, prop(rp, u)) + prop(bst, u);
}
void Build(int u)
{
    if (prop(lp, u))
        Build(prop(lp, u));
    if (prop(rp, u))
        Build(prop(rp, u));
    Update(u);
}
void Change(int u, int x)
{
    prop(x, u) = x;
    while (u) {
        Update(u);
        u = prop(fa, u);
    }
}
int main()
{
    freopen("bst.in", "r", stdin);
    freopen("bst.out", "w", stdout);
    IO::readl(n, q);
    for (int i = 1; i <= n; i++) {
        int l, r;
        IO::readl(l, r);
        prop(lp, i) = l;
        prop(rp, i) = r;
        if (l)
            prop(fa, l) = i;
        if (r)
            prop(fa, r) = i;
    }
    for (int i = 1; i <= n; i++)
        IO::readi(prop(x, i));
    Build(1);
    while (q--) {
        int k, x;
        IO::readl(k, x);
        Change(k, x);
        IO::writel(prop(cntBst, 1));
    }
    return 0;
}
