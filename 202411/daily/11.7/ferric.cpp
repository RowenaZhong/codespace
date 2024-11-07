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
int n, k;
long long d[20];
void dfs(int x, int t)
{
    if(t == 0)
    {
        d[x]++;
        return;
    }
    if(x == 1)
    {
        d[x]++;
        dfs(x + 1, t - 1);
    }
    else if(x == n)
    {
        d[x]++;
        dfs(x - 1, t - 1);
    }
    else
    {
        d[x] += 2;
        dfs(x - 1, t - 1);
        dfs(x + 1, t - 1);
    }
}
typedef unsigned short Dim;
typedef unsigned long long LDim;
template <Dim H, Dim W, typename T>
class Matrix
{
public:
    T **content;
    Matrix()
    {
        this->content = new T *[H];
        for (Dim i = 0; i < H; i++)
            this->content[i] = new T[W]();
    }
    ~Matrix()
    {
        for (Dim i = 0; i < H; i++)
            delete[] this->content[i];
        delete[] this->content;
    }
    Matrix(const Matrix<H, W, T> &copyfrom)
    {
        this->content = new T *[H];
        for (Dim i = 0; i < H; i++)
        {
            this->content[i] = new T[W]();
            for (Dim j = 0; j < W; j++)
                this->content[i][j] = copyfrom[i][j];
        }
    }
    const Matrix &operator=(const Matrix<H, W, T> &copyfrom)
    {
        for (Dim i = 0; i < H; i++)
        {
            for (Dim j = 0; j < W; j++)
                this->content[i][j] = copyfrom[i][j];
        }
        return *this;
    }
    T *operator[](Dim h)
    {
        return (this->content[h]);
    }
    const T *operator[](Dim h) const
    {
        return (this->content[h]);
    }
};
const unsigned long long Mod = 19260817;
template <Dim H, Dim W, Dim M, typename T>
Matrix<H, W, T> operator*(const Matrix<H, M, T> &A, const Matrix<M, W, T> &B)
{
    Matrix<H, W, T> R;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            for (int k = 0; k < M; k++)
                R[i][j] = (R[i][j] + A[i][k] * B[k][j] % Mod) % Mod;
    return R;
}
template <Dim H, Dim W, typename T>
Matrix<H, W, T> operator+(const Matrix<H, W, T> &A, const Matrix<H, W, T> &B)
{
    Matrix<H, W, T> R;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            R[i][j] = (A[i][j] + B[i][j]) % Mod;
    return R;
}
Matrix<1,1,LDim> Ans;
Matrix<200,200,LDim> F;
Matrix<200,200,LDim> MF;
Matrix<200,200,LDim> SF;
Matrix<200,1,LDim> P;
Matrix<1,200,LDim>A;
void solve()
{
    readi(n), readi(k);
    assert(n <= 200);
    for(int i = 0; i < n; i++)MF[i][i] =  1;
    for(int i = 0; i < n; i++)
    {
        if(i)F[i][i - 1] = 1;
        if(i != n - 1)F[i][i + 1] = 1;
    }
    for(int i = 0; i <= k; i++)
    {
        SF = SF + MF;
        MF = MF * F;
    }
    for(int i = 0; i < n; i++)P[i][i] = 1;
    for(int i = 0; i < n; i++)readi(A[0][i]);
    Ans = A * SF * P;
    writei(Ans[0][0]);
    putchar('\n');
}
int main()
{
    freopen("ferric.in", "r", stdin);
    freopen("ferric.out", "w", stdout);
    int T;
    T = 1;
    while(T--)
        solve();
    return 0;
}