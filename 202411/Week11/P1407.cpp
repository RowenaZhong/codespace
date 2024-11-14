#include <bits/stdc++.h>
using namespace std;
map<string, int> person;
const int MAXN = 8007, MAXM = 24007;
int head[MAXN], nxt[MAXM], ver[MAXM];
int scc[MAXN], totPerson = 1, totEdge = 1;
void AddEdge(int u, int v)
{
    totEdge++, nxt[totEdge] = head[u], head[u] = totEdge, ver[totEdge] = v;
}
int dfn[MAXN], low[MAXN], dfntot = 1, stk[MAXN], stktot, ins[MAXN];
int scctot;
void tarjan(int u)
{
    dfn[u] = low[u] = dfntot++;
    stk[++stktot] = u;
    ins[u] = true;
    for (auto e = head[u]; e; e = nxt[e])
    {
        auto v = ver[e];
        if (dfn[v])
            if (ins[v])
                low[u] = min(low[u], dfn[v]);
            else
                ;
        else
            tarjan(v), low[u] = min(low[u], low[v]);
    }
    if (dfn[u] == low[u])
    {
        scctot++;
        do
        {
            scc[stk[stktot]] = scctot;
            ins[stk[stktot]] = false;
        } while (stk[stktot--] != u);
    }
}
int main()
{
    int n, m;
    cin >> n;
    string str1, str2;
    for (int i = 1; i <= n; i++)
    {
        cin >> str1 >> str2;
        person[str1] = i, person[str2] = i + n;
        AddEdge(i, i + n);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> str1 >> str2;
        AddEdge(person[str2], person[str1]);
    }
    for (int i = 1; i <= n * 2; i++)
        if (!dfn[i])
            tarjan(i);
    for (int i = 1; i <= n; i++)
        puts(scc[i] == scc[i + n] ? "Unsafe" : "Safe");
    return 0;
}