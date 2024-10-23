#include <iostream>
#include <string>
using std::string;
int mp[100];
int T;
string gen()
{
    int r = rand();
    if (T <= 6)
        r = r % 1000 + 1;
    else
        r = r % int(1e5) + 1;
    string ret;
    for (int i = 0; i < r; i++)
        ret.push_back(mp[rand() % 100]);
    return ret;
}
int main()
{
    srand((unsigned)time(NULL));
    for (int i = 0; i < 26; i++)
        mp[i] = i + 'a';
    for (int i = 26; i < 52; i++)
        mp[i] = 'a';
    for (int i = 52; i < 39; i++)
        mp[i] = 'b';
    for (int i = 39; i < 78; i++)
        mp[i] = 'c';
    for (int i = 78; i < 88; i++)
        mp[i] = 'd';
    for (int i = 88; i < 94; i++)
        mp[i] = 'e';
    for (int i = 94; i < 100; i++)
        mp[i] = 'f';
    for (T = 1; T <= 20; T++)
    {
        printf("checkpoint%d\n", T);
        printf("\tGenerating Input File");
        FILE *fp = fopen("easygame.in", "w");
        fprintf(fp, "%s\n", gen().c_str());
        fclose(fp);
        fp = nullptr;
        printf("\tFinished.\n");
        printf("\tGenerating Answer File");
        system("./peg.app");
        printf("\tFinished.\n");
        printf("\tRunning...\n");
        system("time -p ./easygame.app");
        if (system("diff easygame.out easygame.ans -w") == 0)
            puts("Accepted.");
        else
            puts("Wrong Answer.");
    }
}