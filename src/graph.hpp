#ifndef _GRAPH_HPP
#define _GRAPH_HPP

#include "edges.hpp"
#include <string>
#include <vector>
using namespace std;

//k definido como no enunciado será passado como argumento de linha de comando
class Graph {
   private:
      vector<vector<pair<int, string>>> graph;
      int minimunNumOfLetters;
      int vertices;
      int edges;

   public:
      Graph(int k);
      int insere(string word);
      int vertices();
      int arestas();
      int componentes();
      bool conexo();
      int tamComp(string palavra);
      int dist(string a, string b);
      bool emCiclo(string a);
      bool emCiclo(string a, string b);

}

#endif