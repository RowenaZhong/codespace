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

typedef unsigned short Dim;
typedef unsigned long long LDim;
template <Dim H, Dim W, typename T = LDim>
class Matrix
{
public:
    T **content;
    Matrix()
    {
        content = new T *[H];
        for (int i = 0; i < H; i++)
        {
            content[i] = new T[W];
        }
    }
    ~Matrix()
    {
        for (int i = 0; i < H; i++)
            delete[] content[i];
        delete[] content;
    }
    Matrix(const Matrix<H, W, T> &m)
    {
        content = new T *[H];
        for (int i = 0; i < H; i++)
        {
            content[i] = new T[W];
            for (int j = 0; j < W; j++)
                content[i][j] = m.content[i][j];
        }
    }
    const T *operator[](Dim h) const
    {
        return this->content[h];
    }
    T *operator[](Dim h)
    {
        return this->content[h];
    }
    const Matrix<H, W, T> &operator=(const Matrix<H, W, T> &a)
    {
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                this->content[i][j] = a[i][j];
            }
        }
        return *this;
    }
};
template <Dim A, Dim B, Dim C, typename T>
Matrix<A, C, T> operator*(const Matrix<A, B, T> &a, const Matrix<B, C, T> &b)
{
    Matrix<A, C, T> ret;
    for (Dim i = 0; i < A; i++)
    {
        for (Dim j = 0; j < C; j++)
        {
            ret[i][j] = T();
            for (Dim k = 0; k < B; k++)
                ret[i][j] += a[i][k] * b[k][j];
        }
    }
    return ret;
}
template <Dim A, Dim B, typename T>
Matrix<A, B, T> operator%(const Matrix<A, B, T> &a, T p)
{
    Matrix<A, B, T> ret;
    for (Dim i = 0; i < A; i++)
    {
        for (Dim j = 0; j < B; j++)
        {
            ret[i][j] = a[i][j] % p;
        }
    }
    return ret;
}
template <Dim A, Dim B, typename T>
Matrix<A, B, T> operator+(const Matrix<A, B, T> &a, const Matrix<A, B, T> &b)
{
    Matrix<A, B, T> ret;
    for (Dim i = 0; i < A; i++)
    {
        for (Dim j = 0; j < B; j++)
        {
            ret[i][j] = a[i][j] + b[i][j];
        }
    }
    return ret;
}
template <Dim A, Dim B, typename T>
Matrix<A, B, T> operator-(const Matrix<A, B, T> &a, const Matrix<A, B, T> &b)
{
    Matrix<A, B, T> ret;
    for (Dim i = 0; i < A; i++)
    {
        for (Dim j = 0; j < B; j++)
        {
            ret[i][j] = a[i][j] - b[i][j];
        }
    }
    return ret;
}
template <Dim A, Dim B, typename T>
Matrix<A, B, T> power(Matrix<A, B, T> MA, LDim b, T p)
{
    // cerr << __LINE__ << endl;
    Matrix<A, B, T> ret;
    for (int i = 0; i < A; i++)
        for (int j = 0; j < B; j++)
            ret[i][j] = (i == j);
    // cerr << __LINE__ << endl;
    while (b)
    {
        if (b & 1)
            ret = ret * MA % p;
        b >>= 1;
        MA = MA * MA % p;
    }
    // cerr << __LINE__ << endl;
    return ret;
}
int main()
{
    Matrix<2, 2> M;
    readi(M.content[0][0]);
    readi(M.content[0][1]);
    M.content[1][0] = 1;
    M.content[1][1] = 0;
    Matrix<2, 1> Input;
    readi(Input.content[1][0]); // a1
    readi(Input.content[0][0]); // a2
    Matrix<2, 1> Ans;
    LDim n, m;
    readi(n);
    readi(m);
    if (n == 1)
    {
        writei(Input.content[1][0] % m);
        return 0;
    }
    // cerr << __LINE__ << endl;
    Ans = power(M, n - 2, m) * Input % m;
    writei(Ans.content[0][0]);
    puts("");
    return 0;
}