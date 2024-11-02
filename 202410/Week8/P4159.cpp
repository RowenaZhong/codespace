#include <bits/stdc++.h>
using namespace std;
typedef unsigned short Dim;
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
        // cerr << "!" << __LINE__ << endl;
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
        // cerr << "!" << __LINE__ << endl;
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
const unsigned long long Mod = 2009;
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
Matrix<H, H, T> power(const Matrix<H, H, T> &MA, unsigned long long k)
{
    Matrix<H, H, T> M;
    Matrix<H, H, T> A = MA;
    for (int i = 0; i < H; i++)
        M[i][i] = 1;
    while (k)
    {
        // printf("%llu\n", k);
        if (k & 1)
            M = M * A;
        A = A * A;
        k >>= 1;
    }
    // cerr << __LINE__ << endl;
    return M;
}
Dim N;
int DimT;
#define get_pos(n, t) 10 * (t) + (n) - 1
int main()
{
    cin >> N >> DimT;
    Matrix<100, 100, Dim> F;
    Matrix<100, 1, Dim> T;
    T[get_pos(1, 0)][0] = 1;
    for (int t = 1; t <= 8; t++)
    {
        for (int n = 1; n <= 10; n++)
        {
            F[get_pos(n, t)][get_pos(n, t - 1)] = 1;
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int t;
            scanf("%1d", &t);
            if (t > 0)
                F[get_pos(j, 0)][get_pos(i, t - 1)] = 1;
        }
    }
    T = power(F, DimT) * T;
    cout << T[get_pos(N, 0)][0] << endl;
    return 0;
}