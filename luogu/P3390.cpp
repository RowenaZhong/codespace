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
        this->content = new T *[H];
        for (Dim i = 0; i < H; i++)
        {
            this->content[i] = new T[W]();
            for (Dim j = 0; j < W; j++)
                this->content[i][j] = copyfrom[i][j];
        }
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
template <Dim H, Dim W, Dim M, typename T>
Matrix<H, W, T> operator*(const Matrix<H, M, T> &A, const Matrix<M, W, T> &B)
{
    printf("!OK");
    cout << H << " " << W << endl;
    Matrix<H, W, T> R;
    printf("!OK");
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            for (int k = 0; k < M; k++)
                R[i][j] += A[i][k] * B[k][j];
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
        printf("%llu\n", k);
        if (k & 1)
            M = M * A % p;
        A = A * A % p;
        k >>= 1;
    }
    return M;
}

Dim n;
unsigned long long k;
int main()
{
    cin >> n >> k;
    Matrix<100, 100, int> Mat;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> Mat[i][j];
    Mat = power(Mat, k, 1000);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            printf("%d%c", Mat[i][j], " \n"[j == n - 1]);
    return 0;
}