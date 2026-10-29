#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 7;
vector<int> primes;
bool v[MAXN];

void init()
{
    primes.reserve(MAXN);
    for (int i = 2; i <= MAXN; i++)
    {
        if (v[i] == 1)
            continue;
        primes.push_back(i);
        for (int j = i; j <= MAXN; j += i)
            v[j] = 1;
    }
}

int main()
{
    init();
    int n;
    cin >> n;
    // int ans = 0;
    for (int i = 0; i < primes.size(); i++)
    {
        int ans = 0;
        if (primes[i] > n)
            break;
        for (int j = n / primes[i]; j; j /= primes[i])
            ans += j;
        printf("%d %d\n", primes[i], ans);
    }
    // cout << ans << endl;
}