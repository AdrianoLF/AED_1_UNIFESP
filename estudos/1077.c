#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAMANHO_MAXIMO 300

typedef struct No {
    char dado;
    struct No* prox;
} No;

typedef struct {
    No* topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = NULL;
}

int isEmpty(Pilha* p) {
    return p->topo == NULL;
}

void empilhar(Pilha* p, char valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->dado = valor;
    novoNo->prox = p->topo;
    p->topo = novoNo;
}

char desempilhar(Pilha* p) {
    if (isEmpty(p)) {
        printf("Subfluxo de pilha\n");
        exit(EXIT_FAILURE);
    }
    No* temp = p->topo;
    char valor = temp->dado;
    p->topo = temp->prox;
    free(temp);
    return valor;
}

char topo(Pilha* p) {
    if (isEmpty(p)) {
        printf("Subfluxo de pilha\n");
        exit(EXIT_FAILURE);
    }
    return p->topo->dado;
}

int ehOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int precedencia(char c) {
    if (c == '+' || c == '-')
        return 1;
    if (c == '*' || c == '/')
        return 2;
    if (c == '^')
        return 3;
    return -1;
}

void infixParaPostfix(char *expressao, char *resultado) {
    Pilha pilha;
    inicializar(&pilha);

    int tamanho = strlen(expressao);
    int j = 0;

    for (int i = 0; i < tamanho; i++) {
        char atual = expressao[i];

        if (isalnum(atual)) {
            resultado[j++] = atual;
        } else if (atual == '(') {
            empilhar(&pilha, atual);
        } else if (atual == ')') {
            while (!isEmpty(&pilha) && topo(&pilha) != '(') {
                resultado[j++] = desempilhar(&pilha);
            }
            if (!isEmpty(&pilha) && topo(&pilha) != '(') {
                printf("Expressão inválida\n");
                exit(EXIT_FAILURE);
            } else {
                desempilhar(&pilha);
            }
        } else { // Se for um operador
            while (!isEmpty(&pilha) && precedencia(atual) <= precedencia(topo(&pilha))) {
                resultado[j++] = desempilhar(&pilha);
            }
            empilhar(&pilha, atual);
        }
    }
    while (!isEmpty(&pilha)) {
        resultado[j++] = desempilhar(&pilha);
    }
    resultado[j] = '\0';
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    char resultados[N][TAMANHO_MAXIMO];

    for (int i = 0; i < N; i++) {
        char expressao[TAMANHO_MAXIMO];
        fgets(expressao, TAMANHO_MAXIMO, stdin);
        infixParaPostfix(expressao, resultados[i]);
    }

    // Imprimir resultados
    for (int i = 0; i < N; i++) {
        printf("%s", resultados[i]);
    }

    return 0;
}
