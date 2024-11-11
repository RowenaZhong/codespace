#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1;
int m;
vector<ll> pl[10];
#define int long long
ll p10[21];
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
        putchar(0x30);
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


signed main()
{
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    cin >> s1 ;
    auto n = s1.size();
    s1 = " " + s1;
    readi(m);
    p10[0] = 1;
    for (auto i = 1; i <= 18; i++)
        p10[i] = p10[i - 1] * 10;
    ll sd = 0;
    ll now1, now2;
    for (auto i = 9; i >= 1; i--) {
        for (auto j = 1; j <= n; j++)
            if (s1[j] == i + 0x30)
                pl[i].push_back(j);
        for (auto j = 0; j < pl[i].size(); j++) {
            now1 = now2 = 0;
            for (int k = sd + 1; k <= pl[i][j]; k++)
                now1 = now1 * 10 + s1[k] - 0x30;
            now2 = i;
            for (int k = sd + 1; k < pl[i][j]; k++)
                now2 = now2 * 10 + s1[k] - 0x30;
            if ((now2 - now1) * p10[n - pl[i][j]] < m * (pl[i][j] - sd - 1)) {
                for (int i = 1; i <= n; i++)
                    putchar(s1[i]+0x30);
                return 0;
            }
            sd++;
            for (int k = pl[i][j]; k >= sd + 1; k--)
                s1[k] = s1[k - 1];
            s1[sd] = i + 0x30;
        }
    }
    for (int i = 1; i <= n; i++)
        putchar(s1[i]+0x30);
    return 0;
}
