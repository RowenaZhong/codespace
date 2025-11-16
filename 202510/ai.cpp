#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;
int n, m;
string s;
vector<int> c;
vector<vector<int>> dp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    cin >> s;
    c.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    // dp[i][j] = 第 i 天，已经有 j 个被拒绝/放弃的方案数
    dp.assign(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;

    for (int day = 0; day < n; ++day)
    {
        vector<vector<int>> new_dp(n + 1, vector<int>(n + 1, 0));
        for (int rejected = 0; rejected <= day; ++rejected)
        {
            int accepted = day - rejected;
            for (int i = 0; i < n; ++i)
            {
                // 如果第 i 个人已经安排过，跳过
                // 用一个标记数组记录是否安排过
                // 这里我们用排列组合方式处理，不枚举具体人

                // 假设当前安排的是某个未安排的人
                // 如果 rejected >= c[i]，他放弃面试
                // 否则，根据题目难度决定是否录用

                // 为了避免枚举人，我们统计有多少人满足条件
                // 所以我们需要一个计数方式来处理

                // 简化处理：我们只考虑人数，不考虑具体人
                // 所以我们在 day 天安排一个人，更新状态

                if (rejected >= c[i])
                {
                    // 放弃面试
                    new_dp[day + 1][rejected + 1] = (new_dp[day + 1][rejected + 1] + dp[day][rejected]) % MOD;
                }
                else
                {
                    if (s[day] == '1')
                    {
                        // 被录用
                        new_dp[day + 1][rejected] = (new_dp[day + 1][rejected] + dp[day][rejected]) % MOD;
                    }
                    else
                    {
                        // 被拒绝
                        new_dp[day + 1][rejected + 1] = (new_dp[day + 1][rejected + 1] + dp[day][rejected]) % MOD;
                    }
                }
            }
        }
        dp = new_dp;
    }

    int result = 0;
    for (int rejected = 0; rejected <= n; ++rejected)
    {
        int hired = n - rejected;
        if (hired >= m)
        {
            result = (result + dp[n][rejected]) % MOD;
        }
    }

    cout << result << '\n';
    return 0;
}