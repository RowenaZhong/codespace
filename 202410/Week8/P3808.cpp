#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e6 + 7;
const int N = 2e5 + 7;
namespace AC
{
    class Node
    {
    public:
        int son[26];
        int fail;
        int deg;
        int ans;
        int idx;
        Node()
        {
            memset(this->son, 0x00, sizeof(son));
            this->fail = this->deg = this->ans = 0;
        }
    };
    Node nodes[MAXN];
    int ans[N];
    int idxtot = 0, tot = 0;
    void add(char *str, int &idx)
    {
        int p = 0;
        while (*str)
        {
            if (!nodes[p].son[*str - 'a'])
                nodes[p].son[*str - 'a'] = ++tot;
            p = nodes[p].son[*str - 'a'];
            str++;
        }
        if (!nodes[p].idx)
            nodes[p].idx = ++idxtot;
        idx = nodes[p].idx;
    }
    void build()
    {
        queue<int> que;
        for (int i = 0; i < 26; i++)
            if (nodes[0].son[i])
                que.push(nodes[0].son[i]);
        while (que.size())
        {
            int t = que.front();
            que.pop();
            for (int i = 0; i < 26; i++)
                if (nodes[t].son[i])
                {
                    nodes[nodes[t].son[i]].fail = nodes[nodes[t].fail].son[i];
                    nodes[nodes[nodes[t].fail].son[i]].deg++;
                    que.push(nodes[t].son[i]);
                }
                else
                    nodes[t].son[i] = nodes[nodes[t].fail].son[i];
        }
    }
    void query(char *str)
    {
        int p = 0;
        while (*str)
        {
            p = nodes[p].son[*str - 'a'];
            nodes[p].ans++;
            str++;
        }
    }
    void toposort()
    {
        queue<int> que;
        for (int i = 0; i <= tot; i++)
            if (nodes[i].deg == 0)
                que.push(i);
        while (que.size())
        {
            int t = que.front();
            que.pop();
            ans[nodes[t].idx] = nodes[t].ans;
            nodes[nodes[t].fail].ans += nodes[t].ans;
            if (--nodes[nodes[t].fail].deg == 0)
                que.push(nodes[t].fail);
        }
    }
}
char str[MAXN];
int n;
int idx[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", str);
        AC::add(str, idx[i]);
    }
    scanf("%s", str);
    AC::build();
    AC::query(str);
    AC::toposort();
    int Ans = 0;
    for (int i = 1; i <= n; i++)
        if (AC::ans[idx[i]])
            Ans++;
    printf("%d\n", Ans);
    return 0;
}