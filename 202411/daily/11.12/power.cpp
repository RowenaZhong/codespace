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
typedef unsigned long long ull;
ull n, k, k1;
ull ys[200005], cnt[200005], cnt2[200005], tot;
int main()
{
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    readi(n), readi(k);
    for (ull i = 2; i * i <= k; i++) {
        if (k % i)
            continue;
        tot++, ys[tot] = i;
        while (k % i == 0)
            cnt[tot]++, k /= i;
    }
    if (k != 1)
        tot++, ys[tot] = k, cnt[tot] = 1;
    ull ans = LONG_LONG_MAX;
    ull now;
    for (ull i = 1; i <= tot; i++) {
        for (now = ys[i]; now <= n; now *= ys[i]) {
            cnt2[i] += n / now;
            if (now * ys[i] / ys[i] != now)
                break;
        }
        ans = min(ans, cnt2[i] / cnt[i]);
    }
    writei(ans);
    putchar('\n');
    return 0;
}
