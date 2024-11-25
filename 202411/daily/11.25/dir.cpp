#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const int dire[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
const int trans[4][2][2] = {
    {{1, 0}, {0, 1}}, {{0, 1}, {-1, 0}}, {{-1, 0}, {0, -1}}, {{0, -1}, {1, 0}}};
int n;
char cmd[MAXN];
typedef struct {
    int x, y, dire;
} Status;
Status currentStatus[MAXN];
Status backStatus[MAXN];
set<pair<int, int>> finalCoords;
pair<int, int> test(int idx, char ch)
{
    Status status = currentStatus[idx - 1];
    switch (ch) {
        case 'F':
            status.x += dire[status.dire][0];
            status.y += dire[status.dire][1];
            status.x += backStatus[idx + 1].x * trans[status.dire][0][0] +
                        backStatus[idx + 1].y * trans[status.dire][0][1];
            status.y += backStatus[idx + 1].x * trans[status.dire][1][0] +
                        backStatus[idx + 1].y * trans[status.dire][1][1];
            status.dire = (backStatus[idx + 1].dire + status.dire) % 4;
            break;
        case 'L':
            status.dire = (status.dire + 3) % 4;
            status.x += backStatus[idx + 1].x * trans[status.dire][0][0] +
                        backStatus[idx + 1].y * trans[status.dire][0][1];
            status.y += backStatus[idx + 1].x * trans[status.dire][1][0] +
                        backStatus[idx + 1].y * trans[status.dire][1][1];
            break;
        case 'R':
            status.dire = (status.dire + 1) % 4;
            status.x += backStatus[idx + 1].x * trans[status.dire][0][0] +
                        backStatus[idx + 1].y * trans[status.dire][0][1];
            status.y += backStatus[idx + 1].x * trans[status.dire][1][0] +
                        backStatus[idx + 1].y * trans[status.dire][1][1];
        default:
            break;
    }
    return {status.x, status.y};
}
int main()
{
    freopen("dir.in", "r", stdin);
    freopen("dir.out", "w", stdout);
    scanf("%s", cmd + 1);
    n = strlen(cmd + 1);
    for (int i = 1; i <= n; i++) {
        switch (cmd[i]) {
            case 'F':
                currentStatus[i].dire = currentStatus[i - 1].dire;
                currentStatus[i].x =
                    currentStatus[i - 1].x + dire[currentStatus[i - 1].dire][0];
                currentStatus[i].y =
                    currentStatus[i - 1].y + dire[currentStatus[i - 1].dire][1];
                break;

            case 'L':
                currentStatus[i].dire = (currentStatus[i - 1].dire + 3) % 4;
                currentStatus[i].x = currentStatus[i - 1].x;
                currentStatus[i].y = currentStatus[i - 1].y;
                break;

            case 'R':
                currentStatus[i].dire = (currentStatus[i - 1].dire + 1) % 4;
                currentStatus[i].x = currentStatus[i - 1].x;
                currentStatus[i].y = currentStatus[i - 1].y;
                break;
        }
    }
    for (int i = n; i >= 1; i--) {
        switch (cmd[i]) {
            case 'F':
                backStatus[i].dire = backStatus[i + 1].dire;
                backStatus[i].x = backStatus[i + 1].x + dire[0][0];
                backStatus[i].y = backStatus[i + 1].y + dire[0][1];
                break;

            case 'L':
                backStatus[i].dire = (backStatus[i + 1].dire + 3) % 4;
                backStatus[i].x = -backStatus[i + 1].y;
                backStatus[i].y = backStatus[i + 1].x;
                break;

            case 'R':
                backStatus[i].dire = (backStatus[i + 1].dire + 1) % 4;
                backStatus[i].x = backStatus[i + 1].y;
                backStatus[i].y = -backStatus[i + 1].x;
                break;
        }
    }
    for (int i = 1; i <= n; i++) {
        switch (cmd[i]) {
            case 'F':
                finalCoords.insert(test(i, 'L'));
                finalCoords.insert(test(i, 'R'));
                break;
            case 'L':
                finalCoords.insert(test(i, 'F'));
                finalCoords.insert(test(i, 'R'));
                break;
            case 'R':
                finalCoords.insert(test(i, 'F'));
                finalCoords.insert(test(i, 'L'));
                break;
            default:
                break;
        }
    }
    printf("%d\n", finalCoords.size());
    return 0;
}