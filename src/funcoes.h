// .h

#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

// Aloca a matriz dinamicamente
int ** aloca_matriz(int linhas, int colunas);

// Preenche uma matriz de acordo com arquivo passado
int ** preenche_matriz(FILE *arquivo, int linhas, int colunas);

// Desaloca matriz passada como parâmetro
void desaloca_matriz(int ** matriz, int linhas);

#endif