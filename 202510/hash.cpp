#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long hash_t;
const int MAXN = 1e5 + 7, P = 131;
hash_t ha[MAXN], hb;
hash_t value(int ch)
{
    return ch - 'a' + 1;
}
void myhash(string str, hash_t h[])
{
    h[0] = 0;
    for (int i = 0; i < str.size(); i++)
        h[i + 1] = h[i] * P + value(str[i]);
}
hash_t myhash(string str)
{
    hash_t ret = 0;
    for (int i = 0; i < str.size(); i++)
        ret = ret * P + value(str[i]);
    return ret;
}
hash_t power(int n)
{
    if (n == 0)
        return 1;
    hash_t t = power(n >> 1);
    t *= t;
    if (n & 1)
        t = t * P;
    return t;
}
hash_t strcat_h(hash_t h[], int l, int d)
{
    int r = l + d - 1;
    return h[r] - h[l - 1] * power(d);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    myhash(a, ha);
    hb = myhash(b);
    for (int i = 1; i <= a.size(); i++)
    {
        if (strcat_h(ha, i, b.size()) == hb)
        {
            cout << i << " ";
        }
    }
    cout << "\b" << endl;
    return 0;
}
/*
ababaccbbabcba
aba
 */