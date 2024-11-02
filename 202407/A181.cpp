#include <iostream>
#include <vector>
using namespace std;
int basin[7][7];
int f()
{
    int *cnt = new int[4]();
    for (int i = 2; i <= 4; i++)
        for (int j = 2; j <= 4; j++)
            cnt[basin[i][j]]++;
    int maxn = 0;
    for (int i = 1; i <= 3; i++)
        maxn = max(maxn, cnt[i]);
    delete[] cnt;
    return 8 - maxn;
}
void examine()
{
    int cnt[4];
    cnt[1] = cnt[2] = cnt[3] = 0;
    for (int i = 0; i < 7; i++)
    {
        cnt[basin[2][i]]++;
        cnt[basin[4][i]]++;
        cnt[basin[i][2]]++;
        cnt[basin[i][4]]++;
    }
    cnt[basin[2][2]]--;
    cnt[basin[4][4]]--;
    cnt[basin[2][4]]--;
    cnt[basin[4][2]]--;
    if (cnt[1] != 8 || cnt[2] != 8 || cnt[3] != 8)
    {
        printf("ERROR!\n");
        exit(-1);
    }
}
void operate(char ch)
{
    int t;
    switch (ch)
    {
    case 'A':
        t = basin[0][2];
        for (int i = 0; i < 6; i++)
            basin[i][2] = basin[i + 1][2];
        basin[6][2] = t;
        break;
    case 'B':
        t = basin[0][4];
        for (int i = 0; i < 6; i++)
            basin[i][4] = basin[i + 1][4];
        basin[6][4] = t;
        break;
    case 'C':
        t = basin[2][6];
        for (int i = 6; i > 0; i--)
            basin[2][i] = basin[2][i - 1];
        basin[2][0] = t;
        break;
    case 'D':
        t = basin[4][6];
        for (int i = 6; i > 0; i--)
            basin[4][i] = basin[4][i - 1];
        basin[4][0] = t;
        break;
    case 'E':
        t = basin[6][4];
        for (int i = 6; i > 0; i--)
            basin[i][4] = basin[i - 1][4];
        basin[0][4] = t;
        break;
    case 'F':
        t = basin[6][2];
        for (int i = 6; i > 0; i--)
            basin[i][2] = basin[i - 1][2];
        basin[0][2] = t;
        break;
    case 'G':
        t = basin[4][0];
        for (int i = 0; i < 6; i++)
            basin[4][i] = basin[4][i + 1];
        basin[4][6] = t;
        break;
    case 'H':
        t = basin[2][0];
        for (int i = 0; i < 6; i++)
            basin[2][i] = basin[2][i + 1];
        basin[2][6] = t;
        break;
    default:
        break;
    }
}
vector<char> cmds;
int depth = 1;
char antiCmd(char ch)
{
    switch (ch)
    {
    case 'A':
        return 'F';
    case 'B':
        return 'E';
    case 'C':
        return 'H';
    case 'D':
        return 'G';
    case 'E':
        return 'B';
    case 'F':
        return 'A';
    case 'G':
        return 'D';
    case 'H':
        return 'C';
    default:
        return 0x00;
    }
}
void print()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
            printf("%d ", basin[i][j]);
        putchar('\n');
    }
}
bool dfs()
{
    if (cmds.size() + f() > depth)
        return false;
    if (f() == 0)
    {
        print();
        return true;
    }
    for (char ch = 'A'; ch <= 'H'; ch++)
    {
        if (cmds.size() && cmds[cmds.size() - 1] == antiCmd(ch))
            continue;
        operate(ch);
        cmds.push_back(ch);
        if (dfs())
            return true;
        cmds.pop_back();
        operate(antiCmd(ch));
    }
    return false;
}
inline int check()
{
    return basin[2][2];
}
int main()
{
    while (1)
    {
        int c;
        scanf("%d", &c);
        if (c == 0)
            break;
        basin[0][2] = c;
        scanf("%d", *(basin + 0) + 4);
        scanf("%d", *(basin + 1) + 2);
        scanf("%d", *(basin + 1) + 4);
        for (int i = 0; i < 7; i++)
            scanf("%d", *(basin + 2) + i);
        scanf("%d", *(basin + 3) + 2);
        scanf("%d", *(basin + 3) + 4);
        for (int i = 0; i < 7; i++)
            scanf("%d", *(basin + 4) + i);
        scanf("%d", *(basin + 5) + 2);
        scanf("%d", *(basin + 5) + 4);
        scanf("%d", *(basin + 6) + 2);
        scanf("%d", *(basin + 6) + 4);
        // char ch = getchar();
        // while (1)
        // {
        //     if (ch < 'A' || ch > 'H')
        //     {
        //         ch = getchar();
        //         continue;
        //     }
        //     operate(ch);
        //     print();
        //     ch = getchar();
        //     examine();
        //     if (f() == 0)
        //     {
        //         printf("Accepted\n");
        //     }
        // }
        int t = f();
        cmds = vector<char>();
        if (t == 0)
        {
            printf("No moves needed\n");
            printf("%d\n", check());
            continue;
        }
        for (depth = t;; depth++)
        {
            if (dfs())
            {
                for (auto iter = cmds.begin(); iter != cmds.end(); iter++)
                    putchar(*iter);
                putchar('\n');
                printf("%d\n", check());
                break;
            }
            // printf("%d%d%d%d", basin[0][2], basin[0][4], basin[1][2], basin[1][4]);
            // for (int i = 0; i < 7; i++)
            //     printf("%d", basin[2][i]);
            // printf("%d%d", basin[3][2], basin[3][4]);
            // for (int i = 0; i < 7; i++)
            //     printf("%d", basin[4][i]);
            // printf("%d%d%d%d", basin[5][2], basin[5][4], basin[6][2], basin[6][4]);
            // putchar('\n');
        }
    }
    return 0;
}