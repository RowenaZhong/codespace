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
int TBase[3][3] = {1, 0, 1, 1, 1, 0, 0, 1, 1};
int T[3][3];
int Tmp1[3][3];
int Tmp2[3][3];
int F[3];
int A[3];
int n, r, p, s;
void MulIn(int Dst[3][3], const int Src[3][3])
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Tmp1[i][j] = Dst[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Tmp2[i][j] = Src[i][j];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            Dst[i][j] = Tmp1[i][0] * Tmp2[0][j] + Tmp1[i][1] * Tmp2[1][j] +
                        Tmp1[i][2] * Tmp2[2][j];
}
void Mul()
{
    A[0] = T[0][0] * F[0] + T[0][1] * F[1] + T[0][2] * F[2];
    A[1] = T[1][0] * F[0] + T[1][1] * F[1] + T[1][2] * F[2];
    A[2] = T[2][0] * F[0] + T[2][1] * F[1] + T[2][2] * F[2];
}
void calcTrans(int x)
{
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            T[i][j] = (i == j);
    while (x) {
        if (x & 1)
            MulIn(T, TBase);
        MulIn(TBase, TBase);
        x >>= 1;
    }
}
enum class Preference { P = 0, R, S };
map<Preference, int> rnk[21];
void dfs(Preference prefer, int dep)
{
    if (dep == 0) {
        switch (prefer) {
            case Preference::P:
                putchar('P');
                break;

            case Preference::R:
                putchar('R');
                break;

            case Preference::S:
                putchar('S');
                break;
            default:
                break;
        }
        return;
    }
    switch (prefer) {
        case Preference::P:
            if (rnk[dep - 1][Preference::P] > rnk[dep - 1][Preference::R]) {
                dfs(Preference::R, dep - 1);
                dfs(Preference::P, dep - 1);
            } else {
                dfs(Preference::P, dep - 1);
                dfs(Preference::R, dep - 1);
            }
            break;

        case Preference::R:
            if (rnk[dep - 1][Preference::S] > rnk[dep - 1][Preference::R]) {
                dfs(Preference::R, dep - 1);
                dfs(Preference::S, dep - 1);
            } else {
                dfs(Preference::S, dep - 1);
                dfs(Preference::R, dep - 1);
            }
            break;

        case Preference::S:
            if (rnk[dep - 1][Preference::P] > rnk[dep - 1][Preference::S]) {
                dfs(Preference::S, dep - 1);
                dfs(Preference::P, dep - 1);
            } else {
                dfs(Preference::P, dep - 1);
                dfs(Preference::S, dep - 1);
            }
            break;
        default:
            break;
    }
}
void RnkInit()
{
    rnk[0][Preference::P] = 0;
    rnk[0][Preference::R] = 1;
    rnk[0][Preference::S] = 2;
    for (int i = 1; i <= 20; i++) {
        int rnkP, rnkR, rnkS;
        rnkP = min(rnk[i - 1][Preference::P] * 3 + rnk[i - 1][Preference::R],
                   rnk[i - 1][Preference::R] * 3 + rnk[i - 1][Preference::P]);
        rnkR = min(rnk[i - 1][Preference::S] * 3 + rnk[i - 1][Preference::R],
                   rnk[i - 1][Preference::R] * 3 + rnk[i - 1][Preference::S]);
        rnkS = min(rnk[i - 1][Preference::P] * 3 + rnk[i - 1][Preference::S],
                   rnk[i - 1][Preference::S] * 3 + rnk[i - 1][Preference::P]);
        (rnkP > rnkR) ? (++rnk[i][Preference::P]) : (++rnk[i][Preference::R]);
        (rnkP > rnkS) ? (++rnk[i][Preference::P]) : (++rnk[i][Preference::S]);
        (rnkR > rnkS) ? (++rnk[i][Preference::R]) : (++rnk[i][Preference::S]);
    }
}
int main()
{
    freopen("rps.in", "r", stdin);
    freopen("rps.out", "w", stdout);
    IO::readl(r, p, s);
    n = r + p + s;
    int t = n;
    n = 0;
    while (t > 1)
        n++, t >>= 1;
    calcTrans(n);
    RnkInit();
    F[0] = 1, F[1] = 0, F[2] = 0;
    Mul();
    if (A[0] == p && A[1] == r && A[2] == s) {
        dfs(Preference::P, n);
        putchar('\n');
        return 0;
    }
    F[0] = 0, F[1] = 1, F[2] = 0;
    Mul();
    if (A[0] == p && A[1] == r && A[2] == s) {
        dfs(Preference::R, n);
        putchar('\n');
        return 0;
    }
    F[0] = 0, F[1] = 0, F[2] = 1;
    Mul();
    if (A[0] == p && A[1] == r && A[2] == s) {
        dfs(Preference::S, n);
        putchar('\n');
        return 0;
    }
    puts("IMPOSSIBLE");
    return 0;
}
