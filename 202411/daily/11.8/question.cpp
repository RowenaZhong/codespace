#include <bits/stdc++.h>
using namespace std;
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
inline int log_2(unsigned x)
{
    int rst = 0;
    if (x & 0xffff'0000U)
        rst += 16, x >>= 16;
    if (x & 0x0000'ff00U)
        rst += 8, x >>= 8;
    if (x & 0x0000'00f0U)
        rst += 4, x >>= 4;
    if (x & 0x0000'000cU)
        rst += 2, x >>= 2;
    if (x & 0x0000'0002U)
        rst += 1;
    return rst;
}
const int MAXN = 1e5 + 7;
int n, m;
int a[MAXN], pre[MAXN], decl[MAXN];
class ST {
    int st[MAXN][20];

public:
    int *gen;
    int (*mix)(int x, int y);
    void build(int n)
    {
        for (int i = 1; i <= n; i++)
            st[i][0] = this->gen[i];
        for (int j = 1; j <= log_2(n); j++) {
            for (int i = 1; i + (1 << j) - 1 <= n; i++) {
                this->st[i][j] =
                    this->mix(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    int query(int l, int r)
    {
        int k = log_2(r - l + 1);
        return this->mix(st[l][k], st[r - (1 << k) + 1][k]);
    }
};
inline int Gcd(int a, int b)
{
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}
inline int Max(int a, int b)
{
    return a > b ? a : b;
}
inline int Min(int a, int b)
{
    return a < b ? a : b;
}
map<int, int> lastIdxOfAi;
ST MaxST, MinST, PreST, GcdST;
int MaxAns, MinAns, PreAns, GcdAns;
void GeneralQuery(int l, int r)
{
    MaxAns = MaxST.query(l, r);
    MinAns = MinST.query(l, r);
    PreAns = PreST.query(l, r);
    GcdAns = GcdST.query(l, r - 1);
}
int main()
{
    freopen("question.in", "r", stdin);
    freopen("question.out", "w", stdout);
    readi(n);
    readi(m);
    for (int i = 1; i <= n; i++) {
        readi(a[i]);
        pre[i] = lastIdxOfAi[a[i]];
        decl[i] = abs(a[i] - a[i - 1]);
        lastIdxOfAi[a[i]] = i;
    }
    MaxST.gen = MinST.gen = a;
    PreST.gen = pre;
    GcdST.gen = decl + 1;
    MaxST.mix = Max;
    MinST.mix = Min;
    PreST.mix = Max;
    GcdST.mix = Gcd;
    MaxST.build(n);
    MinST.build(n);
    PreST.build(n);
    GcdST.build(n - 1);
    while (m--) {
        int l, r;
        readi(l);
        readi(r);
        GeneralQuery(l, r);
        puts((MinAns == MaxAns ||
              (GcdAns * (r - l) == MaxAns - MinAns && PreAns < l))
                 ? "YES"
                 : "NO");
    }
    return 0;
}