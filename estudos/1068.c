#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    char valor;
    struct cel *seg;
} celula;

char Desempilha(celula **topo) {
    if (*topo == NULL) {
        printf("Erro: pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    celula *q = *topo;
    char valor = q->valor;
    *topo = q->seg;
    free(q);
    return valor;
}

void Empilhaa(celula **topo, char valor) {
    celula *nova = malloc(sizeof(celula));
    if (nova == NULL) {
        printf("Erro: falha na alocação de memória.\n");
        exit(EXIT_FAILURE);
    }
    nova->valor = valor;
    nova->seg = *topo;
    *topo = nova;
}

int VerificaParentese(char expressao[]) {
    celula *pilha = NULL;
    int i = 0;

    while (expressao[i] != '\0') {
        if (expressao[i] == '(') {
            Empilhaa(&pilha, '(');
        } else if (expressao[i] == ')') {
            if (pilha == NULL || Desempilha(&pilha) != '(') {
                return 0;
            }
        }
        i++;
    }

    if (pilha != NULL) {
        return 0;
    }

    return 1; // Todos os parênteses estão corretos
}

int main() {
    char expressao[1001];

    while (scanf("%[^\n]%*c", expressao) != EOF) {
        if (VerificaParentese(expressao)) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
        if (expressao[0] == '\0') {
            break;
        }
    }

    return 0;
}
