#include <bits/stdc++.h>

#define int long long
#define DB double
#define N 1000010

using namespace std;

inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while(c < '0' || c > '9'){if(c == '-') f = -1; c = getchar();}
    while(c <= '9' && c >= '0') x = (x << 1) + (x << 3) + (c ^ 48), c = getchar();
    return x * f;
}

int n, c[N], p[N], x[N], s[N], q[N], f[N], ans = 1e18;

/*
f[i] = min(f[j] + \sum_{k = j + 1}^{i} (x[i] - x[k]) * p[k] + c[i]);
f[i] = min(f[j] + \sum_{k = j + 1}^{i} (x[i] * p[k]) - \sum_{k = j + 1}^{i} x[k] * p[k] + c[i]);
s[i] = \sum_{k = 1}^{i} p[k] * x[k], p[i] = \sum_{k = 1}^{i} p[k];
f[i] = min(f[j] + x[i] * (p[i] - p[j]) - s[i] + s[j] + c[i]);
f[i] = min(f[j] + x[i] * p[i] - x[i] * p[j] - s[i] + s[j] + c[i]);
f[j] = x[i] * p[j] + f[i] - x[i] * p[i] + s[i] - s[j] - c[i];???
*/

inline DB xl(int i, int j)
{
    DB y = f[j] - f[i] + s[j] - s[i];
    if(p[j] == p[i])
    {
        if(y == 0) return 0;
        else
        {
            if(y > 0) return 1e19;
            else return -1e19;
        }
    }
    else return y / (p[j] - p[i]);
    return (f[j] - f[i]) * 1.0 / (p[j] - p[i]);
    // return(p[j] == p[i] ? (!y ? 0 : (y > 0 ? 1e19 : -1e19)) : y / DB(p[j] - p[i]));
}

signed main()
{
    n = read();
    for(int i = 1; i <= n; i ++)
    {
        x[i] = read(), p[i] = read(), c[i] = read();
        s[i] = s[i - 1] + p[i] * x[i];
        p[i] += p[i - 1];
    }
    int h = 1, t = 1;
    for(int i = 1; i <= n; i ++)
    {
        while(h < t && xl(q[h], q[h + 1]) <= x[i]) h ++;
        f[i] = f[q[h]] + x[i] * (p[i] - p[q[h]]) - s[i] + s[q[h]] + c[i];
        // cout << "CAO : " << q[h] << endl;
        while(h < t && xl(q[t - 1], i) <= xl(q[t - 1], q[t])) t --;
        q[++ t] = i;
    }
    h = n; ans = f[n];
    while(h && p[h] - p[h - 1] == 0) h --, ans = min(ans, f[h]);
    cout << ans << endl;
    return 0;
}