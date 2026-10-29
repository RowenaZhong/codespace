#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 7;
int phi[MAXN], prefix[MAXN], p[MAXN];
vector<int> primes;

void GetPhi()
{
    primes.reserve(MAXN);
    for (int i = 2; i < MAXN; i++)
        p[i] = i;
    for (int i = 2; i < MAXN; i++)
    {
        if (p[i] == i)
            primes.push_back(i), phi[i] = i - 1;
        for (int j = 0; j < primes.size() && primes[j] <= p[i] && primes[j] * i < MAXN; j++)
        {
            p[i * primes[j]] = primes[j];
            if (i % primes[j] == 0)
                phi[i * primes[j]] = phi[i] * primes[j];
            else
                phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
}
void GetPrefix()
{
    prefix[0] = 1;
    prefix[1] = 3;
    for (int i = 2; i <= MAXN; i++)
        prefix[i] = prefix[i - 1] + phi[i] * 2;
}

int main()
{
    int C, incr = 0;
    scanf("%d", &C);
    GetPhi();
    GetPrefix();
    while (C--)
    {
        incr++;
        int N;
        scanf("%d", &N);
        printf("%d %d %d\n", incr, N, prefix[N]);
    }
    return 0;
}