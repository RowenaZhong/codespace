#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
class Matrix
{
    vector<vector<int>> _val;
    int _n, _m;

public:
    Matrix(int n, int m) : _n(n), _m(m)
    {
        _val.resize(n);
        for (int i = 0; i < n; i++)
            _val[i].resize(m);
    }
    int &at(int i, int j)
    {
        return _val[i][j];
    }
    const int &at(int i, int j) const
    {
        return _val[i][j];
    }
    Matrix operator*(const Matrix &b)
    {
        assert(this->_m == b._n);
        Matrix ans(this->_n, b._m);
        for (int i = 0; i < this->_n; i++)
            for (int j = 0; j < b._m; j++)
                for (int k = 0; k < this->_m; k++)
                    ans.at(i, j) = (ans.at(i, j) + ((long long)(this->at(i, k)) * b.at(k, j) % MOD)) % MOD;
        return ans;
    }
    Matrix power(long long k)
    {
        assert(this->_n == this->_m);
        assert(k >= 0);
        Matrix Ans(this->_n, this->_n);
        for (int i = 0; i < _n; i++)
            Ans.at(i, i) = 1;
        Matrix P = *this;
        while (k)
        {
            if (k & 1)
                Ans = Ans * P;
            P = P * P;
            k >>= 1;
        }
        return Ans;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long k;
    cin >> n >> k;
    Matrix A(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A.at(i, j);
    auto Ans = A.power(k);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cout << Ans.at(i, j) << " \n"[j == n - 1];
    return 0;
}