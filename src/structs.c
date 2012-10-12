// Structs

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1
#define INFINITO       INT_MAX


typedef int TipoValorVertice;

typedef int TipoPeso;

typedef struct TipoGrafo {
	TipoPeso Mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
	int  NumVertices;
	int  NumArestas;
} TipoGrafo;

typedef TipoValorVertice TipoApontador;
typedef int TipoIndice;
typedef struct TipoItem {
	TipoPeso Chave;
} TipoItem;

typedef TipoItem TipoVetor[MAXNUMVERTICES + 1];

TipoApontador Aux;
int  i, NArestas;
short FimListaAdj;
TipoValorVertice V1, V2, Adj;
TipoPeso Peso;
TipoGrafo Grafo;
TipoValorVertice NVertices;
TipoIndice n;   /*Tamanho do heap*/
TipoValorVertice Raiz;


