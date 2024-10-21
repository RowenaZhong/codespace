#include <bits/stdc++.h>
using namespace std;
int n, k;
char str[500005];
void solve()
{
    scanf("%d %d", &n, &k);
    scanf("%s", str);
    int Ans = 0;
    for (int l = 0; l < n; l++)
    {
        for (int s = 1; l + s * k <= n; s++)
        {
            bool flag1 = true;
            for (int i = 1; i < k; i++)
            {
                if (i & 1)
                {
                    for (int j = 0; j < s; j++)
                    {
                        if (str[l + j] != str[l + i * s + j])
                        {
                            flag1 = false;
                            goto kel;
                        }
                    }
                }
                else
                {
                    for (int j = 0; j < s; j++)
                    {
                        if (str[l + j] != str[l + i * s + s - j - 1])
                        {
                            flag1 = false;
                            goto kel;
                        }
                    }
                }
            }
        kel:
            if (flag1)
                Ans++;
        }
    }
    printf("%d\n", Ans);
}
int main()
{
    freopen("kasane.in", "r", stdin);
    freopen("kasane.out", "w", stdout);
    int t;
    scanf("%d", &t);
    while (t--)
        solve();
    return 0;
}