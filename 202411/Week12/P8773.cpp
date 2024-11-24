#include <bits/stdc++.h>
using namespace std;
map<int, int> lastA;
int n, m, x;
const int MAXN = 1e5 + 7;
int last[MAXN];
int main()
{
    scanf("%d %d %d", &n, &m, &x);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        last[i] = max(last[i - 1], lastA[x ^ a]);
        lastA[a] = i;
    }
    while (m--) {
        int l, r;
        scanf("%d %d", &l, &r);
        puts(last[r] >= l ? "yes" : "no");
    }
    return 0;
}