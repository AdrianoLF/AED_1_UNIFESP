#include <stdio.h>
#include <string.h>
#define MAXN 501

int board[MAXN][MAXN];
int pblack[MAXN][MAXN];
int pwhite[MAXN][MAXN];

int get_sum(int matrix[MAXN][MAXN], int x1, int y1, int x2, int y2) {
    return matrix[x2+1][y2+1] - matrix[x1][y2+1] - matrix[x2+1][y1] + matrix[x1][y1];
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    memset(board, 0, sizeof(board));
    memset(pblack, 0, sizeof(pblack));
    memset(pwhite, 0, sizeof(pwhite));
    for (int i = 0; i < p; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        board[r][c] = 1;
    }
    for (int i = 0; i < p; i++) {
        int r, c;
        scanf("%d %d", &r, &c);
        board[r][c] = 2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            pblack[i][j] = pblack[i-1][j] + pblack[i][j-1] - pblack[i-1][j-1] + (board[i][j] == 1 ? 1 : 0);
            pwhite[i][j] = pwhite[i-1][j] + pwhite[i][j-1] - pwhite[i-1][j-1] + (board[i][j] == 2 ? 1 : 0);
        }
    }
    int black = 0;
    int white = 0;

    for (int size = 1; size <= n; size++) {
        for (int i = 0; i <= n - size; i++) {
            for (int j = 0; j <= n - size; j++) {
                int black_sum = get_sum(pblack, i, j, i + size - 1, j + size - 1);
                int white_sum = get_sum(pwhite, i, j, i + size - 1, j + size - 1);
                if (black_sum > 0 && white_sum == 0) {
                    black++;
                } else if (white_sum > 0 && black_sum == 0) {
                    white++;
                }
            }
        }
    }
    printf("%d %d\n", black, white);
    return 0;
    }