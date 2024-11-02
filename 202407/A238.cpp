#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
int fa[N], d[N], s[N];
void pre()
{
    for (int i = 1; i <= N; i++)
        fa[i] = i, s[i] = 1;
}
int get()
{
    int ch = getchar();
    if (ch != 'M' && ch != 'C')
        return get();
    return ch;
}
int getfather(int x)
{
    if (fa[x] == x)
        return x;
    int t = getfather(fa[x]);
    d[x] += d[fa[x]];
    return fa[x] = t;
}
int main()
{
    pre();
    int T;
    scanf("%d", &T);
    while (T--)
    {
        if (get() == 'C')
        {
            int a, b;
            scanf("%d %d", &a, &b);
            if (getfather(a) != getfather(b))
                printf("-1\n");
            else if (a == b)
                printf("0\n");
            else
                printf("%d\n", abs(d[a] - d[b]) - 1);
        }
        else
        {
            int a, b;
            scanf("%d %d", &a, &b);
            a = getfather(a);
            b = getfather(b);
            if (a == b)
                continue;
            fa[a] = b;
            d[a] = s[b];
            s[b] += s[a];
        }
    }
    return 0;
}