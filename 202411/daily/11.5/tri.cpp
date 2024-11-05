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
typedef long long ll;
const int MAXN = 1e5;
ll cnt_edge[MAXN];
ll n, m;


int main()
{
    freopen("tri.in", "r", stdin);
    freopen("tri.out", "w", stdout);
    readi(n), readi(m);
	int a, b;
	for (int i = 0; i < m; i++)
	{
        readi(a), readi(b);
        cnt_edge[a]++;
        cnt_edge[b]++;
	}
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		sum += cnt_edge[i] * (n - cnt_edge[i] - 1);
	cout << n * (n - 1) /2 * (n - 2) / 3 - sum /2 << endl;

}

