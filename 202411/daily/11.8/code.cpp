#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline void readi(T &x)
{
    T f = 1;
    x = 0;
    int ch;
    while (ch = getchar(), !feof(stdin) && !isdigit(ch) && ch != '-')
        ;
    if (ch == '-')
        f = -f, ch = getchar();
    while (!feof(stdin) && isdigit(ch)) {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
template <typename T>
inline void writei(T x)
{
    if (x == 0) {
        putchar('0');
        return;
    }
    if (x < 0)
        x = -x, putchar('-');
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p) {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}
unsigned valUsing;
const int NUM_N = INT_MAX;
class Code {
public:
    enum class Type { RUN, EXIT, ENDFOR, FOR };
    Type type;
    int val;
    int l, r;
    Code(Type t, char v = 0, int l = 0, int r = 0)
    {
        this->val = v;
        this->l = l;
        this->r = r;
        this->type = t;
    }
};
queue<Code> q;
int parseGeneral();
int parseFor()
{
    if (q.front().type != Code::Type::FOR)
    {
        // printf("not for:");
        return -1;
    }
    auto l = q.front().l, r = q.front().r,val=q.front().val;
    q.pop();
    if (valUsing & (1<<val)) {
        // printf("val_using@%c:",q.front().val+'a');
        return -1;
    }
    valUsing ^= 1 << val;
    int innerComplexity = INT_MIN;
    while (q.front().type != Code::Type::ENDFOR) {
        auto complexity = parseGeneral();
        if (complexity == -1)
            return -1;
        innerComplexity = max(innerComplexity, complexity);
    }
    valUsing ^= 1 << val;
    q.pop();
    if (l > r)
        return INT_MIN;
    if (r == NUM_N&&l!=NUM_N)
        return innerComplexity + 1;
    return innerComplexity;
}
int parseGeneral()
{
    switch (q.front().type) {
        case Code::Type::RUN:
            q.pop();
            return 0;
        case Code::Type::EXIT:
            q.pop();
            // printf("unexpected_exit:");
            return -1;
        case Code::Type::ENDFOR:
            q.pop();
            // printf("unexpected_end_for:");
            return -1;
        case Code::Type::FOR:
            return parseFor();
        default:
            // printf("unexpected_token:");
            return -1;
    }
}
int generalComplexity;
int main()
{
    freopen("code.in", "r", stdin);
    freopen("code.out", "w", stdout);
    int T;
    scanf("%d\n", &T);
    char str[100];
    int val, l, r;
    char chVal;
    char strL[20], strR[20];
    while (T--) {
        valUsing = 0;
        generalComplexity = 0;
        q = queue<Code>();
        while (true) {
            scanf("%[^\n]\n", str);
            bool isExit = false;
            switch (*str) {
                case 'r':
                    q.push(Code(Code::Type::RUN));
                    break;
                case 'e':
                    if (str[1] == 'x')
                        q.push(Code(Code::Type::EXIT)), isExit = true;
                    else
                        q.push(Code(Code::Type::ENDFOR));
                    break;
                case 'f':
                    sscanf(str, "for %c from %s to %s", &chVal, strL, strR);
                    val = chVal - 'a';
                    l = (strL[0] == 'n') ? NUM_N : atoi(strL);
                    r = (strR[0] == 'n') ? NUM_N : atoi(strR);
                    q.push(Code(Code::Type::FOR, val, l, r));
                    break;
                default:
                    break;
            }
            if (isExit)
                break;
        }
        bool CE = false;
        while (q.front().type != Code::Type::EXIT) {
            auto complexity = parseGeneral();
            if (complexity == -1) {
                puts("Compile Error");
                CE = true;
                break;
            }
            generalComplexity = max(generalComplexity, complexity);
        }
        if (CE)
            continue;
        writei(generalComplexity);
        putchar('\n');
    }
    return 0;
}
