#include "graph.hpp"

Graph(int k){
   /* Inicializa um grafo com parâmetro k */
   minimunNumOfLetters = k;
   vertices = 0;
   edges = 0;
}

int insere(string word) {
   vector<pair<int, string>> aux;
   
   if (word.length() < minimunNumOfLetters)
      return -1;
   
   for (int v = 0; v < vertices; v++)
      if (graph[v][0].second == word)
         return -1;

   graph[V][0].push_back(make_pair(0, word));
   graph[0][V].push_back(make_pair(0, word));
   vertices++;

   int newEdges = makeEdges(graph, edges, vertices);
   edges += newEdges;

   return edges;
   /* Insere a palavra e retorna o número de arestas adicionados ao grafo,
   retorna -1 se a palavra já está no grafo ou tem tamanho menor que k*/
}

int vertices(){
   return vertices;
}

int arestas(){
   return edges;
}

int componentes(){
   /* Retorna o número de componentes do grafo */
}

bool conexo(){
   for (int v = 0; v < vertices; v++)
      for (int j = 0; j < vertices; j++)
         if (graph[v][j].first == 0)
            return false;
   
   return true;
}

int tamComp(string palavra){
   /* Retorna o tamanha da componente conexa onde está a palavra
   ou -1 caso ela não se encontre no grafo */
}

int dist(string a, string b){
   /* Retorna a menor distância entre as palavras a e b ou -1
   caso elas estejam desconexas ou não estejam no grafo */
}

bool emCiclo(string a){
   /* Retorna verdadeiro casa a palavra esteja em algum ciclo,
   falso caso contrário */
}

bool emCiclo(string a, string b){
   /* Retorna verdadeiro casa exista um ciclo que contenha ambas as palavras,
   falso caso contrário */
}