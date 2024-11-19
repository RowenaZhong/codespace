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
    while (!feof(stdin) && isdigit(ch)) {
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
inline void writel() {}
template <typename T, typename... Args>
inline void writel(T x, Args... args)
{
    writei(x);
    putchar(" \n"[sizeof...(args) == 0]);
    writel(args...);
}
} // namespace IO

const int MAXN = 2e6 + 7;
bool doorOpenedHistory[MAXN];
bool doorOpened[MAXN];
bool buttonPressed[MAXN];
int doorPosition[MAXN];
int buttonPosition[MAXN];
int n, cntDoor, cntButton;
void dfs()
{
    for (int i = 1; i <= cntButton; i++) {
        if (buttonPressed[i] == false) {
            buttonPressed[i] = true;
            int l = lower_bound(doorPosition + 1, doorPosition + cntDoor + 1,
                                buttonPosition[i]) -
                    doorPosition - 1;
            auto r = l + 1;
            int x;
            while (l && doorOpened[l])
                l--;
            while (r <= cntDoor && doorOpened[r])
                r++;
            if (doorOpened[l] && doorOpened[r])
                return;
            if (doorOpened[l])
                x = r;
            else if (doorOpened[r])
                x = l;
            else if (doorPosition[l] + doorPosition[r] >= buttonPosition[i])
                x = l;
            else
                x = r;
            doorOpened[x] = doorOpenedHistory[x] = true;
            dfs();
            doorOpened[x] = false;
            buttonPressed[i] = false;
        }
    }
}
int main()
{
    freopen("door.in", "r", stdin);
    freopen("door.out", "w", stdout);
    IO::readi(n);
    for (int i = 1; i <= n; i++) {
        int type, pos;
        IO::readl(type, pos);
        if (type == 1)
            doorPosition[++cntDoor] = pos;
        else
            buttonPosition[++cntButton] = pos;
    }
    dfs();
    for (int i = 1; i <= cntDoor; i++)
        IO::writei((int) doorOpenedHistory[i]);
    return 0;
}
