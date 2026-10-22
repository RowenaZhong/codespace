// 最小表示法
#include <bits/stdc++.h>
using namespace std;
string a, b;
int main()
{
    cin >> a >> b;
    int i = 0, j = 1, pa, pb;
    a = a + a, b = b + b;
    int n = a.size() / 2;
    while (i < n && j < n)
    {
        int k;
        for (k = 0; k < n; k++)
            if (a[i + k] != a[j + k])
                break;
        if (k == n)
            break;
        if (a[i + k] < a[j + k])
            j = j + k + 1;
        else
            i = i + k + 1;
        if (i == j)
            j++;
    }
    pa = min(i, j);
    i = 0, j = 1;
    while (i < n && j < n)
    {
        int k;
        for (k = 0; k < n; k++)
            if (b[i + k] != b[j + k])
                break;
        if (k == n)
            break;
        if (b[i + k] < b[j + k])
            j = j + k + 1;
        else
            i = i + k + 1;
        if (i == j)
            j++;
    }
    pb = min(i, j);
    string na, nb;
    na = a.substr(pa, n), nb = b.substr(pb, n);
    if (na == nb)
    {
        cout << "Yes" << endl;
        cout << na << endl;
    }
    else
        cout << "No" << endl;
    return 0;
}