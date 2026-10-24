#include <stdio.h>

int N, K;
long long total = 0;
int visited[200][200];

struct Move {
    int dx;
    int dy;
};

struct Move moves[8] = {
    { 2,  1}, { 1,  2}, {-1,  2}, {-2,  1},
    {-2, -1}, {-1, -2}, { 1, -2}, { 2, -1}
};

void findRoutes(int x, int y, int steps)
{
    if (steps == K) {
        total++;
        return;
    }

    for (int i = 0; i < 8; i++) {
        int nx = x + moves[i].dx;
        int ny = y + moves[i].dy;

        if (nx >= 0 && nx < N && ny >= 0 && ny < N && !visited[nx][ny]) {
            visited[nx][ny] = 1;
            findRoutes(nx, ny, steps + 1);
            visited[nx][ny] = 0;
        }
    }
}

int main(void)
{
    printf("Enter N (0 < N < 201) and K (K >= 0): ");
    if (scanf("%d %d", &N, &K) != 2) {
        printf("Error: enter two integers\n");
        return 1;
    }
    if (N < 1 || N > 200) {
        printf("Error: 0 < N < 201\n");
        return 1;
    }
    if (K < 0) {
        printf("Error: K >= 0\n");
        return 1;
    }

    visited[0][0] = 1;
    findRoutes(0, 0, 0);

    printf("Result: %lld\n", total);
    return 0;
}