#include <bits/stdc++.h>
using namespace std;
typedef unsigned Ident;
typedef unsigned long long Addr;
map<string, Ident> ValueIdent;
map<string, Ident> TypeIdent;

class TypeDef;
extern TypeDef TypeDefine[109];
vector<string> ValueName;
class TypeDef
{
public:
    vector<Ident> value;
    vector<Ident> type;
    vector<Addr> offset;
    Addr size, general_offset;
    vector<Ident> QueryValueName(Addr x)
    {
        if (x >= this->size)
        {
            return vector<Ident>{INT_MAX};
        }
        if (this->offset.size() == 0)
            return vector<Ident>();
        int l = 0, r = this->offset.size() - 1;
        while (l != r)
        {
            int mid = (l + r + 1) >> 1;
            if (offset[mid] > x)
                r = mid - 1;
            else
                l = mid;
        }
        vector<Ident> ret = TypeDefine[this->type[l]].QueryValueName(x - this->offset[l]);
        ret.push_back(this->value[l]);
        return ret;
    }
    Addr QueryOffset(vector<Ident> &valuenames)
    {
        if (valuenames.size() == 0)
            return 0;
        for (int i = 0; i < this->value.size(); i++)
        {
            if (this->value[i] == valuenames[valuenames.size() - 1])
            {
                valuenames.pop_back();
                return this->offset[i] + TypeDefine[this->type[i]].QueryOffset(valuenames);
            }
        }
        return 0;
    }
    Addr AddValue(Ident type, Ident value)
    {
        this->type.push_back(type);
        this->value.push_back(value);
        Addr offset = this->size;
        if (offset % TypeDefine[type].general_offset)
            offset = offset - (offset % TypeDefine[type].general_offset) + TypeDefine[type].general_offset;
        this->offset.push_back(offset);
        this->size = offset + TypeDefine[type].size;
        this->general_offset = max(this->general_offset, TypeDefine[type].general_offset);
        return offset;
    }
    Addr Package()
    {
        if (this->size % this->general_offset)
            this->size = this->size - (this->size % this->general_offset) + this->general_offset;
        return this->size;
    }
    TypeDef()
    {
        this->size = 0;
        this->general_offset = 0;
    }
};
TypeDef TypeDefine[109];
void solve()
{
    int op;
    scanf("%d", &op);
    char s[1500], t[15], n[15];
    Ident k, Ident_Type_s;
    Addr addr;
    vector<Ident> valueidents;
    switch (op)
    {
    case 1:
        scanf("%s %d", s, &k);
        Ident_Type_s = TypeIdent.size();
        TypeIdent[s] = Ident_Type_s;
        while (k--)
        {
            scanf("%s %s", t, n);
            if (!ValueIdent.count(n))
            {
                ValueIdent[n] = ValueIdent.size();
                ValueName.push_back(n);
            }
            TypeDefine[Ident_Type_s].AddValue(TypeIdent[t], ValueIdent[n]);
        }
        printf("%llu %llu\n", TypeDefine[Ident_Type_s].Package(), TypeDefine[Ident_Type_s].general_offset);
        break;
    case 2:
        scanf("%s %s", t, n);
        if (!ValueIdent.count(n))
        {
            ValueIdent[n] = ValueIdent.size();
            ValueName.push_back(n);
        };
        printf("%llu\n", TypeDefine[0].AddValue(TypeIdent[t], ValueIdent[n]));
        break;
    case 3:
        scanf("%s", s);
        k = 0;
        for (char *p = s; *p; p++)
        {
            if (*p == '.')
            {
                t[k] = '\0';
                valueidents.push_back(ValueIdent[t]);
                k = 0;
            }
            else
            {
                t[k++] = *p;
            }
        }
        t[k] = '\0';
        valueidents.push_back(ValueIdent[t]);
        reverse(valueidents.begin(), valueidents.end());
        printf("%llu\n", TypeDefine[0].QueryOffset(valueidents));
        break;
    case 4:
        scanf("%llu", &addr);
        valueidents = TypeDefine[0].QueryValueName(addr);
        if (valueidents[0] == INT_MAX)
        {
            puts("ERR");
            break;
        }
        for (auto riter = valueidents.rbegin(); riter != valueidents.rend(); riter++)
        {
            if (riter != valueidents.rbegin())
                putchar('.');
            printf("%s", ValueName[*riter].c_str());
        }
        putchar('\n');
        break;
    case 5:
        for (int i = 0; i < TypeIdent.size(); i++)
        {
            printf("struct %d\n", i);
            printf("\tsize = %llu\n", TypeDefine[i].size);
            printf("\tgeneral offset = %llu\n", TypeDefine[i].general_offset);
            printf("\ttypes = ");
            for (const auto &c : TypeDefine[i].type)
                printf("\t%u", c);
            printf("\n");
            printf("\tvalue = ");
            for (const auto &c : TypeDefine[i].value)
                printf("\t%u", c);
            printf("\n");
            printf("\toffset= ");
            for (const auto &c : TypeDefine[i].offset)
                printf("\t%llu", c);
            printf("\n");
            printf("\n");
        }
        break;
    default:
        break;
    }
}
int main()
{
    TypeIdent["/"] = 0;
    TypeIdent["byte"] = 1;
    TypeIdent["short"] = 2;
    TypeIdent["int"] = 3;
    TypeIdent["long"] = 4;
    TypeDefine[1].size = TypeDefine[1].general_offset = 1;
    TypeDefine[2].size = TypeDefine[2].general_offset = 2;
    TypeDefine[3].size = TypeDefine[3].general_offset = 4;
    TypeDefine[4].size = TypeDefine[4].general_offset = 8;
    int T;
    scanf("%d", &T);
    while (T--)
    {
        solve();
    }

    return 0;
}
