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
        while (!feof(stdin) && isdigit(ch))
        {
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
    inline void writel() {}
    template <typename T, typename... Args>
    inline void writel(T x, Args... args)
    {
        writei(x);
        putchar(" \n"[sizeof...(args) == 0]);
        writel(args...);
    }
}
const int MAXN = 5e4 + 7, MAXA = 1e6 + 7, MAXP = 1e3 + 3;
int primes[170] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997};
map<int, int> lookup;
int head[MAXP], ver[MAXN], nxt[MAXN], deg[MAXN];
int dis[MAXP];
int n, a[MAXN];
void AddEdge(int u, int v)
{
    static int cnt = 0;
    ver[++cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt;
    deg[v]++;
}
int GetMaxRoute()
{
    queue<int> q;
    for (int i = 1; primes[i]; i++)
        if (deg[i] == 0)
            q.push(i);
    auto ret = int();
    while (!q.empty())
    {
        auto u = q.front();
        q.pop();
        ret = max(ret, dis[u]);
        for (int i = head[u]; i; i = nxt[i])
        {
            auto v = ver[i];
            dis[v] = max(dis[v], dis[u] + 1);
            if (--deg[v] == 0)
                q.push(v);
        }
    }
    return ret;
}
int main()
{
    freopen("chain.in", "r", stdin);
    freopen("chain.out", "w", stdout);
    for (int i = 1; primes[i]; i++)
        lookup[primes[i]] = i;
    IO::readi(n);
    for (int i = 1; i <= n; i++)
    {
        IO::readi(a[i]);
        for (int j = 1; primes[j]; j++)
        {
            if (a[i] % primes[j] == 0)
            {
                if (lookup.count(a[i] / primes[j]))
                    AddEdge(j, lookup[a[i] / primes[j]]);
                break;
            }
        }
    }
    IO::writel(GetMaxRoute());
    return 0;
}
