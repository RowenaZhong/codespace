// https://www.luogu.com.cn/problem/P1236
#include <bits/stdc++.h>
using namespace std;
enum class op
{
    ADD,
    SUB,
    MUL,
    DIV
};
struct logs
{
    vector<int> data;
    vector<tuple<int, int, op>> operations;
    logs(vector<int> d) : data(d)
    {
    }
    vector<logs> next()
    {
        vector<logs> res;
        for (int i = 0; i < data.size(); i++)
        {
            for (int j = i + 1; j < data.size(); j++)
            {
                vector<int> new_data = data;
                swap(new_data[i], new_data[j]);
                res.push_back(logs(new_data));
            }
        }
        return res;
    }
};

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
}