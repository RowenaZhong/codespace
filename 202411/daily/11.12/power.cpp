#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, k, k1;
int ys[200005], cnt[200005], cnt2[200005], tot;
signed main()
{
    scanf("%lld%lld", &n, &k);
    for (int i = 2; i * i <= k; i++) {
        if (k % i)
            continue;
        tot++, ys[tot] = i;
        while (k % i == 0)
            cnt[tot]++, k /= i;
    }
    if (k != 1)
        tot++, ys[tot] = k, cnt[tot] = 1;
    int ans = 1e18 + 1145141919810;
    int now;
    for (int i = 1; i <= tot; i++) {
        for (now = ys[i]; now <= n; now *= ys[i]) {
            cnt2[i] += n / now;
            if (now * ys[i] / ys[i] != now)
                break;
        }
        ans = min(ans, cnt2[i] / cnt[i]);
    }
    printf("%lld\n", ans);
    return 0;
}
