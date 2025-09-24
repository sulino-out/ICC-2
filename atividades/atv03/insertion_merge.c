#include <stdio.h>
#include <stdlib.h>

/* Definicao de variáveis globais */
#define MAX_VETORES 100
#define MAX_TAMANHO 10000
int trocas_insertion;
int trocas_merge;
int comparacoes_insertion;
int comparacoes_merge;

/* Protótipos de funcoes */

void insertion_sort(int vetor[], int n);
void merge_sort(int vetor[], int n);
void merge(int vetor[], int left, int right, int novo_vetor[]);
void merge_dois_vetores(int vetor[], int left1, int right1, int left2, int right2, int novo_vetor[]);
void copia_vetor(int copia[], int vetor[], int n);

/* Funcao main */

int main()
{
	/* Inicializacao dos vetores */

	int vetor[MAX_VETORES][MAX_TAMANHO];
	
	// Pede a quantidade de vetores
	int num_vetores;
	// printf("Insira a quantidade de vetores: ");
	scanf("%d", &num_vetores);

	int tam_vetor[num_vetores];

	int maior_tamanho = 0;
	// Para cada vetor, pede o tamanho e cria o vetor
	for(int i = 0; i < num_vetores; i++)
	{
		// printf("Insira o tamanho do vetor %d: ", i);
		scanf("%d", &tam_vetor[i]);

		// Verifica o maior tamanho inserido
		// para a criacao de uma cópia futuramente
		// sem ocupar muito espaco na memória
		if(maior_tamanho < tam_vetor[i])
		{
			maior_tamanho = tam_vetor[i];
		}
	}
	
	// Pede os valores dos elementos de cada um dos vetores
	for(int i = 0; i < num_vetores; i++)
	{
		for(int j = 0; j < tam_vetor[i]; j++)
		{
			// printf("Insira o valor %d do vetor %d: ", j, i);
			scanf("%d", &vetor[i][j]);
		}
	}

	int copia[num_vetores][maior_tamanho]; // Inicializa uma cópia do vetor

	/* Realizacao dos algoritmos de ordenacao */

	for(int i = 0; i < num_vetores; i++)
	{
		// Reseta o contador de operacoes
		trocas_insertion = 0;
		comparacoes_insertion = 0;
		trocas_merge = 0;
		comparacoes_merge = 0;

		// Cria uma cópia do vetor antigo, para que possamos ordená-lo duas vezes com algoritmos diferentes
		copia_vetor(copia[i], vetor[i], tam_vetor[i]);
		
		insertion_sort(vetor[i], tam_vetor[i]);

		printf("I %d %d %d\n", tam_vetor[i], trocas_insertion, comparacoes_insertion);

		merge_sort(copia[i], tam_vetor[i]);

		printf("M %d %d %d\n", tam_vetor[i], trocas_merge, comparacoes_merge);
	}

	return 0;
}

/* Outras funcoes */

void insertion_sort(int vetor[], int n)
{
	for(int i = 1; i < n; i++)
	{
		trocas_insertion++;
		int elemento = vetor[i];

		int j = i - 1;

		while(j >= 0)
		{
			comparacoes_insertion++;
			if(vetor[j] > elemento)
			{
				trocas_insertion++;
				vetor[j + 1] = vetor[j];
				j--;
			}
			else
			{
				break;
			}
		}

		trocas_insertion++;
		vetor[j + 1] = elemento;
	}
}

void merge_sort(int vetor[], int n)
{
	int *novo_vetor = (int *)malloc(sizeof(int) * n);
	if(novo_vetor == NULL)
		exit(-1);

	merge(vetor, 0, n - 1, novo_vetor);
	
	free(novo_vetor);
}

void merge(int vetor[], int left, int right, int novo_vetor[])
{
	// Caso base
	if(left >= right)
		return;

	// Caso recursivo
	int middle = (left + right) / 2;

	merge(vetor, left, middle, novo_vetor);
	merge(vetor, middle + 1, right, novo_vetor);
	merge_dois_vetores(vetor, left, middle, middle + 1, right, novo_vetor);
}

void merge_dois_vetores(int vetor[], int left1, int right1, int left2, int right2, int novo_vetor[])
{
	int i1 = left1;
	int i2 = left2;
	int j = 0;
	while(i1 <= right1 && i2 <= right2)
	{
		comparacoes_merge++;
		if(vetor[i1] <= vetor[i2])
		{
			trocas_merge++;
			novo_vetor[j] = vetor[i1];
			j++;
			i1++;
		}
		else
		{
			trocas_merge++;
			novo_vetor[j] = vetor[i2];
			j++;
			i2++;
		}
	}

	while(i1 <= right1)
	{
		trocas_merge++;
		novo_vetor[j] = vetor[i1];
		j++;
		i1++;
	}

	while(i2 <= right2)
	{
		trocas_merge++;
		novo_vetor[j] = vetor[i2];
		j++;
		i2++;
	}

	j = 0;
	for(int i = left1; i <= right2; i++, j++)
	{
		trocas_merge++;
		vetor[i] = novo_vetor[j];
	}
}

void copia_vetor(int copia[], int vetor[], int n)
{
	for(int i = 0; i < n; i++)
	{
		copia[i] = vetor[i];
	}
}
