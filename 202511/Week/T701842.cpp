#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 7;
int nxt[MAXN], f[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    for (int i = 2, j = 0; i < s2.size(); i++)
    {
        while (j != 0 && s2[j + 1] != s2[i])
            j = nxt[j];
        if (s2[j + 1] == s2[i])
            j++;
        nxt[i] = j;
    }
    for (int i = 1, j = 0; i < s1.size(); i++)
    {
        while (j != 0 && s2[j + 1] != s1[i])
            j = nxt[j];
        if (s2[j + 1] == s1[i])
            j++;
        f[i] = j;
        if (f[i] + 1 == s2.size())
            cout << i - s2.size() + 2 << endl;
    }
    for (int i = 1; i < s2.size(); i++)
        cout << nxt[i] << " \n"[i == s2.size() - 1];
    return 0;
}