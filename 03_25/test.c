#include <stdio.h>
#include <string.h>

void removerCaracteresDaFrase(char *str, int indice) {
    int i = indice;
    int j = 0;
    for (; str[i] != '\0'; i++, j++) {
        str[j] = str[i];
    }
    str[j] = '\0';
}

void removerEspacosDaFrase(char *str) {
    int i = 0;
    int j = 0;
    for (; str[i]; i++) {
        if (str[i] != ' ') {
           str[j++] = str[i];
        }
    }
    str[j] = '\0';
}

 
int main() {
    // int casos_de_teste;
    // scanf("%d", &casos_de_teste);
    printf("---- SAÍDA ----------------");
    char frase[21000];
    char lista[1000][20];

    // printf("DIgite uma frase: ");
    // fgets(frase, sizeof(frase), stdin);
    // printf("A frase digitada foi: %s", frase);


    // for (int i = 0; i < casos_de_teste; i++) {
    //     char linha[];
    //     scanf("%s", &linha);

    //     printf("%d\n", i);

    //     // printf("%d\n", casos_de_teste);
    // }
    
    // Acha o espaço na string
    char teste[] = "0123456789";
    char letra = '3';
    char primeira_palavra[20];
    int asdv = 5;

    char *diferenca = strchr(teste, letra); // Acha o primeiro caractere na string
    if (diferenca != NULL) {
        int index = diferenca - teste; // Indice de onde foi achado
        printf("\n");
        // printf("ta aqui : %d", index);
        // printf("\n");
        // printf("ta aqui : %s", diferenca );

        // printf("A FRASE É: %s\n", teste);
        // removerCaracteresDaFrase(teste, asdv);
        // printf("A FRASE ESTÁ AGORA: %s", teste);

        printf("O INDICE É: %d", index);
        printf("\n\n\n");

        // Target / Oirigin / Index 
        strncpy(primeira_palavra, teste, index); // Joga o conteúdo que a string tem até aquele index dentro da variável
        removerEspacosDaFrase(primeira_palavra); // Remove o espaço que sobrou da string
        removerCaracteresDaFrase(teste, ++index); // Remove o conteúdo colhido da frase
        printf("%s", teste);

        // printf("A OUTRA FICOU: %s", teste);
    } 
    else {
        printf("na real ta qui");
    };
    printf("\n\n");
    // printf("DIgite uma frase: %d", index);
}

void comparaSeEhIgual() {
    // COMPARA SE O CHAR É IGUAL OU NAO
    // char str1[] = "asd";
    // char str2[] = "vsc";

    // int abc;
    // abc = strcmp(str1, str2);
    // printf("%d", abc);
}