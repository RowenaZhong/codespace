#include <bits/stdc++.h>
#include <string>
using namespace std;
int n, m, q;
string a, b;
const int MAXN = 2e5 + 7;
int kmp[MAXN], pile[MAXN], f[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    for (size_t i = 2, j = 0; i <= m; i++)
    {
        while (j && b[j + 1] != b[i])
            j = kmp[j];
        if (b[j + 1] == b[i])
            j++;
        kmp[i] = j;
    }
    for (size_t i = 1, j = 0; i <= n; i++)
    {
        while (j && b[j + 1] != a[i])
            j = kmp[j];
        if (b[j + 1] == a[i])
            j++;
        if (j > 0)
            pile[j]++;
    }
    for (int i = m; i >= 1; i--)
    {
        pile[kmp[i]] += pile[i];
    }
    pile[0] = n - pile[1];

    for (int i = 1; i < m; i++)
        pile[i] -= pile[i + 1];
    while (q--)
    {
        int x;
        cin >> x;
        cout << pile[x] << endl;
    }
    return 0;
}