#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_ORDENACAO 9

const char* check_bolha = "bolha";
const char* check_selecao = "selecao";

int troca(int *a, int *b);
void bubble_sort(int *vetor, int n);
void selection_sort(int *vetor, int n);

int main()
{
	char ordenacao[MAX_ORDENACAO];
	fgets(ordenacao, MAX_ORDENACAO, stdin);

	int length = strlen(ordenacao);
	ordenacao[length - 1] = '\0';

	if((strcmp(ordenacao, check_bolha) != 0) && (strcmp(ordenacao, check_selecao) != 0))
	{
		printf("Opcao invalida.\n");
		return 0;
	}

	int tam_vetor;
	scanf("%d", &tam_vetor);
	
	int vetor[tam_vetor];
	for(int i = 0; i < tam_vetor; i++)
	{
		scanf("%d", &vetor[i]);
	}

	if(strcmp(ordenacao, check_bolha) == 0)
	{
		bubble_sort(vetor, tam_vetor);
	}
	else if(strcmp(ordenacao, check_selecao) == 0)
	{
		selection_sort(vetor, tam_vetor);
	}

	for(int i = 0; i < tam_vetor; i++)
	{
		printf("%d ", vetor[i]);
	}

	printf("\n");

	return 0;
}

int troca(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void bubble_sort(int *vetor, int n)
{
	int flag;
	int i = n - 1;

	while(i > 0)
	{
		flag = -1;

		for(int j = 0; j < i; j++)
		{
			printf("C %d %d\n", j, j + 1);
			if(vetor[j] > vetor[j + 1])
			{
				printf("T %d %d\n", j, j + 1);
				troca(&vetor[j], &vetor[j + 1]);
				flag = j;
			}
		}

		i = flag;
	}

	return;
}

void selection_sort(int *vetor, int n)
{
	int posicao;

	for(int i = 0; i < n - 1; i++)
	{
		posicao = i;

		for(int j = i + 1; j < n; j++)
		{
			printf("C %d %d\n", posicao, j);
			if(vetor[j] < vetor[posicao])
			{
				posicao = j;
			}
		}

		printf("T %d %d\n", i, posicao);
		troca(&vetor[i], &vetor[posicao]);
	}

	return;
}

