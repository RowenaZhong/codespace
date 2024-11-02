#include <iostream>
#include <deque>
#include <cstring>
using namespace std;
int N, M;
bool map[512][512];
int dis[512][512];
bool vis[512][512];
int read()
{
    int ch = getchar();
    while (ch != '\\' && ch != '/')
        ch = getchar();
    return ch;
}
int main()
{
    scanf("%d %d", &N, &M);
    if ((N + M) & 1)
    {
        printf("NO SOLUTION\n");
        return 0;
    }
    char ch;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            map[i][j] = (read() == '\\');
        }
    memset(dis, 0x3f, sizeof(dis));
    // for (int i = 0; i < N; i++)
    // {
    //     for (int j = 0; j < M; j++)
    //     {
    //         putchar(0x30 + map[i][j]);
    //     }
    //     putchar('\n');
    // }
    deque<int> deq;
    deq.push_back(0);
    dis[0][0] = 0;
    while (!vis[N][M] && !deq.empty())
    {
        int x = deq.front() >> 9;
        int y = deq.front() & 511;
        deq.pop_front();
        // if (vis[x][y])
        //     continue;
        // vis[x][y] = true;
        for (int i = -1; i <= 1; i += 2)
        {
            for (int j = -1; j <= 1; j += 2)
            {
                if ((x + i < 0) || (x + i > N) || (y + j < 0) || (y + j > M))
                    continue;
                int t = map[x - (i == -1)][y - (j == -1)] == (i != j);
                if (dis[x + i][y + j] > dis[x][y] + t)
                    if (t)
                    {
                        dis[x + i][y + j] = dis[x][y] + 1;
                        deq.push_back(((x + i) << 9) | (y + j));
                    }
                    else
                    {
                        dis[x + i][y + j] = dis[x][y];
                        deq.push_front(((x + i) << 9) | (y + j));
                    }
            }
        }
    }
    printf("%d\n", dis[N][M]);
    return 0;
}