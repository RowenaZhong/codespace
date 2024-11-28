#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
string str[MAXN];
bool cmp(string a, string b)
{
    return (a + b) > (b + a);
}
const int MOD = 998244353;
int n;
int main()
{
    freopen("D-Test.in", "r", stdin);
    freopen("D-Test.out", "w", stdout);
    getline(cin, str[0]);
    n = str[0].size();
    for (int i = 1; i < n; i++)
        str[i] = str[i - 1],
        str[i].pop_back();
    sort(str, str + n, cmp);
    for (int i = 0; i < n; i++)
        cout << str[i] << endl;
    return 0;
}