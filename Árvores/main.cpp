#include "arvoreBinaria.h"
#include <iostream>

using namespace std;

int main(){
  arvoreBin* raiz = cria_arvoreBinaria();
  int inputUsuario;
  int numAtual;

  cout << "Digite a quantidades de números a serem inseridos na árvore: ";
  cin >> inputUsuario;

  for(int i = 0; i<inputUsuario ; i++){
    cout << "Digite o número " << i+1 << ": ";
    cin >> numAtual;
    insere_arvoreBinaria(raiz, numAtual);
  }

  //15, 8, 4, 10, 9, 11 , 18, 20, 19

  if(!arvoreEstaVazia(raiz)){
    cout << "Percorrendo em pré ordem: " << endl;
    percorrer_em_pre_ordem(raiz);
    cout << "Percorrendo em ordem: " << endl;
    percorrer_em_ordem(raiz);
    cout << "Percorrendo em pos ordem: " << endl;
    percorrer_em_pos_ordem(raiz);
    cout << endl;
  }

  cout << "Altura da árvore: " << altura_arvoreBinaria(raiz) << endl;

  return 0;
}
