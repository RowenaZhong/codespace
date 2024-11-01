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
int n, a[20];
map<int, vector<int>>mp;
set<int>ans;
int main()
{
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    readi(n);
    for (int i = 0; i < n; i++)
        readi(a[i]);
    for (int i = 0; i < (1 << n); i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
                sum += a[j];
        }
        if(mp.count(sum))
            for(const auto&x : mp[sum])
                if((x & i) == 0)
                    ans.insert(x ^ i);
        mp[sum].push_back(i);
    }
    writei(ans.size());
    return 0;
}