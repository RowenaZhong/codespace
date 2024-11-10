#include <bits/stdc++.h>
using namespace std;
int main()
{
    int x, y, p, q;
    cin >> x >> y >> p >> q;
    cout << min({y - q, q, x - p, p}) << endl;
    return 0;
}