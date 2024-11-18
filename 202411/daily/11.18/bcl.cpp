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
char s[2005];
string str[2005];
// Data dstr1[2005],dstr2[2005];
//typedef unsigned long long Data;
//Data D1=47,D2=103;
int n;
int main()
{
    freopen("bcl.in", "r", stdin);
    freopen("bcl.out", "w", stdout);
    readi(n);
    for (int i = 1; i <= n; i++) {
        char ch;
        scanf("\n%c", s + i);
        str[i].push_back(s[i]);
    }
    for (int len = 1; len < n; len++) {
        for (int l = 1; l + len <= n; l++) {
            auto r = l + len;
            if (s[l] < s[r])
                str[l] = s[l] + str[l + 1];
            else if (s[l] > s[r])
                str[l] = s[r] + str[l];
            else
                str[l] = s[l] + min(str[l], str[l + 1]);
        }
    }
    cout << str[1] << endl;
    return 0;
}
