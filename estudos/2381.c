#include <stdlib.h>
#include <string.h>

int comparar(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

int main() {
    int N, X;
    scanf("%d %d", &N, &X);
    char **nomes = (char **)malloc(N * sizeof(char *));
    for (int i = 0; i < N; i++) {
        nomes[i] = (char *)malloc(21 * sizeof(char));
        scanf("%s", nomes[i]);
    }
    qsort(nomes, N, sizeof(char *), comparar);
    char *nome_do_aluno = nomes[X - 1];
    printf("%s\n", nome_do_aluno);
    for (int i = 0; i < N; i++) {
        free(nomes[i]);
    }
    free(nomes);
    return 0;
}
