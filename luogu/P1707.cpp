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
unsigned long long Mod;
LDim Mul(LDim a, LDim b)
{
    LDim ret = 0;
    while (b)
    {
        if (b & 1)
            ret = (ret + a) % Mod;
        a = (a << 1) % Mod;
        b >>= 1;
    }
    return ret;
}
template <Dim H, Dim W, Dim M, typename T>
Matrix<H, W, T> operator*(const Matrix<H, M, T> &A, const Matrix<M, W, T> &B)
{
    Matrix<H, W, T> R;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            for (int k = 0; k < M; k++)
                R[i][j] = (R[i][j] + Mul(A[i][k], B[k][j])) % Mod;
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
LDim n, m;
LDim p, q, r, t;
LDim u, v, w;
LDim x, y, z;
int main()
{
    Matrix<11, 1, LDim> T;
    Matrix<11, 11, LDim> F;
    cin >> n >> m;
    cin >> p >> q >> r >> t;
    cin >> u >> v >> w;
    cin >> x >> y >> z;
    Mod = m;
    T[0][0] = T[2][0] = T[4][0] = 3;
    T[1][0] = T[3][0] = T[5][0] = 1;
    T[6][0] = 1;
    T[7][0] = 1;
    T[8][0] = w % Mod;
    T[9][0] = z % Mod;
    T[10][0] = 1;
    F[0][0] = p;
    F[0][1] = q;
    F[0][2] = 1;
    F[0][4] = 1;
    F[0][6] = r;
    F[0][7] = t;
    F[0][10] = 1;
    F[1][0] = 1;
    F[2][0] = F[2][4] = F[2][8] = 1;
    F[2][2] = u;
    F[2][3] = v;
    F[3][2] = 1;
    F[4][0] = F[4][2] = F[4][7] = F[4][9] = 1;
    F[4][4] = x;
    F[4][5] = y;
    F[4][9] = 2;
    F[5][4] = 1;
    F[6][6] = F[6][10] = 1;
    F[6][7] = 2;
    F[7][7] = 1;
    F[7][10] = 1;
    F[8][8] = w;
    F[9][9] = z;
    F[10][10] = 1;
    T = power(F, n - 2) * T;
    for (int i = 0; i < 11; i++)
    {
        printf("%llu\n", T[i][0]);
    }
    printf("nodgd %llu\n", T[0][0]);
    printf("Ciocio %llu\n", T[2][0]);
    printf("Nicole %llu\n", T[4][0]);
    return 0;
}