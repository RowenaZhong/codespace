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
const int MAXN = 1e5 + 7, MOD = 1e9 + 7;
int a[MAXN], n, m;
class SegNode
{
private:
    int _sum;
    int _sqSum;
    SegNode *_lp;
    SegNode *_rp;
    int _l, _r;

public:
    static int arg1;
    static int arg2;
    SegNode(int l, int r)
    {
        this->_l = l, this->_r = r;
        if (l == r)
            this->_sum = a[l],
            this->_sqSum = (long long)a[l] * a[l] % MOD,
            this->_lp = this->_rp = NULL;
        else
        {
            this->_lp = new SegNode(l, l + r >> 1);
            this->_rp = new SegNode((l + r >> 1) + 1, r);
            this->_sum = (this->_lp->_sum + this->_rp->_sum) % MOD;
            this->_sqSum = (this->_lp->_sqSum + this->_rp->_sqSum) % MOD;
        }
    }
    ~SegNode()
    {
        if (this->_lp)
            delete this->_lp;
        if (this->_rp)
            delete this->_rp;
        this->_lp = this->_rp = NULL;
    }
    int QuerySum()
    {
        if (SegNode::arg1 <= this->_l && this->_r <= SegNode::arg2)
            return this->_sum;
        int mid = _l + _r >> 1;
        int ret = 0;
        if (SegNode::arg1 <= mid)
            (ret += this->_lp->QuerySum()) %= MOD;
        if (mid < SegNode::arg2)
            (ret += this->_rp->QuerySum()) %= MOD;
        return ret;
    }
    int QuerySqSum()
    {
        if (arg1 <= this->_l && this->_r <= arg2)
            return this->_sqSum;
        int mid = this->_l + this->_r >> 1;
        int ret = 0;
        if (SegNode::arg1 <= mid)
            (ret += this->_lp->QuerySqSum()) %= MOD;
        if (mid < SegNode::arg2)
            (ret += this->_rp->QuerySqSum()) %= MOD;
        return ret;
    }
    void Set()
    {
        if (this->_l == this->_r)
            this->_sum = SegNode::arg2,
            this->_sqSum = (long long)SegNode::arg2 * SegNode::arg2 % MOD;
        int mid = this->_l + this->_r >> 1;
        if (SegNode::arg1 <= mid)
            this->_lp->Set();
        else
            this->_rp->Set();
    }
};
int SegNode::arg1;
int SegNode::arg2;
SegNode *segroot;
bool enableOpt3;
int main()
{
    freopen("sequence.in", "r", stdin);
    freopen("sequence.out", "w", stdout);
    readi(n), readi(m);
    for (int i = 1; i <= n; i++)
        readi(a[i]);
    enableOpt3 = (n <= 100);
    if (!enableOpt3)
        segroot = new SegNode(1, n);
    while (m--)
    {
        int opt, l, r, p, pos, v, sum;
        readi(opt);
        switch (opt)
        {
        case 1:
            readi(l), readi(r);
            if (enableOpt3)
            {
                sum = 0;
                for (int i = l; i <= r; i++)
                    (sum += a[i]) %= MOD;
                writei(sum);
            }
            else
            {
                SegNode::arg1 = l, SegNode::arg2 = r;
                writei(segroot->QuerySum());
            }
            putchar('\n');
            break;

        case 2:
            readi(l), readi(r);
            if (enableOpt3)
            {
                sum = 0;
                for (int i = l; i <= r; i++)
                    (sum += (long long)a[i] * a[i] % MOD) %= MOD;
                writei(sum);
            }
            else
            {
                SegNode::arg1 = l, SegNode::arg2 = r;
                writei(segroot->QuerySqSum());
            }
            putchar('\n');
            break;

        case 3:
            readi(l), readi(r), readi(p);
            if (enableOpt3)
            {
                for (int i = l; i <= r; i++)
                    a[i] = floor((double)a[i] / p);
            }
            break;
        case 4:
            readi(pos), readi(v);
            if (enableOpt3)
                a[pos] = v;
            else
            {
                SegNode::arg1 = pos, SegNode::arg2 = v;
                segroot->Set();
            }
            break;
        default:
            break;
        }
    }
    if (enableOpt3)
        delete segroot;
    return 0;
}
