#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7, P = 131;
char str[MAXN];
unsigned long long hsh[MAXN], rhsh[MAXN];
int sz = 0;
unsigned long long power[MAXN];
inline void Hash()
{
    int i = 1;
    for (i = 1; *(str + i); i++)
        hsh[i] = hsh[i - 1] * P + str[i] - 0x60;
    sz = i - 1;
}
inline void rHash()
{
    rhsh[sz + 1] = 0;
    for (int i = sz; i > 0; i--)
        rhsh[i] = rhsh[i + 1] * P + str[i] - 0x60;
}
inline unsigned long long h(int l, int r)
{
    return hsh[r] - hsh[l - 1] * power[r - l + 1];
}
inline unsigned long long rh(int r, int l)
{
    return rhsh[l] - rhsh[r + 1] * power[r - l + 1];
}
inline int s1(int i)
{
    int smax = min(i - 1, sz - i);
    int p = 1, s = 0;
    while (p)
    {
        if (s + p <= smax && h(i - (s + p), i - 1) == rh(i + (s + p), i + 1))
        {
            s += p;
            p <<= 1;
        }
        else
            p >>= 1;
    }
    return (s << 1) | 1;
}
inline int s2(int i)
{
    int smax = min(i, sz - i);
    int p = 1, s = 0;
    while (p)
    {
        if (s + p <= smax && h(i - (s + p) + 1, i) == rh(i + (s + p), i + 1))
        {
            s += p;
            p <<= 1;
        }
        else
            p >>= 1;
    }
    return s << 1;
}
int main()
{
    power[0] = 1llu;
    for (int i = 1; i <= (MAXN >> 1); i++)
        power[i] = power[i - 1] * P;
    int T = 0;
    while (1)
    {
        int Ans = 0;
        scanf("%s", str + 1);
        if (*(str + 1) == 'E')
            break;
        Hash();
        rHash();
        for (int i = 1; i <= sz; i++)
        {
            Ans = max(Ans, s1(i));
            Ans = max(Ans, s2(i));
        }
        printf("Case %d: %d\n", ++T, Ans);
    }
    return 0;
}