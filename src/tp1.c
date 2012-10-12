/*
*	Problema de Grafos
*		Autor: Lucas Silvestre (2010054665)
*		Data: 09/10/2012
*/

#include <stdio.h>
#include <stdlib.h>
// #include "funcoes.h"
#include "funcoes_grafo.h"

int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * inputFileName = argv[1];
	char * outputFileName = argv[2];
	int ** matriz;
	int numInstancias, numCidades, peso, i, j, k, l, m;

	// Abrir arquivo de entrada
	FILE * inputFileOpen;
	if ((inputFileOpen = fopen(inputFileName, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", inputFileName);
	}

	// Abrir arquivo de saída
	FILE * outputFileOpen;
	if ((outputFileOpen = fopen(outputFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	} else {
		printf("Aberto arquivo de entrada %s \n", outputFileName);
	}

	// Lê o número de instâncias
	fscanf(inputFileOpen, "%d", &numInstancias);
	// Escreve o número de instâncias no arquivo de saída
	fprintf(outputFileOpen, "%d\n", numInstancias);

	for(i = 0; i < numInstancias; i++) {
		// Lê o número de cidades
		fscanf(inputFileOpen, "%d", &numCidades);

		Grafo.NumVertices = numCidades;
		Grafo.NumArestas = 0;
		//FGVazio(&Grafo);

		for (k = 0; k < numCidades; ++k) {
			for (l = 0; l < numCidades; ++l) {
				V1 = k;
				V2 = l;
				fscanf(inputFileOpen, "%d", &Peso);
				InsereAresta(&V1, &V2, &Peso, &Grafo);
				if (Peso > 0) {
					Grafo.NumArestas++;
				}
			}
		}

	}

	// ImprimeGrafo(&Grafo);

	Raiz = 1;
	
	printf("%d\n", Dijkstra(&Grafo, &Raiz));


	// Retorna 0 se conseguiu fechar o arquivo com sucesso
	if(fclose(inputFileOpen) == 0) {
		printf("%s fechado com sucesso\n", inputFileName);
	}

	if(fclose(outputFileOpen) == 0) {
		printf("%s fechado com sucesso\n", outputFileName);
	}

	return 0;
}