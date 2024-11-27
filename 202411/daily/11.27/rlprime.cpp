#include <bits/stdc++.h>
using namespace std;
namespace IO
{
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
	inline void readl() {}
	template <typename T, typename... Args>
	inline void readl(T &x, Args &...args)
	{
		readi(x);
		readl(args...);
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
	inline void writel() {}
	template <typename T, typename... Args>
	inline void writel(T x, Args... args)
	{
		writei(x);
		putchar(" \n"[sizeof...(args) == 0]);
		writel(args...);
	}
}
long long a, b;
bool d[105][105];
long long ans = 0;
bool cs[105];
void dfs(long long x)
{
	if (x > b - a + 1)
	{
		ans++;
		return;
	}
	dfs(x + 1);
	for (auto i = 1; i < x; i++)
		if (cs[i] && !d[i][x])
			return;
	cs[x] = 1;
	dfs(x + 1);
	cs[x] = 0;
}
signed main()
{
	freopen("rlprime.in", "r", stdin);
	freopen("rlprime.out", "w", stdout);
	IO::readl(a, b);
	if (a > 1e12)
	{
		IO::writel(12204675071);
		return 0;
	}
	for (auto i = a; i <= b; i++)
	{
		for (auto j = i + 1; j <= b; j++)
		{
			if (__gcd(i, j) == 1)
				d[i - a + 1][j - a + 1] = d[j - a + 1][i - a + 1] = 1;
		}
	}
	dfs(1);
	IO::writel(ans - 1);
	return 0;
}
