#include <bits/stdc++.h>
using namespace std;
int main()
{
    queue<int> que;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        que.push(i);
    while (que.size())
    {
        for (int i = 1; i < m; i++)
            que.push(que.front()), que.pop();
        cout << que.front() << " ";
        que.pop();
    }
    return 0;
}