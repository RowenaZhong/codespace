#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int nxt[MAXN], f[MAXN];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    nxt[1] = 0;
    for (int i = 2, j = 0; i < a.size(); i++)
    {
        while (j != 0 && a[j + 1] != a[i])
            j = nxt[j];
        if (a[j + 1] == a[i])
            j++;
        nxt[i] = j;
    }
    f[1] = 0;
    for (int i = 1, j = 0; i < b.size(); i++)
    {
        while (j != 0 && a[j + 1] != b[i])
            j = nxt[j];
        if (a[j + 1] == b[i])
            j++;
        f[i] = j;
        if (f[i] + 1 == a.size())
            cout << i << " ", j = nxt[j];
    }
    cout << "\b" << endl;
    for (int i = 1; i < a.size(); i++)
        cout << a[i] << " ";
    cout << "\b" << endl;
    for (int i = 1; i < a.size(); i++)
        cout << nxt[i] << " ";
    cout << "\b" << endl;
    for (int i = 1; i < b.size(); i++)
        cout << b[i] << " ";
    cout << "\b" << endl;
    for (int i = 1; i < b.size(); i++)
        cout << f[i] << " ";
    cout << "\b" << endl;
    return 0;
}