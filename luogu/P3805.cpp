#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1.1e7 + 7;
int d[MAXN * 2];
int manacher(const string &str)
{
    int ret = 0;
    string pstr = "#";
    for (const auto &c : str)
    {
        pstr.push_back(c);
        pstr.push_back('#');
    }
    int l = 0, r = -1;
    for (int i = 0; i < pstr.size(); i++)
    {
        if (i < r)
        {
            d[i] = min(d[l + r - i], r - i);
            if (d[i] == r - i)
            {
                int j;
                for (j = r; j < pstr.size() && i + i - j >= 0 && pstr[j] == pstr[i + i - j]; j++)
                    ;
                j--;
                if (j > r)
                {
                    r = j;
                    l = i + i - j;
                }
                d[i] = j - i;
            }
        }
        else
        {
            int j;
            for (j = i; j < pstr.size() && i + i - j >= 0 && pstr[j] == pstr[i + i - j]; j++)
                ;
            j--;
            if (j > r)
            {
                r = j;
                l = i + i - j;
            }
            d[i] = j - i;
        }
        ret = max(d[i], ret);
    }
    return ret;
}
int main()
{
    string str;
    cin >> str;
    cout << manacher(str) << endl;
    return 0;
}
