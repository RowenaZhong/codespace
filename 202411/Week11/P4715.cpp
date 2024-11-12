#include <bits/stdc++.h>
using namespace std;
int a[256], n, max1[256], max2[256], max1n[256], max2n[256];
//sxy bless pr
//#pragma optimize(2)
void dfs(int x)
{
    if(x >= n)
        return;
    dfs(x * 2);
    dfs(x * 2 + 1);
    if(max1[x * 2] > max1[x * 2 + 1])
    {
        max1[x] = max1[x * 2];
        max1n[x] = max1n[x * 2];
        max2[x] = max1[x * 2 + 1];
        max2n[x] = max1n[x * 2 + 1];
    }
    else
    {
        max1[x] = max1[x * 2 + 1];
        max1n[x] = max1n[x * 2 + 1];
        max2[x] = max1[x * 2];
        max2n[x] = max1n[x * 2];
    }
}
int main()
{
    cin >> n;
    n = 1 << n;
    for(int i = n; i < n * 2; i++)
        cin >> max1[i], max1n[i] = i;
    dfs(1);
    //for(int i = 1; i < n; i++)
    //    cout << max1[i] << " " << max2[i] << endl;
    cout << max2n[1] - n + 1 << endl;
    return 0;
}

