#include <bits/stdc++.h>
using namespace std;
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
const unsigned long long Mod = 1000;
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
Matrix<H, W, T> operator%(const Matrix<H, W, T> &A, T p)
{
    Matrix<H, W, T> R;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            R[i][j] = A[i][j] % p;
    return R;
}
template <Dim H, typename T>
Matrix<H, H, T> power(const Matrix<H, H, T> &MA, unsigned long long k, T p)
{
    Matrix<H, H, T> M;
    Matrix<H, H, T> A = MA;
    for (int i = 0; i < H; i++)
        M[i][i] = 1;
    while (k)
    {
        if (k & 1)
            M = M * A;
        A = A * A;
        k >>= 1;
    }
    return M;
}

unsigned long long k;
int main()
{
    cin >> k;
    Matrix<5, 5, LDim> F;
    F[0][1] = 2;
    F[1][0] = F[1][2] = 1;
    F[2][1] = F[2][3] = 1;
    F[3][2] = 1;
    F[4][3] = 2;
    Matrix<5, 1, LDim> T;
    T[0][0] = 1;
    T = power(F, k, (LDim)1000) * T;
    printf("%llu\n", T[4][0]);
    return 0;
}