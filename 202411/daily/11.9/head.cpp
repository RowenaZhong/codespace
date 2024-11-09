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
const int MAXN=20,MOD=1e9+7;
bool roped[MAXN][MAXN];
long long power(long long a,long long b)
{
    long long ret=1;
    while(b)
    {
        if(b&1)(ret*=a)%=MOD;
        (a*=a)%=MOD;
        b>>=1;
    }
    return ret;
}
int n,m,k;
int main()
{
    freopen("head.in", "r", stdin);
    freopen("head.out", "w", stdout);
    readi(n),readi(m),readi(k);
    assert(n<=20);
    while(m--)
    {
        int a,b;
        readi(a),readi(b);
        a--,b--;
        roped[a][b]=roped[b][a]=true;
    }
    int generalSum=0,currentSum;
    for(int i=0;i<1<<n;i++)
    {
        currentSum=0;
        for(int j=0;j<n;j++)
            for(int k=j+1;k<n;k++)
                if(roped[j][k]&&(i&(1<<j))&&(i&(1<<k)))
                    currentSum++;
        (generalSum+=power(currentSum,k))%=MOD;
    }
    writei(generalSum);
    putchar('\n');
    return 0;
}
