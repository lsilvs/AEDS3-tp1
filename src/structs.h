// Structs

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define FALSE           0
#define TRUE            1
#define INFINITO       INT_MAX

typedef int TipoPeso;
typedef struct TipoGrafo {
	TipoPeso ** Mat;
	int * Pedidos;
	int NumVertices;
	int NumArestas;
} TipoGrafo;

typedef int TipoValorVertice;
typedef TipoValorVertice TipoApontador;
typedef int TipoIndice;
typedef struct TipoItem {
	TipoPeso Chave;
} TipoItem;

typedef TipoItem TipoVetor;

/*Tamanho do heap*/
TipoIndice n;