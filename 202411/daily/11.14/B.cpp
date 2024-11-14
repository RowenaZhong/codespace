#include <bits/stdc++.h>
using namespace std;
struct FastIO {
    static const int S = 1e7;
    int wpos;
    char wbuf[S];
    FastIO() : wpos(0) {}
    inline int xchar()
    {
        static char buf[S];
        static int len = 0, pos = 0;
        if (pos == len)
            pos = 0, len = fread(buf, 1, S, stdin);
        if (pos == len)
            exit(0);
        return buf[pos++];
    }
    inline int xint()
    {
        int s = 1, c = xchar(), x = 0;
        while (c <= 32)
            c = xchar();
        if (c == '-')
            s = -1, c = xchar();
        for (; '0' <= c && c <= '9'; c = xchar())
            x = x * 10 + c - '0';
        return x * s;
    }
    inline void wchar(int x)
    {
        if (wpos == S)
            fwrite(wbuf, 1, S, stdout), wpos = 0;
        wbuf[wpos++] = x;
    }
    inline void wstring(const char *s)
    {
        while (*s)
            wchar(*s++);
    }
    ~FastIO()
    {
        if (wpos)
            fwrite(wbuf, 1, wpos, stdout), wpos = 0;
    }
} io;
const int MAXN = 500;
int A[MAXN][MAXN], B[MAXN][MAXN], C[MAXN][MAXN];
int n;
bool Check()
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++)
                sum += A[i][k] * B[k][j];
            if (sum != C[i][j])
                return false;
        }
    }
    return true;
}
int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T = io.xint();
    while (T--) {
        n = io.xint();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                A[i][j] = io.xint();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                B[i][j] = io.xint();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                C[i][j] = io.xint();
        puts(Check() ? "true" : "false");
    }
    return 0;
}
