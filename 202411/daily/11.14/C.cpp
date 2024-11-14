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
#define lowbit(x) (x)&(-x)
inline int cnt1(long long x)
{
    int ans = 0;
    while(x)
    {
        x -= lowbit(x);
        ans++;
    }
    return ans;
}
// #define GDB
int main()
{
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int T;
    readi(T);
    while(T--)
    {
        long long n;
        readi(n);
        int ans = 999;
        for(int i = 1; i <= 1e7; i++)
        {
            ans=min(ans,cnt1(n*i));
            if(ans<2)break;
        }
        #ifdef GDB
            printf("%lld\t:\t%d\t@",n,ans);
        for(int i = 1; i <= 1e7; i++)
            if(cnt1(n*i)==ans)
            {
                printf("%d",i);
                break;
            }
        #else
        writei(ans);
        #endif
        putchar('\n');
    }
    return 0;
}