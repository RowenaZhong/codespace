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
char str[30];
int k = 0, len;
int main()
{
    freopen("sadyx.in", "r", stdin);
    freopen("sadyx.out", "w", stdout);
    int T;
    readi(T);
    while(T--)
    {
        scanf("%s", str);
        len = strlen(str);
        k = 0;
        bool meet_a = false, possi = true;
        for (int i = 0; i < len; i++)
        {
            k |= 1 << (str[i] - 'a');
            if(i)
            {
                if(meet_a)
                {
                    if(str[i] <= str[i - 1])
                    {
                        possi = false;
                        break;
                    }
                }
                else if(str[i] >= str[i - 1])
                {
                    possi = false;
                    break;
                }
            }
            if(str[i] == 'a')
                meet_a = true;
        }
        if(k + 1 != (1 << len))possi = false;
        puts(possi ? "yes" : "no");
    }
    return 0;
}