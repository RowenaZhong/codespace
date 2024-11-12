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
    while (!feof(stdin) && isdigit(ch)) {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
template <typename T>
inline void writei(T x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p) {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}

int main()
{
    freopen("ball.in", "r", stdin);
    freopen("ball.out", "w", stdout);
    int T;
    readi(T);
    while (T--) {
        long long color[3];
        readi(color[0]);
        readi(color[1]);
        readi(color[2]);
        sort(color, color + 3);
        if (color[2] == color[0])
            putchar('6');
        else if (color[2] == color[0] + 1)
            if (color[0] + color[1] + color[2] == 1)
                putchar('1');
            else
                putchar('2');
        else
            putchar('0');
        putchar('\n');
    }
    return 0;
}