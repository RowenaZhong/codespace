#include <bits/stdc++.h>
using namespace std;
template <typename T>
void readi(T &x)
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
void readl()
{
}
template <typename T, typename... Args>
void readl(T &x, Args &...args)
{
    readi(x);
    readl(args...);
}

const int MAXN = 1e4 + 7;
int a[MAXN], pos[MAXN];
vector<pair<int, int>> output_list;
void reverso(int l, int r)
{
    output_list.push_back(make_pair(l, r));
    auto mid = l + r >> 1;
    mid += 1;
    auto dis = (r - l + 1) >> 1;
    for (int i = 0; i < dis; i++)
    {
        // cerr << i + l << " " << i + mid << endl;
        pos[a[i + l]] += dis;
        pos[a[i + mid]] -= dis;
        swap(a[i + l], a[i + mid]);
    }
}
int main()
{
    int T;
    readi(T);
    while (T--)
    {
        output_list.clear();
        int n, cnt = 0;
        readi(n);
        for (int i = 1; i <= n; i++)
            readi(a[i]), pos[a[i]] = i;
        for (int i = 1; i <= n; i++)
        {
            while (pos[i] != i)
            {
                // cerr << i << " " << pos[i] << endl;
                cnt++;
                reverso(((pos[i] - i) & 1) ? i : (i + 1), pos[i]);
            }
        }
        printf("%d\n", cnt);
        for (auto i : output_list)
        {
            printf("%d %d\n", i.first, i.second);
        }
    }
}