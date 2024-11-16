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
typedef unsigned long long ull;
const int MAXN = 1e4 + 7;
priority_queue<ull> down;
priority_queue<ull> up;
ull mid;
int n;
ull a[MAXN];
ull ans;
int main()
{
    freopen("book.in", "r", stdin);
    freopen("book.out", "w", stdout);
    readi(n);
    for (int i = 1; i <= n; i++)
        readi(a[i]);
    for (int l = 1; l <= n; l++) {
        ans += l * l * a[l];
        up = down = priority_queue<ull>();
        mid = a[l];
        for (int len = 1; l + len <= n; len++) {
            auto r = l + len;
            auto t = a[r];
            if (len & 1) {
                if (t > mid)
                    swap(t, mid);
                down.push(t);
                if (up.size() && mid > -up.top()) {
                    t = -up.top();
                    swap(mid, t);
                    up.pop();
                    up.push(-t);
                }
            } else {
                if (t < mid)
                    swap(t, mid);
                up.push(-t);
                if (down.size() && mid < down.top()) {
                    t = down.top();
                    swap(mid, t);
                    down.pop();
                    down.push(t);
                }
                ans += l * r * mid;
            }
        }
    }
    writel(ans);
    return 0;
}
