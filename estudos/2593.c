#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int acharPosicao(const char *text, const char *word);

int main() {
    char text[10001];
    char text_copy[10001];
    char words[128][51];
    int **positions;
    int n;

    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';
    strcpy(text_copy, text);

    scanf("%d", &n);

    positions = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        positions[i] = (int *)malloc(10001 * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    for (int i = 0; i < n; i++) {
        int j = 0;
        char *token = strtok(text_copy, " ");
        int pos = 0;

        while (token != NULL) {
            int found_pos = acharPosicao(token, words[i]);

            if (found_pos != -1) {
                positions[i][j++] = pos + found_pos;
            }

            pos += strlen(token) + 1;
            token = strtok(NULL, " ");
        }

        if (j == 0) {
            printf("-1\n");
        } else {
            for (int k = 0; k < j; k++) {
                printf("%d", positions[i][k]);
                if (j > 1 && k != j-1){
                    printf(" ");
                }
            }
            printf("\n");
        }

        strcpy(text_copy, text);
    }

    for (int i = 0; i < n; i++) {
        free(positions[i]);
    }
    free(positions);

    return 0;
}

int acharPosicao(const char *text, const char *word) {
    const char *found = strstr(text, word);

    if (found) {
        if ((found == text || isspace(*(found - 1))) &&
            (*(found + strlen(word)) == '\0' || isspace(*(found + strlen(word))))) {
            return found - text;
        }
    }
    return -1;
}
