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
int dfn[MAXN], low[MAXN], dfntot = 1, stk[MAXN], stktot;
int scctot;
void tarjan(int u)
{
    dfn[u] = low[u] = dfntot++;
    stk[stktot++] = u;
    for (auto e = head[u]; e; e = nxt[e])
    {
        auto v = ver[e];
        if (dfn[v])
            low[u] = min(low[u], dfn[v]);
        else
            tarjan(v), low[u] = min(low[u], low[v]);
    }
    if (dfn[u] == low[u])
    {
        scctot++;
        while (stk[stktot - 1] != u)
        {
            scc[stk[stktot - 1]] = scctot;
            stktot--;
        }
        scc[stk[stktot - 1]] = scctot;
        stktot--;
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
        person[str1] = i * 2 - 1, person[str2] = i * 2;
        AddEdge(i * 2 - 1, i * 2);
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> str1 >> str2;
        AddEdge(person[str2], person[str1]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i * 2 - 1])
            tarjan(i * 2 - 1);
        if (!dfn[i * 2])
            tarjan(i * 2);
        puts(scc[i * 2 - 1] == scc[i * 2] ? "Unsafe" : "Safe");
    }
    return 0;
}