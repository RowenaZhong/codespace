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

#define lowbit(x) (x) & (-x)

int n, m;
char str[3005][24];

inline int cnt1(int x)
{
    int ans = 0;
    while (x)
        x -= lowbit(x), ans++;
    return ans;
}

bool check(int x)
{
    for (int k = 0; k < (1 << m); k++)
    {
        if (cnt1(k) == x)
        {
            set<string> a;
            for (int i = 0; i < n; i++)
            {
                string s;
                for (int j = 0; j < m; j++)
                {
                    if (k & (1 << j))
                    {
                        s.push_back(str[i][j]);
                    }
                }
                if (a.count(s))
                    goto kel;
                a.insert(s);
            }
            return true;
        }
    kel:;
    }
    return false;
}
int countit(int x)
{
    int ret = 0;
    for (int k = 0; k < (1 << m); k++)
    {
        if (cnt1(k) == x)
        {
            set<string> a;
            for (int i = 0; i < n; i++)
            {
                string s;
                for (int j = 0; j < m; j++)
                {
                    if (k & (1 << j))
                    {
                        s.push_back(str[i][j]);
                    }
                }
                if (a.count(s))
                    goto kel;
                a.insert(s);
            }
            ret++;
        }
    kel:;
    }
    return ret;
}
int main()
{
    freopen("guess.in", "r", stdin);
    freopen("guess.out", "w", stdout);
    readi(n);
    readi(m);
    for (int i = 0; i < n; i++)
        scanf("%s", str[i]);
    if (n == 1)
    {
        printf("0 1\n");
        return 0;
    }
    int l = 1, r = m;
    while (l != r)
    {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    countit(l);
    writei(l);
    putchar(' ');
    writei(countit(l));
    putchar('\n');
    return 0;
}