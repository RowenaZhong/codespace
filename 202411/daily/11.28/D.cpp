#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
string str[MAXN];
bool cmp(string a, string b)
{
    return (a + b) > (b + a);
}
const int MOD = 998244353;
int main()
{
    freopen("C.in", "r", stdin);
    freopen("C.out", "w", stdout);
    getline(cin, str[0]);
    for (int i = 1; i < str[0].size(); i++)
        str[i] = str[i - 1],
        str[i].pop_back();
    sort(str, str + str[0].size(), cmp);
    long long ans = 0;
    for (int i = 0; i < str[0].size(); i++)
    {
        for (int j = 0; j < str[i].size(); j++)
        {
            ans = (ans * 10 + str[i][j] - 0x30) % MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}