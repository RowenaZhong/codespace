#include <bits/stdc++.h>
using namespace std;
int n, Ans, l[1000007], r[1000007];
void dfs(int x, int d)
{
    if(x == 0)
    {
        Ans = max(Ans, d);
        return ;
    }
    dfs(l[x], d + 1);
    dfs(r[x], d + 1);
}
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> l[i] >> r[i];
    dfs(1, 0);
    cout << Ans << endl;
    return 0;
}

