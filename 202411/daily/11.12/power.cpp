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
typedef unsigned long long ull;
const int MAXN = 2e5 + 7;
ull n, k, k1;
ull divi[MAXN], tot, cnt[MAXN];
int main()
{
    freopen("power.in", "r", stdin);
    freopen("power.out", "w", stdout);
    readi(n), readi(k);
    for (ull i = 2; i * i <= k; i++) {
        if (k % i == 0) {
            divi[++tot] = i;
            while (k % i == 0) {
                cnt[tot]++;
                k /= i;
            }
        }
    }
    if (k != 1) {
        divi[++tot] = k;
        cnt[tot] = 1;
    }
    ull ans = LONG_LONG_MAX;
    for (ull i = 1; i <= tot; i++) {
        ull sum = 0;
        for (ull j = divi[i]; j <= n; j *= divi[i]) {
            sum += n / j;
            if (j * divi[i] / divi[i] != j)
                break;
        }
        ans = min(ans, sum / cnt[i]);
    }
    writei(ans);
    putchar('\n');
    return 0;
}
