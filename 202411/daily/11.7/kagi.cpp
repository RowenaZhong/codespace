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
const int MAXN = 1e5 + 5, MAXK = 2e5 + 5;
int head[MAXN], k[MAXN], arr[MAXK], choice[MAXN], tot = 1;
inline void solve()
{
    int n, m, deadline, lasting_time = 0, lasting_friend = 0;
    bool possibility = true;
    readi(n);
    readi(m);
    deadline = m / 2 + (m & 1);
    for(int i = 1; i <= m; i++)
    {
        readi(k[i]);
        head[i] = tot;
        tot += k[i];
        for(int j = 0; j < k[i]; j++)
            readi(arr[head[i] + j]);
        sort(arr+head[i],arr+head[i]+k[i]);
        choice[i] = 0;
        if(arr[head[i]] == lasting_friend)
        {
            if(k[i] == 1)
            {
                lasting_time++;
                if(lasting_time > deadline)
                {
                    if(k[i - lasting_time + 1] == 1)
                        possibility = false;
                    else
                        choice[i - lasting_time + 1] ^= 1;
                }
            }
            else choice[i]++, lasting_time = 1;
        }
        else lasting_time = 1;
        lasting_friend = arr[head[i] + choice[i]];
    }
    if(possibility)
    {
        for(int i  = 1; i <= m; i++)
            writei(arr[head[i] + choice[i]]), putchar(" \n"[i == m]);
    }
    else
    {
        puts("SOMEONE WILL BE ANGRY!");
    }
}
int main()
{
    freopen("kagi.in", "r", stdin);
    freopen("kagi.out", "w", stdout);
    int T;
    readi(T);
    while (T--)
        solve();
    return 0;
}