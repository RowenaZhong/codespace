// import bless from molly
#include <bits/stdc++.h>
using namespace std;
namespace IO
{
    template <typename T>
    inline void readi(T &x)
    {
        T f = 1;
        int ch;
        x = 0;
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
            putchar('-'), x = -x;
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
    inline void readl() {}
    inline void writel() {}
    template <typename T, typename... Args>
    inline void readl(T &x, Args &...args)
    {
        readi(x);
        readl(args...);
    }
    template <typename T, typename... Args>
    inline void writel(T x, Args... args)
    {
        writei(x);
        if (sizeof...(args) != 0)
            putchar(' ');
        else
            putchar('\n');
        writel(args...);
    }
}
int T, n, m, v;
const int MAXN = 1e9 + 7, MAXM = 1e5, MOD = 1e9 + 7;
// int f[MAXN], g[MAXN];
map<int, int> force;
int mul(int a, int b)
{
    long long t = a;
    return t * b % MOD;
}
int add(int a, int b)
{
    long long t = a;
    return (a + b) % MOD;
}

const int DimForced = 0, DimUnforced = 1;
int F[2];
int TransForForcedPlace[2][2];
int TransForUnforcedPlace[2][2];

int PowerAns[2][2];
int PowerTmp[2][2];
int MulAns[2][2];
int MulAnsVec[2];
inline void MatCopy(int dest[2][2], const int source[2][2])
{
    dest[0][0] = source[0][0];
    dest[0][1] = source[0][1];
    dest[1][0] = source[1][0];
    dest[1][1] = source[1][1];
}
inline void VecCopy(int dest[2], const int source[2])
{
    dest[0] = source[0];
    dest[1] = source[1];
}

inline void MatMul(const int a[2][2], const int b[2][2])
{
    MulAns[0][0] = add(mul(a[0][0], b[0][0]), mul(a[0][1], b[1][0]));
    MulAns[0][1] = add(mul(a[0][0], b[0][1]), mul(a[0][1], b[1][1]));
    MulAns[1][0] = add(mul(a[1][0], b[0][0]), mul(a[1][1], b[1][0]));
    MulAns[1][1] = add(mul(a[1][0], b[0][1]), mul(a[1][1], b[1][1]));
}

inline void VecMul(const int a[2][2], const int b[2])
{
    MulAnsVec[0] = add(mul(a[0][0], b[0]), mul(a[0][1], b[1]));
    MulAnsVec[1] = add(mul(a[1][0], b[0]), mul(a[1][1], b[1]));
}

void MatPower(const int mat[2][2], int b)
{
    MatCopy(PowerTmp, mat);
    PowerAns[0][0] = 1;
    PowerAns[0][1] = 0;
    PowerAns[1][0] = 0;
    PowerAns[1][1] = 1;
    for (; b; b >>= 1)
    {
        if (b & 1)
        {
            // PowerAns = PowerAns * PowerTmp
            MatMul(PowerAns, PowerTmp);
            MatCopy(PowerAns, MulAns);
        }
        // PowerTmp = PowerTmp * PowerTmp
        MatMul(PowerTmp, PowerTmp);
        MatCopy(PowerTmp, MulAns);
    }
}

inline void solve()
{
    IO::readl(n, m, v);
    TransForForcedPlace[0][0] = add(mul(v, v - 1), 1);
    TransForForcedPlace[0][1] = 0;
    TransForForcedPlace[1][0] = mul(v, v);
    TransForForcedPlace[1][1] = 0;

    TransForUnforcedPlace[0][0] = v;
    TransForUnforcedPlace[0][1] = mul(v, v - 1);
    TransForUnforcedPlace[1][0] = 0;
    TransForUnforcedPlace[1][1] = mul(v, v);

    bool fail = false;
    force = map<int, int>();
    while (m--)
    {
        int x, y;
        IO::readl(x, y);
        if (force.count(x) && force.find(x)->second != y)
            fail = true;
        force[x] = y;
    }
    if (fail)
    {
        IO::writel(0);
        return;
    }
    F[0] = F[1] = 1;
    auto riter = force.rbegin();
    auto lasti = n + 1; // TODO : set last i
    for (; riter != force.rend(); riter++)
    {
        auto i = riter->first;
        if (riter->first == 1)
            break;
        MatPower(TransForUnforcedPlace, lasti - i - 1);
        VecMul(PowerAns, F);
        VecCopy(F, MulAnsVec);
        VecMul(TransForForcedPlace, F);
        VecCopy(F, MulAnsVec);
        lasti = i;
    }
    MatPower(TransForUnforcedPlace, lasti - 2);
    VecMul(PowerAns, F);
    VecCopy(F, MulAnsVec);
    if (force.count(1))
        IO::writel(F[DimForced]);
    else
        IO::writel(F[DimUnforced]);
}
int main()
{
    IO::readi(T);
    while (T--)
        solve();
    return 0;
}
