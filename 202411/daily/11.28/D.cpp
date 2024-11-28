#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
string str[MAXN];
int n;
bool cmp(string a, string b)
{
    return (a + b) > (b + a);
}
const int MOD = 998244353;
int main()
{
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    getline(cin, str[0]);
    n = str[0].size();
    for (int i = 1; i < n; i++)
        str[i] = str[i - 1],
        str[i].pop_back();
    sort(str, str + n, cmp);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < str[i].size(); j++)
        {
            ans = (ans * 10 + str[i][j] - 0x30) % MOD;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
// #include <bits/stdc++.h>
// #define int long long
// using namespace std;
// string s;
// int n;
// const int p = 998244353;
// int lst[100005];
// string s1[100005];
// bool cmp(string s1, string s2)
// {
//     if (s1 + s2 < s2 + s1)
//         return false;
//     return true;
// }
// signed main()
// {
//     freopen("D.in", "r", stdin);
//     freopen("D.out", "w", stdout);
//     getline(cin, s);
//     n = s.size();
//     s = " " + s;
//     string s0 = "";
//     for (int i = 1; i <= n; i++)
//         s1[i] = s1[i - 1] + s[i];
//     sort(s1 + 1, s1 + n + 1, cmp);
//     int now = 0;
//     for (int i = 1; i <= n; i++)
//         for (int j = 0; j < s1[i].size(); j++)
//             now = (now * 10 + s1[i][j] - '0') % p;
//     cout << now << endl;
//     return 0;
// }
