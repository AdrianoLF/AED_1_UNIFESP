#include <stdio.h>
#include <stdlib.h>

/*
Lista para vetor. Escreva uma função que copie uma lista encadeada para um vetor.
*/
typedef struct cel {
    int valor;
    struct cel *prox;
} celula;

void Copia(int *endPrimeiroIndexArray, celula *cabeca) {
  celula *celAtual = cabeca->prox;
  int indexAtual = 0;

  while (celAtual != NULL) {
    // Pego o endereço do primeiro item do vetor e calculo o endereço dos itens subsequentes conforme percorro a lista
    int *elementoArray = endPrimeiroIndexArray + indexAtual;
    *elementoArray = celAtual->valor;
    // Pula para o próximo item da lista
    celAtual = celAtual->prox;

    ++indexAtual;
  }
}

void main() {
  int arr[3] = {11,22,33};
  
  // Cabeça da lista
  celula *primeiro = (celula *) malloc(sizeof(celula));

  // Primeiro elemento
  primeiro->prox = (celula *) malloc(sizeof(celula));
  primeiro->prox->valor = 111;
  
  // Segundo elemento
  primeiro->prox->prox = (celula *) malloc(sizeof(celula));
  primeiro->prox->prox->valor = 222;
  
  // Terceiro elemento
  primeiro->prox->prox->prox = (celula *) malloc(sizeof(celula));
  primeiro->prox->prox->prox->valor = 333;
  
  printf("O vetor inicial: [");
  for(int i; i<3;++i) printf("%i, ", arr[i]);
  printf("]\n\n");

  Copia(&arr[0], primeiro);

  printf("O vetor novo transcrito: [");
  for(int i; i<3;++i) printf("%i, ", arr[i]);
  printf("]\n\n");
}
