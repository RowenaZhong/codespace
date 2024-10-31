#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 7;
deque<int>deq;
int a[MAXN], s[MAXN], n, m;
int main()
{
    scanf("%d %d", &n, &m);
    int ans = 0;
    deq.push_back(0);
    for(int i = 1; i <=n; i++)
    {
        scanf("%d", &a[i]);
        s[i] = s[i - 1] + a[i];
        if(deq.front() < i - m)
            deq.pop_front();
        ans = max(ans, s[i] - s[deq.front()]);
        while(deq.size() && s[i] <= s[deq.back()])
            deq.pop_back();
        deq.push_back(i);
    }
    printf("%d\n", ans);
}