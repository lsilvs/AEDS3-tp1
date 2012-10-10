/*
*	Problema de Grafos
*		Autor: Lucas Silvestre (2010054665)
*		Data: 09/10/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * inputFileName = argv[1];
	char * outputFileName = argv[2];
	int ** matriz;
	int numInstancias, numCidades, i, j, k, l, m;

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

	for(m = 0; m < numInstancias; m++) {
		// Lê o número de cidades
		fscanf(inputFileOpen, "%d", &numCidades);	

		// Preenche a matriz
		matriz = preenche_matriz(inputFileOpen, numCidades, numCidades);


		// Libera as matrizes já utilizadas
		desaloca_matriz(matriz, numCidades);

	}

	// Retorna 0 se conseguiu fechar o arquivo com sucesso
	if(fclose(inputFileOpen) == 0) {
		printf("%s fechado com sucesso\n", inputFileName);
	}

	if(fclose(outputFileOpen) == 0) {
		printf("%s fechado com sucesso\n", outputFileName);
	}

	return 0;
}