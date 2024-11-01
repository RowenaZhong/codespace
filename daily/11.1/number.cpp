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
const int MAXN = 1e5 + 7;
char s1[MAXN], s2[MAXN];
unsigned long long a1[MAXN], a2[MAXN];
int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    scanf("%s\n%s", s1, s2);
    int len1 = strlen(s1), len2 = strlen(s2);
    reverse(s1, s1 + len1);
    reverse(s2, s2 + len2);
    for (int i = 0; i < len1; i++)
        a1[i] = s1[i] - '0';
    for (int i = 0; i < len2; i++)
        a2[i] = s2[i] - '0';
    for (int i = len1 - 1; i >= 2; i--)
        a1[i - 2] += a1[i], a1[i - 1]+=a1[i];
    for (int i = len2 - 1; i >= 2; i--)
        a2[i - 2] += a2[i], a2[i - 1]+=a2[i];
    int a = a1[1] - a2[1], b = a1[0] - a2[0];
    double ans = a;
    ans = ans * (sqrt(5) + 1) / 2 + b;
    if(ans > 1e-6) puts(">");
    else if(ans < -1e-6) puts("<");
    else puts("=");
    return 0;
}