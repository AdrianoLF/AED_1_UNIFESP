#include <stdlib.h>
#include <stdio.h>

/*
  Vetor para lista. Escreva uma função que copie um vetor para uma lista encadeada.
*/
typedef struct cel {
  int valor;
  struct cel *prox;
} celula;

void Copia(celula *cabeca, int vetor[], int n) {
  celula *ptr = cabeca;
  for (int i = 0; i < n; i++) {
    ptr->prox = (celula *) malloc(sizeof(celula));
    ptr->prox->valor = vetor[i];
    ptr = ptr->prox;
  }
}

void main() {
  int arr[5] = {11,23,34,45,56};
  celula *cabeca = (celula *) malloc(sizeof(celula));
  Copia(cabeca, arr, 5);
  printf("#1: %i\n", cabeca->prox->valor);
  printf("#2: %i\n", cabeca->prox->prox->valor);
  printf("#3: %i\n", cabeca->prox->prox->prox->valor);
  printf("#4: %i\n", cabeca->prox->prox->prox->prox->valor);
  printf("#5: %i\n", cabeca->prox->prox->prox->prox->prox->valor);
}
