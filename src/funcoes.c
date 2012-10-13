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

		P = Dijkstra(Grafo, &raiz);;

		for (u = 0; u < Grafo->NumVertices; u++) {
			aux += P[u];
		}

		if(aux < dist){
		  indver = i;
		  dist = aux;
		}
	}

	return indver + 1;
}

TipoValorVertice cenario2(TipoGrafo *Grafo) {

	TipoValorVertice raiz = 0;

	int i, u, indver = 0;
	float dist = 0.0, aux = 0.0;

	TipoPeso * P = Dijkstra(Grafo, &raiz);

	for (u = 0; u < Grafo->NumVertices; u++) {
		dist += (float) P[u]*Grafo->Pesos[u];
	}


	for(i = 1; i < Grafo->NumVertices; i++) {
		raiz++;
		aux = 0;
		//aux = Dijkstra(Grafo, &raiz);

		P = Dijkstra(Grafo, &raiz);;

		for (u = 0; u < Grafo->NumVertices; u++) {
			aux += (float) P[u]*Grafo->Pesos[u];
		}

		if(aux < dist){
		  indver = i;
		  dist = aux;
		}
	}

	return indver + 1;
}


TipoValorVertice cenario3(TipoGrafo *Grafo) {
    TipoValorVertice raiz = 0;

    int result = 0, maior = 0, aux = 9999999, i, u;

    TipoPeso * P;

    for (i = 0; i < Grafo->NumVertices; i++) {
    	maior = 0;

        P = Dijkstra(Grafo, &raiz);
        for (u = 0; u < Grafo->NumVertices; u++) {
			if (maior < P[u]) {
				maior = P[u];
			}
		}

        if (maior < aux) {
        	result = raiz;
        	aux = maior;
        }

        raiz++;
    }

    return result+1;
}

float cenario_prejuizo(TipoGrafo *Grafo) {

    TipoValorVertice raiz = 0;

    int soma = 0, maior = 0, peso_maior = 0, soma_menor2 = 9999999, soma_aux2 = 0, aux = 999999, soma_maior = 0, i, j;
    float result, soma_aux = 0.0, soma_menor = 99999999.99;

    TipoPeso * P;

    for (i = 0; i < Grafo->NumVertices; i++){

    	soma = 0;
    	maior = 0;

        P = Dijkstra(Grafo, &raiz);
        for (j = 0; j < Grafo->NumVertices; j++) {
            soma += P[j];
            if (maior < P[j]) {
				soma_maior = soma;
				maior = P[j];
			}
        }

        if (soma < soma_menor) {
        	soma_menor = soma;
       	}

       	if (maior < aux) {
        	aux = maior;
        	soma_aux = soma;
        }

        raiz++;
    }

    result = (float) (soma_aux*100/soma_menor)-100;

    return result;

}

