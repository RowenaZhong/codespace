#include <bits/stdc++.h>
using namespace std;
bool m[128];
int main()
{
    string s;
    cin >> s;
    stack<int> l;
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '(':
        case '[':
            l.push(i);
            break;
        case ')':
            if (l.size() && s[l.top()] == '(')
            {
                m[l.top()] = m[i] = true;
                l.pop();
            }
            break;
        case ']':
            if (l.size() && s[l.top()] == '[')
            {
                m[l.top()] = m[i] = true;
                l.pop();
            }
            break;
        default:
            break;
        }
    }
    for (int i = 0; i < s.size(); i++)
    {
        switch (s[i])
        {
        case '(':
            putchar('(');
            if (!m[i])
                putchar(')');
            break;
        case ')':
            if (!m[i])
                putchar('(');
            putchar(')');
            break;
        case '[':
            putchar('[');
            if (!m[i])
                putchar(']');
            break;
        case ']':
            if (!m[i])
                putchar('[');
            putchar(']');
            break;
        }
    }
    return 0;
}