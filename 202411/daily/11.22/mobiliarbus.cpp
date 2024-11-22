//molly bless rowena
#include <bits/stdc++.h>
using namespace std;
namespace IO
{
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
inline void readl() {}
template <typename T, typename... Args>
inline void readl(T &x, Args &...args)
{
    readi(x);
    readl(args...);
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
inline void writel() {}
template <typename T, typename... Args>
inline void writel(T x, Args... args)
{
    writei(x);
    putchar(" \n"[sizeof...(args) == 0]);
    writel(args...);
}
} // namespace IO
const int MAXN = 1e6 + 7;
int a[MAXN];
long long n, k;
// int lazy[MAXN<<2];
// inline void Spread(int p)
// {
//     if(lazy[p])
//     {
//         lazy[p*2]+=lazy[p];
//         lazy[p*2+1]+=lazy[p];
//         lazy[p]=0;
//     }
// }
// int Query(int l,int r,int x,int p)
// {
//     if(l==r)return lazy[p];
//     Spread(p);
//     int mid=(l+r)>>1;
//     if(x<=mid)return Query(l,mid,x,p*2);
//     else return Query(mid+1,r,x,p*2+1);
// }
// void Change(int lc,int rc,int offset,int l,int r,int p)
// {
//     if(lc<=l&&r<=rc)
//     {
//         lazy[p]+=offset;
//         return;
//     }
//     Spread(p);
//     int mid=(l+r)>>1;
//     if(lc<=mid)Change(lc,rc,offset,l,mid,p*2);
//     if(rc>mid)Change(lc,rc,offset,mid+1,r,p*2+1);
// }
int cnt2 = 0, l2 = 1;
int pos2[MAXN];
int cnt[3];
// class P{
//     int ver;
//     P* next;
//     P(int v,P*n)
//     {
//         this->ver=v;
//         this->next=n;
//     }
// }
// P* e[MAXN];
int cnt0, cnt1;
int main()
{
    freopen("mobiliarbus.in", "r", stdin);
    freopen("mobiliarbus.out", "w", stdout);
    IO::readl(n, k);
    for (int i = 1; i <= n; i++) {
        IO::readi(a[i]), cnt[a[i]]++;
    }
    if (n <= 1000 && k <= 1000) {
        int cont1 = 0;
        for (int i = 1; i <= n && k; i++) {
            int j;
            switch (a[i]) {
                case 0:
                    j = i - 1;
                    while (j && a[j] == 1 && k) {
                        swap(a[j], a[j + 1]);
                        k--;
                        j--;
                    }
                    break;
                case 1:
                    j = l2;
                    for (j; j <= cnt2; j++) {
                        if (i - pos2[j] <= k) {
                            k -= i - pos2[j];
                            for (int p = i - 1; p >= pos2[j]; p--)
                                swap(a[p], a[p + 1]);
                            for (int p = j; p <= cnt2; p++)
                                pos2[p]++;
                            break;
                        }
                    }
                    l2 = j;
                    break;
                case 2:
                    pos2[++cnt2] = i;
                    break;
            }
        }
        for (int i = 1; i <= n; i++) {
            IO::writei(a[i]);
            putchar(" \n"[i == n]);
        }
        return 0;
    }
    if (n * n <= k) {
        int cnt0 = 0;
        int first2 = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 2) {
                first2 = i;
                break;
            }
            if (a[i] == 0)
                cnt0++;
        }
        for (int i = 1; i <= cnt0; i++)
            putchar('0'), putchar(' ');
        for (int i = 1; i <= cnt[1]; i++)
            putchar('1'), putchar(' ');
        for (int i = first2; i <= n; i++) {
            if (a[i] != 1)
                putchar(a[i] + 0x30), putchar(" \n"[i == n]);
        }
        putchar('\n');
        return 0;
    }
    if (cnt[2] == 0) {
        for (int i = 1; i <= n; i++) {
            if (a[i] == 0) {
                int req = i - (cnt0 + 1);
                if (req <= k) {
                    k -= req;
                    cnt0++;
                } else {
                    int xi = i - k;
                    for (int j = 1; j <= cnt0; j++)
                        putchar('0'), putchar(' ');
                    for (int j = cnt0 + 1; j <= i; j++) {
                        if (j == xi)
                            putchar('0');
                        else
                            putchar('1');
                        putchar(' ');
                    }
                    for (int j = i + 1; j <= n; j++) {
                        putchar(a[i] + 0x30), putchar(" \n"[i == n]);
                    }
                    break;
                }
            }
        }
    }
    return 0;
}
