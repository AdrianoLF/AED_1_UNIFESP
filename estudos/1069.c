#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int top;
    int capacidade;
    char *array;
} Stack;

Stack *createStack(int capacidade) {
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->capacidade = capacidade;
    stack->top = -1;
    stack->array = (char *)malloc(stack->capacidade * sizeof(char));
    return stack;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, char item) {
    stack->array[++stack->top] = item;
}

char pop(Stack *stack) {
    if (!isEmpty(stack))
        return stack->array[stack->top--];
    return '\0';
}

int countDiamonds(char *s) {
    Stack *stack = createStack(strlen(s));
    int diamonds = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '<') {
            push(stack, '<');
        } else if (s[i] == '>') {
            if (!isEmpty(stack) && stack->array[stack->top] == '<') {
                diamonds++;
                pop(stack);
            }
        }
    }

    free(stack->array);
    free(stack);
    return diamonds;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar();

    char **inputs = (char **)malloc(N * sizeof(char *));
    int *results = (int *)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        char *s = (char *)malloc(1001 * sizeof(char));
        fgets(s, 1001, stdin);
        inputs[i] = s;
        results[i] = countDiamonds(s);
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", results[i]);
        free(inputs[i]);
    }

    free(inputs);
    free(results);

    return 0;
}
