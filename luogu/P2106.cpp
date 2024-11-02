#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long LDim;
typedef unsigned short Dim;
const int Mod = 1000000007;
template <Dim R, Dim C, typename T>
class Matrix
{
public:
    T **content;
    Matrix()
    {
        this->content = new T *[R];
        for (Dim i = 0; i < R; i++)
            this->content[i] = new T[C]();
    }
    Matrix(const Matrix<R, C, T> &mat)
    {
        this->content = new T *[R];
        for (Dim i = 0; i < R; i++)
            this->content[i] = new T[C]();
        for (Dim i = 0; i < R; i++)
            for (Dim j = 0; j < C; j++)
                this->content[i][j] = mat[i][j];
    }
    const Matrix &operator=(const Matrix<R, C, T> &mat)
    {
        for (Dim i = 0; i < R; i++)
            for (Dim j = 0; j < C; j++)
                this->content[i][j] = mat[i][j];
        return mat;
    }
    T *operator[](const Dim x)
    {
        return this->content[x];
    }
    const T *operator[](const Dim x) const
    {
        return this->content[x];
    }
    ~Matrix()
    {
        for (Dim i = 0; i < R; i++)
            delete[] this->content[i];
        delete[] this->content;
    }
};
template <Dim H, Dim W, Dim K, typename T>
const Matrix<H, W, T> operator*(const Matrix<H, K, T> &A, const Matrix<K, W, T> &B)
{
    Matrix<H, W, T> R;
    for (Dim r = 0; r < H; r++)
        for (Dim c = 0; c < W; c++)
        {
            R[r][c] = 0;
            for (Dim k = 0; k < K; k++)
                (R[r][c] += A[r][k] * B[k][c] % Mod) %= Mod;
        }
    return R;
}
template <Dim a, typename T>
Matrix<a, a, T> &operator*=(Matrix<a, a, T> &A, const Matrix<a, a, T> &B)
{
    A = A * B;
    return A;
}
template <Dim a, typename T>
const Matrix<a, a, T> operator^(const Matrix<a, a, T> &A, LDim b)
{
    Matrix<a, a, T> R, tA = A;
    for (Dim i = 0; i < a; i++)
        R[i][i] = 1;
    while (b)
    {
        if (b & 1)
            R *= tA;
        tA *= tA;
        b >>= 1;
    }
    return R;
}
Matrix<10, 10, LDim> F;
Matrix<10, 1, LDim> T;
int main()
{
    LDim k;
    cin >> k;
    for (int i = 0; i <= 9; i++)
        T[i][0] = 1;
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            F[i][j] = (abs(i - j) <= 2);
    T = (F ^ (k - 1)) * T;
    LDim Ans(0);
    for (Dim i = (k > 1); i < 10; i++)
        (Ans += T[i][0]) %= Mod;
    cout << Ans << endl;
    return 0;
}