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
    while (!feof(stdin) && isdigit(ch))
    {
        x = (x << 3) + (x << 1) + ch - 0x30;
        ch = getchar();
    }
    x *= f;
}
template <typename T>
inline void writei(T x)
{
    if (x == 0)
    {
        putchar('0');
        return;
    }
    if (x < 0)
        putchar('-'), x = -x;
    T p = 1;
    while (x / p >= 10)
        p = (p << 3) + (p << 1);
    while (p)
    {
        putchar(x / p + 0x30);
        x %= p;
        p /= 10;
    }
}
typedef enum
{
    SCANEOF,
    INTEGER,
    GREATER,
    LESS,
    QUOT,
    COLON,
    X,
    UNKNOWN
} token;
map<token, string> tks;
int buffer, m, q;
token tokbuf = UNKNOWN;
token scanner()
{
    if (feof(stdin))
        return SCANEOF;
    int ch = getchar();
    switch (ch)
    {
    case 'x':
        return X;
    case '>':
        return GREATER;
    case '<':
        return LESS;
    case '?':
        return QUOT;
    case ':':
        return COLON;
    default:
        if (isdigit(ch))
        {
            buffer = 0;
            while (isdigit(ch) && !feof(stdin))
            {
                buffer = (buffer << 3) + (buffer << 1) + ch - 0x30;
                ch = getchar();
            }
            ungetc(ch, stdin);
            return INTEGER;
        }
        else if (isspace(ch))
        {
            return scanner();
        }
        break;
    }
    return UNKNOWN;
}
token next_token()
{
    if (tokbuf == UNKNOWN)
        tokbuf = scanner();
    return tokbuf;
}
void match(token tok)
{
    if (tokbuf == UNKNOWN)
        next_token();
    tokbuf = UNKNOWN;
}
int getbuf()
{
    if (tokbuf == UNKNOWN)
        next_token();
    return buffer;
}

int x;
class BaseAST
{
public:
    virtual int calc() = 0;
    virtual void json() = 0;
};

class IntegerAst : public BaseAST
{
public:
    int content;
    int calc() override { return content; }
    void json() override
    {
        printf("{\"type\":\"Integer\",\"content\":%d}", content);
    }
};

class TernaryAST : public BaseAST
{
public:
    bool greater;
    unique_ptr<BaseAST> cmp;
    unique_ptr<BaseAST> o1;
    unique_ptr<BaseAST> o2;
    int calc() override
    {
        if (greater)
            return (x > cmp->calc()) ? o1->calc() : o2->calc();
        else
            return (x < cmp->calc()) ? o1->calc() : o2->calc();
    }
    void json() override
    {
        printf("{\"type\":\"Ternary\",\"op\":\"%c\",\"cmp\":", "<>"[this->greater]);
        this->cmp->json();
        printf(",\"a1\":");
        this->o1->json();
        printf(",\"a2\":");
        this->o2->json();
        printf("}");
    }
};

unique_ptr<BaseAST> Expression();
unique_ptr<BaseAST> Integer()
{
    unique_ptr<IntegerAst> ret(new IntegerAst());
    ret->content = getbuf();
    match(INTEGER); // Integer
    return ret;
}
unique_ptr<BaseAST> Ternary()
{
    unique_ptr<TernaryAST> ret(new TernaryAST());
    match(X); // x
    if (next_token() == GREATER)
        ret->greater = true;
    else
        ret->greater = false;
    match(next_token()); // > or <
    ret->cmp = Integer();
    match(QUOT); // QUOT ?
    ret->o1 = Expression();
    match(COLON); // :
    ret->o2 = Expression();
    return ret;
}
unique_ptr<BaseAST> Expression()
{
    switch (next_token())
    {
    case INTEGER:
        return Integer();
    case X:
        return Ternary();
    default:
        break;
    }
    return nullptr;
}
unique_ptr<BaseAST> expr;
int main()
{
    /*

    SCANEOF,
    INTEGER,
    GREATER,
    LESS,
    QUOT,
    COMMA,
    X,
    UNKNOWN*/
    tks[SCANEOF] = "^Z";
    tks[INTEGER] = "int";
    tks[GREATER] = ">";
    tks[LESS] = "<";
    tks[QUOT] = "?";
    tks[COLON] = ":";
    tks[X] = "x";
    tks[UNKNOWN] = "???";
    readi(m);
    readi(q);
    expr = Expression();
    // expr->json();
    while (q--)
    {
        int t;
        readi(t);
        x = t;
        writei(expr->calc());
        putchar('\n');
    }
    return 0;
}