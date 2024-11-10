#include <bits/stdc++.h>
using namespace std;
size_t power(size_t a, size_t b, size_t p)
{
    size_t ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans;
}
int main()
{
    size_t a, b, p;
    cin >> a >> b >> p;
    cout << a << "^" << b << " mod " << p << "=" << power(a, b, p) << endl;
}