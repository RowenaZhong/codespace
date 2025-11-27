#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    deque<int> up, down;
    for (int i = 1; i <= k; i++)
    {
        while (!up.empty() && a[up.back()] > a[i])
            up.pop_back();
        up.push_back(i);
    }
    printf("%d ", a[up.front()]);
    for (int i = k + 1; i <= n; i++)
    {
        while (!up.empty() && a[up.back()] > a[i])
            up.pop_back();
        up.push_back(i);
        if (up.front() == i - k)
            up.pop_front();
        printf("%d ", a[up.front()]);
    }
    putchar('\n');
    for (int i = 1; i <= k; i++)
    {
        while (!down.empty() && a[down.back()] < a[i])
            down.pop_back();
        down.push_back(i);
    }
    printf("%d ", a[down.front()]);
    for (int i = k + 1; i <= n; i++)
    {
        while (!down.empty() && a[down.back()] < a[i])
            down.pop_back();
        down.push_back(i);
        if (down.front() == i - k)
            down.pop_front();
        printf("%d ", a[down.front()]);
    }
    putchar('\n');
    return 0;
}