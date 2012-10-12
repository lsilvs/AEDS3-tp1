// .c

#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"


TipoValorVertice cenario1(TipoGrafo *Grafo) {

	TipoValorVertice raiz = 0;

	int i, u, dist = 0, aux = 0, indver = 0;

	TipoPeso * P = Dijkstra(Grafo, &raiz);

	for (u = 0; u < Grafo->NumVertices; u++) {
		dist += P[u];
	}


	for(i = 1; i < Grafo->NumVertices; i++) {
		raiz++;
		aux = 0;
		//aux = Dijkstra(Grafo, &raiz);

		P = Dijkstra(Grafo, &raiz);;

		for (u = 0; u < Grafo->NumVertices; u++) {
			aux += P[u];
		}

		// printf("%d %d\n", aux, dist); getchar();

		if(aux < dist){
		  indver = i;
		  // printf("%d\n", indver);
		  dist = aux;
		}
	}

	free(P);

	return indver + 1;
}

TipoValorVertice cenario2(TipoGrafo *Grafo) {
  // TipoValorVertice raiz = 0;

  // int i = 0, indver = 0;
  // double dist = 0.0, aux = 0.0;
  // dist = (double) Dijkstra(Grafo, &raiz);
  // printf("%f\n", dist);
  // dist = (double) dist/(Grafo->Pesos[i]);
  // printf("%f\n", dist);
  // getchar();
  
  // for(i = 1; i < Grafo->NumVertices; i++) {
  //   raiz++;
  //   aux = (double) Dijkstra(Grafo, &raiz);
  //   printf("%f\n", aux);
  //   aux = (double) aux/(Grafo->Pesos[i]);
  //   printf("%f\n", aux);
  //   getchar();
  //   if(aux < dist) {
  //     indver = i;
  //     dist = aux;
  //   }
  // }

  return 1;
}