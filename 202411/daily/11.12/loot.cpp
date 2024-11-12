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
const int MAXN = 2e4 + 7;
int w, iP, n;
double p;
int s[MAXN];
int main()
{
    freopen("loot.in", "r", stdin);
    freopen("loot.out", "w", stdout);
    readi(w), readi(iP), readi(n);
    p = iP / 100.00;
    for (int i = 1; i <= n; i++)
        readi(s[i]);
    priority_queue<double> pq;
    for (int i = 1; i <= n; i++)
        pq.push(-s[i]);
    while (pq.size() > 1) {
        double p1 = -pq.top();
        pq.pop();
        double p2 = -pq.top();
        pq.pop();
        pq.push(-(p1 + p2) / (1 - p));
    }
    double firstHalvedGoldBarSize = -pq.top();
    if (firstHalvedGoldBarSize > w) {
        puts("-1");
        return 0;
    }
    double firstStolenGoldBarSize = w * (1 - p);
    if (firstStolenGoldBarSize <= firstHalvedGoldBarSize) {
        puts("0");
        return 0;
    }
    printf("%.5lf", firstStolenGoldBarSize - firstHalvedGoldBarSize);
    return 0;
}
