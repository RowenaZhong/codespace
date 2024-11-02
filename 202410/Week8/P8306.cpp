#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e6 + 7;
map<char, int> Trie[MAXN];
int cntc[MAXN], tot, root;
char str[MAXN];
int T, n, q;
void add(char *p)
{
    int t = root;
    while (*p)
    {
        if (!Trie[t].count(*p))
            Trie[t][*p] = tot++;
        cntc[t]++;
        t = Trie[t][*p];
        p++;
    }
    cntc[t]++;
}
int query(char *p)
{
    int t = root;
    while (*p)
    {
        if (!Trie[t].count(*p))
            return 0;
        t = Trie[t][*p];
        p++;
    }
    return cntc[t];
}
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &n, &q);
        root = tot++;
        while (n--)
        {
            scanf("%s", str);
            add(str);
        }
        while (q--)
        {
            scanf("%s", str);
            printf("%d\n", query(str));
        }
    }
    return 0;
}