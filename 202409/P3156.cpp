#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    vector<int> ident;
    cin >> n >> m;
    ident.resize(n);
    for (int i = 0; i < n; i++)
        cin >> ident[i];
    for (int i = 0; i < m; i++)
    {
        int t;
        cin >> t;
        cout << ident[t - 1] << endl;
    }
    return 0;
}