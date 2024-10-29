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
int s[100005];
string str;
string getstr()
{
    string ret;
    int ch;
    while (ch = getchar(), !islower(ch) && !feof(stdin))
        ;
    while (islower(ch) && !feof(stdin))
    {
        ret.push_back(ch);
        ch = getchar();
    }
    return ret;
}
map<int, int> lasti;
int main()
{
    freopen("easygame.in", "r", stdin);
    freopen("easygame.out", "w", stdout);
    str = getstr();
    int Ans = 0;
    lasti[0] = 0;
    for (int i = 0; i < 26; i++)
        lasti[1 << i] = 0;
    for (int i = 1; i <= str.size(); i++)
    {
        char ch = str[i - 1];
        s[i] = s[i - 1] ^ (1 << (ch - 'a'));
        if (lasti.count(s[i]))
        {
            Ans = max(Ans, i - lasti[s[i]]);
        }
        else
            lasti[s[i]] = i;
        for (int j = 0; j < 26; j++)
        {
            int t = s[i] ^ (1 << j);
            if (!lasti.count(t))
                lasti[t] = i;
        }
    }
    writei(Ans);
    putchar('\n');
    // for (int len = str.size(); len >= 1; len--)
    // {
    //     for (int l = 0; l + len <= str.size(); l++)
    //     {
    //         if (count1(s[l + len] ^ s[l]) <= 1)
    //         {
    //             writei(len);
    //             return 0;
    //         }
    //     }
    // }
    return 0;
}