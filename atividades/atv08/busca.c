// Library inclusion
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Defining pseudo-variables
#define TRUE 1
#define FALSE 0

// Function prototypes
int busca_sequencial(int vetor[], int n, int elemento);
void quick(int v[], int f, int l);
int busca_binaria_recursiva(int vetor[], int elemento, int inicio, int fim);

int main(int argc, char *argv[])
{
	int n;
	scanf("%d", &n);

	int vetor[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &vetor[i]);
	}

	int k;
	scanf("%d", &k);

	int inteiros[k];
	for(int i = 0; i < k; i++)
	{
		scanf("%d", &inteiros[i]);
	}

	int is_sorted = FALSE;
	if(k > log2(n))
	{
		int inicio = 0;
		int fim = n - 1;
		quick(vetor, inicio, fim);
		is_sorted = TRUE;
	}

	if(is_sorted)
	{
		int inicio = 0;
		int fim = n - 1;
		for(int i = 0; i < k; i++)
		{
			printf("%d\n", busca_binaria_recursiva(vetor, inteiros[i], inicio, fim));
		}
	}
	else
	{
		for(int i = 0; i < k; i++)
		{
			printf("%d\n", busca_sequencial(vetor, n, inteiros[i]));
		}
	}

	return 0;
}

// Functions
int busca_sequencial(int vetor[], int n, int elemento)
{
	for(int i = 0; i < n; i++)
	{
		if(vetor[i] == elemento)
		{
			return TRUE;
		}
	}

	return FALSE;
}



void quick(int v[], int f, int l)
{
	if (f >= l) 
	{
		return;
        }
	int m = (l + f)/2;

	int pivot = v[m]; 

	int i = f;
	int j = l;

        while(1) 
	{
                while(v[i] < pivot) 
		{
                        i++;
                }

                while(v[j] > pivot) 
		{
                        j--;
                }

                if (i >= j) 
		{
                        break;
                }

                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
                i++;
                j--;

        }

        quick(v, f, j);
        quick(v, j+1, l);
}

int busca_binaria_recursiva(int vetor[], int elemento, int inicio, int fim)
{
	/* Casos base */

	if(fim < inicio) // Caso 1: Posicao final é menor que a posicao inicial (Elemento nao encontrado)
	{
		return FALSE;
	}

	int meio = inicio + ((fim - inicio) / 2); // Define a posicao intermediária do vetor
	
	if(vetor[meio] == elemento) // Caso 2: Elemento central do vetor é igual ao desejado (Elemento encontrado)
	{
		return TRUE;
	}

	/* Caso recursivo */

	// Declara as variaveis para os novos novo_inicio e novo_fim
	int novo_inicio = inicio;
	int novo_fim = fim;

	if(vetor[meio] < elemento) // Se o elemento central do vetor for menor que o elemento, corta a metade da esquerda
	{
		novo_inicio = meio + 1;
	}
	else if(vetor[meio] > elemento) // Se o elemento central do vetor for maior que o elemento, corta a metade da direita
	{
		novo_fim = meio - 1;
	}

	busca_binaria_recursiva(vetor, elemento, novo_inicio, novo_fim); // Chama recursivamente a funcao
}
