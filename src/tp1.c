/*
*	Problema de Grafos
*		Autor: Lucas Silvestre (2010054665)
*		Data: 09/10/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"
#include "funcoes_grafo.h"

int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * inputFileName = argv[1];
	char * outputFileName = argv[2];
	int numInstancias, numCidades, i, j, k, l;
	TipoValorVertice V1, V2;
	TipoPeso peso;
	TipoGrafo grafo;

	// Abrir arquivo de entrada
	FILE * inputFileOpen;
	if ((inputFileOpen = fopen(inputFileName, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	// Abrir arquivo de saída
	FILE * outputFileOpen;
	if ((outputFileOpen = fopen(outputFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	// Abrir arquivo de testes
	char * testFileName = "test.out";
	FILE * testFileOpen;
	if ((testFileOpen = fopen(testFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	// Lê o número de instâncias
	fscanf(inputFileOpen, "%d", &numInstancias);


	for(i = 0; i < numInstancias; i++) {

		clock_t start = clock();

		// Lê o número de cidades
		fscanf(inputFileOpen, "%d", &numCidades);

		// Preenche o grafo
		grafo = alocaGrafo(numCidades);
		for (k = 0; k < numCidades; ++k) {
			for (l = 0; l < numCidades; ++l) {
				V1 = k;
				V2 = l;
				fscanf(inputFileOpen, "%d", &peso);
				InsereAresta(&V1, &V2, &peso, &grafo);
				if (peso > 0) {
					grafo.NumArestas++;
				}
			}
		}

		for (j = 0; j < numCidades; ++j) {
			fscanf(inputFileOpen, "%d", &grafo.Pedidos[j]);
		}

		fprintf(outputFileOpen, "%d %d %d %.2f\n", cenario1(&grafo), cenario2(&grafo), cenario3(&grafo), cenario_prejuizo(&grafo));

		liberaGrafo(grafo);

		fprintf(testFileOpen, "%f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	}


	// Retorna 0 se conseguiu fechar o arquivo com sucesso
	if(fclose(inputFileOpen) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", inputFileName);
	}

	if(fclose(outputFileOpen) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", inputFileName);
	}

	if(fclose(testFileOpen) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", inputFileName);
	}

	return 0;
}