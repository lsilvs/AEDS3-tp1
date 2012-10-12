// .h

#ifndef FUNCOES_GRAFO_H_INCLUDED
#define FUNCOES_GRAFO_H_INCLUDED

#include "structs.c"

void FGVazio(TipoGrafo *Grafo);

void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, 
          TipoGrafo *Grafo);

short  ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2, 
            TipoGrafo *Grafo);

/*-- Operadores para obter a lista de adjacentes --*/
short ListaAdjVazia(TipoValorVertice *Vertice, TipoGrafo *Grafo);

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo);

void ProxAdj(TipoValorVertice *Vertice, TipoGrafo *Grafo, 
         TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, 
         short *FimListaAdj);

void ImprimeGrafo(TipoGrafo *Grafo);

void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *A, TipoPeso *P, 
            TipoValorVertice *Pos);

void Constroi(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos);

TipoItem RetiraMinInd(TipoItem *A,  TipoPeso *P,  TipoValorVertice *Pos);

void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *A, 
             TipoPeso *P,  TipoValorVertice *Pos);

int Dijkstra(TipoGrafo *Grafo, TipoValorVertice *Raiz);

#endif