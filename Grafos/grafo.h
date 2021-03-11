#include <iostream>

typedef struct grafo Grafo;

Grafo* cria_grafo(int nro_vertices, int grau_max, int eh_ponderado);
void libera_grafo(Grafo *gr);
int insere_aresta(Grafo *gr,int orig,int dest,int eh_digrafo,float peso);
int remove_aresta(Grafo *gr,int orig,int dest,int eh_digrafo);
void aux_busca_profundidade(Grafo *gr, int ini, int *visitado,
 int cont);
void busca_profundidade(Grafo *gr, int ini, int *visitado);
void busca_largura(Grafo *gr, int ini, int *visitado);
int menor_distancia(float *dist, int *visitado, int NV);
void busca_menor_caminho(Grafo *gr,int ini,int *ant, float *dist);
void algPRIM(Grafo* gr,int orig, int *pai);