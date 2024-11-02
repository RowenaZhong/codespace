#include <iostream>
#include <algorithm>
using namespace std;
int T, n;
class P
{
public:
    int x, y, z;
    P() {}
    P(int a, int b, int c)
    {
        this->x = a;
        this->y = b;
        this->z = c;
    }
    bool operator<(P &x)
    {
        return this->z < x.z;
    }
};
template <typename T>
inline void readi(T &r)
{
    T x = 0, f = 1;
    char ch = getchar();
    while (!isdigit(ch) && ch != '-')
        ch = getchar();
    if (ch == '-')
        f = -f, ch = getchar();
    while (isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    r = x * f;
}
template <typename T>
inline void writei(T x)
{
    if (x < 0)
        putchar('-'), x = -x;
    else if (x == 0)
    {
        putchar('0');
        return;
    }
    T t = 1;
    while (t <= x)
        t = (t << 3) + (t << 1);
    t = t / 10;
    while (t)
    {
        putchar(x / t + 0x30);
        x = x % t;
        t = t / 10;
    }
    return;
}
int fa[6007], sz[6007];
P nodes[6007];
int getf(int x)
{
    if (fa[x] == x)
        return x;
    return fa[x] = getf(fa[x]);
}
int main()
{
    readi(T);
    while (T--)
    {
        readi(n);
        for (int i = 1; i < n; i++)
        {
            int x, y, z;
            readi(x);
            readi(y);
            readi(z);
            nodes[i] = P(x, y, z);
        }
        for (int i = 1; i <= n; i++)
            fa[i] = i, sz[i] = 1;
        sort(nodes + 1, nodes + n);
        long long ans = 0ll;
        for (int i = 1; i < n; i++)
        {
            ans += ((long long)(sz[getf(nodes[i].x)]) * sz[getf(nodes[i].y)] - 1) * (nodes[i].z + 1);
            sz[getf(nodes[i].x)] += sz[getf(nodes[i].y)];
            fa[getf(nodes[i].y)] = getf(nodes[i].x);
        }
        writei(ans);
        putchar('\n');
    }
    return 0;
}