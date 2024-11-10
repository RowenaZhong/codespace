#include <bits/stdc++.h>
using namespace std;
int a[100007];
priority_queue<int> lm;
priority_queue<int> gm;
int main()
{
    int n;
    cin >> n;
    int t;
    cin >> t;
    printf("%d\n", t);
    for (int i = 2; i + 1 <= n; i += 2)
    {
        int p;
        scanf("%d", &p);
        if (t < p)
        {
            swap(t, p);
            if (gm.size() && -gm.top() < t)
            {
                int k = t;
                t = -gm.top();
                gm.pop();
                gm.push(-k);
            }
        }
        lm.push(p);
        scanf("%d", &p);
        if (p < t)
        {
            swap(t, p);
            if (lm.size() && lm.top() > t)
            {
                int k = t;
                t = lm.top();
                lm.pop();
                lm.push(k);
            }
        }
        gm.push(-p);
        printf("%d\n", t);
    }
    return 0;
}