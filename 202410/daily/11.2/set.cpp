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

int mp[2004][2004], S[2004], pres[2004];
int n;
int c, T;
int main()
{
    freopen("set.in", "r", stdin);
    freopen("set.out", "w", stdout);
    readi(c), readi(T);
    while (T--)
    {
        memset(mp, 0x00, sizeof(mp));
        int n, m, k;
        readi(n), readi(m);
        while (m--)
        {
            readi(k);
            for (int i = 1; i <= n; i++)
                pres[i] = 0, S[i] = false;
            while (k--)
            {
                int l, r;
                readi(l), readi(r);
                pres[l]++;
                pres[r + 1]--;
            }
            int sum = 0;
            for (int i = 1; i <= n; i++)
            {
                sum += pres[i];
                if (sum > 0)
                    S[i] = true;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (S[i] ^ S[j])
                    {
                        mp[i][j] = mp[j][i] = true;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            bool _flag = true;
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    continue;
                if (!mp[i][j])
                {
                    _flag = false;
                    break;
                }
            }
            ans += _flag;
        }
        writei(ans);
        putchar('\n');
    }
    return 0;
}