#include <iostream>
using namespace std;
const int MAXN = 2e5 + 7;
unsigned h[MAXN], n, l[MAXN], r[MAXN];
//  l_i : count of k < i and h_k smaller than h_i
//  r_i : count of k > i and h_k smaller than h_i
inline unsigned lowbit(unsigned x)
{
    return x & (-x);
}
unsigned c1[MAXN], c2[MAXN], *c;
unsigned Query(unsigned x)
{
    unsigned Ans = 0u;
    for (; x; x -= lowbit(x))
        Ans += *(c + x);
    return Ans;
}
void Add(unsigned x, unsigned y)
{
    for (; x <= n; x += lowbit(x))
        *(c + x) += y;
}
typedef unsigned long long ull;
int main()
{
    scanf("%u", &n);
    for (int i = 1; i <= n; i++)
        scanf("%u", h + i);
    c = c1;
    for (int i = 1; i <= n; i++)
    {
        l[i] = Query(h[i]);
        Add(h[i], 1u);
    }
    c = c2;
    for (int i = n; i >= 1; i--)
    {
        r[i] = Query(h[i]);
        Add(h[i], 1u);
    }
    ull Ans1 = 0llu, Ans2 = 0llu; // Ans1:V Ans2:^
    for (int i = 1; i <= n; i++)
    {
        Ans1 += ull(i - 1 - l[i]) * (n - i - r[i]);
        Ans2 += ull(l[i]) * r[i];
    }
    printf("%llu %llu\n", Ans1, Ans2);
    return 0;
}