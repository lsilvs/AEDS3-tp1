// .c

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int **aloca_matriz(int linhas, int colunas) {
	// Aloca a matriz
	int ** matriz;
	int i;

	matriz = (int **) malloc(linhas * sizeof(int *));

	for(i = 0; i < linhas; i++) {
		matriz[i] = (int *) malloc(colunas * sizeof(int));	
	}
	return(matriz);
}

int **preenche_matriz(FILE *arquivo, int linhas, int colunas) {
	// Aloca a matriz
	int ** matriz;
	int i, j;

	matriz = aloca_matriz(linhas, colunas);

	// Preenche a matriz
	for(i = 0; i < linhas; i++) {
		for(j = 0; j < colunas; j++) {
			fscanf(arquivo, "%d", &matriz[i][j]);
		}
	}
	return(matriz);
}

void desaloca_matriz(int ** matriz, int linhas) {
	// Desaloca a matriz
	int i;
	for(i = 0; i < linhas; i++) {
		free(matriz[i]);
	}
	free(matriz);
}