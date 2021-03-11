#include <iostream>
#include "arvoreBinaria.h"

using namespace std;

struct NO{
  int info;
  struct NO* esquerda;
  struct NO* direita;
};

arvoreBin* cria_arvoreBinaria(){
  arvoreBin* raiz = (arvoreBin*) malloc(sizeof(arvoreBin));
  if(raiz != NULL){
    *raiz = NULL;
  }

  cout << "Criando árvore Binaria" << endl;
  return raiz;
}

void libera_arvoreBinaria(arvoreBin* raiz){
  if(raiz != NULL) return;
  libera_noArvoreBinaria(*raiz);
  free(raiz);
}

void libera_noArvoreBinaria(struct NO* no){
  if(no == NULL) return;
  libera_noArvoreBinaria(no -> esquerda);
  libera_noArvoreBinaria(no -> direita);
  free(no);
  no = NULL;
}

int arvoreEstaVazia(arvoreBin *raiz){
  if(raiz == NULL || *raiz == NULL) return 1;

  return 0;
}

int altura_arvoreBinaria(arvoreBin* raiz){
  if(raiz == NULL || *raiz == NULL) return 0;

  int alturaFilhoEsquerdo = altura_arvoreBinaria(&((*raiz) -> esquerda));
  int alturaFilhoDireito  = altura_arvoreBinaria(&((*raiz) -> direita));

  if(alturaFilhoEsquerdo > alturaFilhoDireito) return alturaFilhoEsquerdo + 1;
  else return alturaFilhoDireito + 1;
}

int total_de_nos(arvoreBin* raiz){
  if(raiz == NULL || *raiz == NULL) return 0;

  int nosEsquerda = altura_arvoreBinaria(&((*raiz) -> esquerda));
  int nosDireita  = altura_arvoreBinaria(&((*raiz) -> direita));

  return (nosEsquerda + nosDireita + 1);

}

void percorrer_em_pre_ordem(arvoreBin* raiz){
  if(raiz == NULL || *raiz == NULL) return;

  cout << (*raiz) -> info << endl;
  percorrer_em_pre_ordem(&((*raiz) -> esquerda));
  percorrer_em_pre_ordem(&((*raiz) -> direita));
}

void percorrer_em_ordem(arvoreBin* raiz){
  if(raiz == NULL || *raiz == NULL) return;  

  percorrer_em_ordem(&((*raiz) -> esquerda));
  cout << (*raiz) -> info << endl;
  percorrer_em_ordem(&((*raiz) -> direita));
}

void percorrer_em_pos_ordem(arvoreBin* raiz){
  if(raiz == NULL || *raiz == NULL) return;

  percorrer_em_pos_ordem(&((*raiz) -> esquerda));
  percorrer_em_pos_ordem(&((*raiz) -> direita));
  cout << (*raiz) -> info << endl;
}

int insere_arvoreBinaria(arvoreBin* raiz, int valor){
  if(raiz==NULL) return 0;
  struct NO* novo;
  novo = (struct NO*)malloc(sizeof(struct NO));

  if (novo==NULL)return 0;
  novo->info = valor;
  novo->direita = NULL;
  novo->esquerda = NULL;

  if (*raiz == NULL) *raiz = novo;

  else{
    struct NO* atual = *raiz;
    struct NO* ant = NULL;
    while (atual!=NULL){
      ant = atual;
      if (valor==atual->info){
        free (novo);
        return 0;
      }
      if (valor > atual -> info) atual = atual->direita;
      else atual = atual -> esquerda;
    }
    if(valor > ant -> info) ant -> direita = novo;
    else ant -> esquerda = novo;
  }
  return 1;
}

struct NO* remove_atual(struct NO* atual){
  struct NO *no1, *no2;
  if(atual->esquerda==NULL){
    no2 = atual -> direita;
    free(atual);
    return no2;
  }
  
  no1 = atual;
  no2 = atual -> esquerda;

  while(no2->direita != NULL){
    no1 = no2;
    no2 = no2 ->direita;
  }

  if(no1 != atual){
    no1 -> direita = no2->esquerda;
    no2->esquerda = atual -> esquerda;
  }

  no2 -> direita = atual -> direita;
  free(atual);
  return no2;
  
}

int remove_arvoreBinaria(arvoreBin* raiz, int valor){
  if(raiz == NULL) return 0;
  struct NO* ant = NULL;
  struct NO* atual = *raiz;
  while(atual!=NULL){
    if(valor==atual->info){
      if(atual==*raiz) *raiz=remove_atual(atual);
      else{
        if(ant->direita == atual)
          ant->direita = remove_atual(atual);
        else
          ant->esquerda = remove_atual(atual);
      }
      return 1;

    }
    ant = atual;
    if(valor>atual->info) atual = atual->direita;
    else atual = atual->esquerda;
  }

  return 0;
}

int consulta_arvoreBinaria(arvoreBin* raiz, int valor){
  if (raiz==NULL) return 0;
  struct NO* atual = *raiz;
  while(atual!=NULL){
    if(valor == atual -> info) return 1;
    if(valor > atual -> info) atual = atual->direita;
    else atual = atual->esquerda;
  }
  return 0;
}