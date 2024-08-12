/***
 * João está trabalhando em uma mina, tentando retirar o máximo que consegue de diamantes "<>".
 * Ele deve excluir todas as particulas de areia "." do processo e a cada retirada de diamante,
 * novos diamantes poderão se formar. Se ele tem como uma entrada .<...<<..>>....>....>>>., três diamantes são formados.
 * O primeiro é retirado de <..>, resultando  .<...<>....>....>>>. 
 * Em seguida o segundo diamante é retirado,  * restando .<.......>....>>>. 
 * O terceiro diamante é então retirado, restando no final .....>>>., sem possibilidade de extração de novo diamante.
 * 
 * 
 * Entrada
 * Deve ser lido um valor inteiro N que representa a quantidade de casos de teste. Cada linha a seguir é um caso
 * de teste que contém até 1000 caracteres, incluindo "<,>, ."
 * 
 * Saída
 * Você deve imprimir a quantidade de diamantes possíveis de serem extraídos em cada caso de entrada.
 * ******************************************************************************************************************
*/
#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

typedef unsigned short us;

us diamonds(char *);

void main ()
{

	us n;
	int lixo;
	char string[1005];

	scanf("%hu", &n);
	scanf("%d", &lixo);

	while (n--)
	{

		fgets(string, 1005, stdin);
		string[strlen(string) - 1] = '\0';
		printf("%hu\n", diamonds(string));
		memset(string, 0, sizeof(string));

 	}
}

us diamonds(char *string)
{

	short x = 0;
	us qtsDiamonds = 0;

	us i, j;
	for (i = 0; string[i]; ++i)
	{

		if (string[i] != '<')
			continue;

		for (j = i + 1; string[j]; ++j)
			if (string[j] == '>')
			{

				++qtsDiamonds;
				string[i] = 'x';
				string[j] = 'x';
				break;

			}

	}

	return qtsDiamonds;

}