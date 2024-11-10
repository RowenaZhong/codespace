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
const int MAXN = 5e5 + 7;
int T, n, id, last, q;
typedef long long ll;
ll a[MAXN];
int que[MAXN], h, t;
inline ll GetX(int i)
{
    return i;
}
inline ll GetY(int i)
{
    return a[i];
}
inline long double GetSlope(int i, int j)
{
    return (long double) (GetY(i) - GetY(j)) / (GetX(i) - GetX(j));
}
int main()
{
    freopen("sign.in", "r", stdin);
    freopen("sign.out", "w", stdout);
    readi(T), readi(n), readi(id);
    ll last = 0;
    while (T--) {
        last = 0;
        readi(q);
        for (int i = 1; i <= n; i++)
            readi(a[i]);
        h = t = 0;
        for (int i = 1; i <= n; i++) {
            while (h < t && GetSlope(que[t], que[t - 1]) < GetSlope(que[t], i))
                t--;
            que[++t] = i;
        }
        ll k, sumK = 0;
        for (int i = 1; i <= q; i++) {
            readi(k);
            if (id)
                k = (k ^ (last % (k + 1)));
            sumK += k;
            while (h < t &&
                   GetSlope(que[h], que[h + 1]) > (long double) (-sumK))
                h++;
            last = a[que[h]] + sumK * que[h];
            writei(last);
            putchar('\n');
        }
    }
    return 0;
}
