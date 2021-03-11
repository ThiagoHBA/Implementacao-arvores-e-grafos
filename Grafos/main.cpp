#include <iostream>
#include "grafo.h"

using namespace std;

int main() {
  int eh_digrafo = 0;
  int ponto_de_partida = 0;
  int ponto_de_destino = 0;
  int i,ant[6],pai[6];
  float dist[6];

  Grafo *gr = cria_grafo(6, 6, 1);
  
  insere_aresta(gr, 0, 1, eh_digrafo, 6);
  insere_aresta(gr, 0, 2, eh_digrafo, 1);
  insere_aresta(gr, 0, 3, eh_digrafo, 5);
  insere_aresta(gr, 1, 2, eh_digrafo, 2);
  insere_aresta(gr, 1, 4, eh_digrafo, 3);
  insere_aresta(gr, 2, 3, eh_digrafo, 2);
  insere_aresta(gr, 2, 4, eh_digrafo, 6);
  insere_aresta(gr, 2, 5, eh_digrafo, 6);
  insere_aresta(gr, 3, 5, eh_digrafo, 3);
  insere_aresta(gr, 4, 5, eh_digrafo, 3);

  cout << "Insira o ponto de partida: ";
  cin >> ponto_de_partida;

  cout << "Insira o ponto de destino: ";
  cin  >> ponto_de_destino;

  busca_menor_caminho(gr, ponto_de_partida, ant, dist);
  cout << "Distância percorrida: " << dist[ponto_de_destino] << endl;

  libera_grafo(gr);
  return 0;
}