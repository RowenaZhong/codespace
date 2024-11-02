#include <iostream>
using namespace std;
const int MAXN = 1e5 + 7;
typedef long long ll;
ll c1[MAXN];
ll c2[MAXN];
ll a[MAXN], d[MAXN];
int N, M;
template <typename T>
inline T lowbit(T x)
{
    return x & (-x);
}
void build1()
{
    for (int i = 1; i <= N; i++)
    {
        c1[i] = d[i];
        int t = lowbit(i);
        int p = 1;
        while (p < t)
        {
            c1[i] += c1[i - p];
            p <<= 1;
        }
    }
}
void build2()
{
    for (int i = 1; i <= N; i++)
    {
        c2[i] = i * d[i];
        int t = lowbit(i);
        int p = 1;
        while (p < t)
        {
            c2[i] += c2[i - p];
            p <<= 1;
        }
    }
}
template <ll *c>
ll Q(int x)
{
    ll Ans = 0ll;
    for (; x; x -= lowbit(x))
        Ans += *(c + x);
    return Ans;
}
template <ll *c>
void A(int x, ll y)
{
    for (; x <= N; x += lowbit(x))
        *(c + x) += y;
}
inline int get()
{
    int ch = getchar();
    while (ch != 'Q' && ch != 'C')
        ch = getchar();
    return ch;
}
int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        scanf("%lld", a + i);
        d[i] = a[i] - a[i - 1];
    }
    build1();
    build2();
    while (M--)
    {
        int ch = get();
        if (ch == 'Q')
        {
            int l, r;
            scanf("%d %d", &l, &r);
            if (l == 1)
                printf("%lld\n", ((r + 1) * Q<c1>(r) - Q<c2>(r)));
            else
                printf("%lld\n", ((r + 1) * Q<c1>(r) - Q<c2>(r)) - ((l)*Q<c1>(l - 1) - Q<c2>(l - 1)));
        }
        else
        {
            int l, r, d;
            scanf("%d %d %d", &l, &r, &d);
            A<c1>(l, d);
            A<c2>(l, ll(d) * l);
            A<c1>(r + 1, -d);
            A<c2>(r + 1, ll(-d) * (r + 1));
        }
    }
    return 0;
}