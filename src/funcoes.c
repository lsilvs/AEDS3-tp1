// .c

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


TipoValorVertice cenario1(TipoGrafo *Grafo) {
  TipoValorVertice raiz = 0;

  int i, dist, aux, indver;
  dist = Dijkstra(Grafo, &raiz);
  indver = 0;
  
  for(i = 1; i < Grafo->NumVertices; i++) {
    raiz++;
    aux = Dijkstra(Grafo, &raiz);
    if(aux < dist){
      indver = i;
      // printf("%d\n", indver);
      dist = aux;
    }
  }

  return indver + 1;
}

TipoValorVertice cenario2(TipoGrafo *Grafo) {
  TipoValorVertice raiz = 0;

  int i, indver;
  float dist, aux;
  dist = (float) Dijkstra(Grafo, &raiz);
  dist = dist/Grafo->Pesos[i];
  indver = 0;
  
  for(i = 1; i < Grafo->NumVertices; i++) {
    raiz++;
    aux = (float) Dijkstra(Grafo, &raiz);
    aux = aux/Grafo->Pesos[i];
    if(aux < dist) {
      indver = i;
      // printf("%d\n", indver);
      dist = aux;
    }
  }

  return indver + 1;
}