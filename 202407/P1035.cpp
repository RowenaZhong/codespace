#include <bits/stdc++.h>
using namespace std;
int k;
double sum = 0;
int main()
{
    cin >> k;
    int n;
    for (int i = 1;; i++)
    {
        sum = sum + double(1) / i;
        if (sum > k)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}