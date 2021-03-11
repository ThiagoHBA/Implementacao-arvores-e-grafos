#include <iostream>

typedef struct NO* arvoreBin;
arvoreBin* cria_arvoreBinaria();
void libera_arvoreBinaria(arvoreBin* raiz);
void libera_noArvoreBinaria(struct NO* no);
int arvoreEstaVazia(arvoreBin* raiz);
int altura_arvoreBinaria(arvoreBin* raiz);
int total_de_nos(arvoreBin* raiz);
void percorrer_em_pre_ordem(arvoreBin* raiz);
void percorrer_em_ordem(arvoreBin* raiz);
void percorrer_em_pos_ordem(arvoreBin* raiz);
int insere_arvoreBinaria(arvoreBin* raiz, int valor);
int remove_arvoreBinaria(arvoreBin* raiz, int valor);
int consulta_arvoreBinaria(arvoreBin* raiz, int valor);