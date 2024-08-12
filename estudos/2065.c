#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M, i, j;
    scanf("%d %d", &N, &M);
    int *funcionarios = (int*) malloc(N * sizeof(int));
    int *clientes = (int*) malloc(M * sizeof(int));
    for (i = 0; i < N; i++) {
        scanf("%d", &funcionarios[i]);
    }
    for (i = 0; i < M; i++) {
        scanf("%d", &clientes[i]);
    }

    long long *time_added = (long long*) calloc(N, sizeof(long long));

    long long tempo_total = 0;
    for (i = 0; i < M; i++) {
        int idx_funcionario_min = 0;
        for (j = 1; j < N; j++) {
            if (time_added[j] < time_added[idx_funcionario_min]) {
                idx_funcionario_min = j;
            }
        }
        time_added[idx_funcionario_min] += (long long) clientes[i] * funcionarios[idx_funcionario_min];
        if (time_added[idx_funcionario_min] > tempo_total) {
            tempo_total = time_added[idx_funcionario_min];
        }
    }

    printf("%lld\n", tempo_total);

    free(funcionarios);
    free(clientes);
    free(time_added);

    return 0;
}
