#include "graph.hpp"
#include "edges.hpp"


Graph::Graph(int k) {
   /* Inicializa um grafo com parâmetro k */
   minimunNumOfLetters = k;
   vertices = 0;
   edges = 0;
}

int Graph::insert(string word) {
   vector<pair<int, string>> aux;

   if ((int) word.length() < minimunNumOfLetters)
      return -1;
   
   for (int v = 0; v < vertices; v++) {
      // aux.push_back(make_pair(0, graph[v][0].second));
      if (graph[v][0].second == word)
         return -1;
   }
   
   
   aux.push_back(make_pair(0, word));

   for (int v = 0; v < vertices; v++) {
      string auxWord = graph[v].at(0).second;
      if (swappingLetter(word, auxWord) || replacingLetter(word, auxWord) || removingOrInsertingLetter(word, auxWord)) {
         graph[v].push_back(make_pair(1, word));
         aux.push_back(make_pair(1, auxWord));
         edges++;
      }
   }

   graph.push_back(aux);
   vertices++;

   return edges;
   /* Insere a palavra e retorna o número de arestas adicionados ao grafo,
   retorna -1 se a palavra já está no grafo ou tem tamanho menor que k*/
}

int Graph::getVertices(){
   return vertices;
}

int Graph::getEdges(){
   return edges;
}

int Graph::components(){
   /* Retorna o número de componentes do grafo */
}

bool Graph::conexo(){
   for (int v = 0; v < vertices; v++)
      for (int j = 0; j < vertices; j++)
         if (graph[v][j].first == 0)
            return false;
   
   return true;
}

int Graph::tamComp(string palavra){
   /* Retorna o tamanha da componente conexa onde está a palavra
   ou -1 caso ela não se encontre no grafo */
}

int Graph::dist(string a, string b){
   /* Retorna a menor distância entre as palavras a e b ou -1
   caso elas estejam desconexas ou não estejam no grafo */
}

bool Graph::emCiclo(string a){
   /* Retorna verdadeiro casa a palavra esteja em algum ciclo,
   falso caso contrário */
}

bool Graph::emCiclo(string a, string b){
   /* Retorna verdadeiro casa exista um ciclo que contenha ambas as palavras,
   falso caso contrário */
}

void Graph::print() {
   cout << endl << "Grafo: " << endl;
   // for (int v = 0; v < vertices; v++) {
   //    cout << graph[v].at(0).second << endl;

   //    for (int w = 1; w < (int) graph[v].size(); w++)
   //       cout << "Vertice " << graph[v].at(w).first << ": " << graph[v].at(w).second << endl;
   // }
   for (unsigned int i = 0; i < graph.size(); i++) {
      for (unsigned int j = 0; j < graph[i].size(); j++)
         cout << " " << graph[i][j].second << " " << graph[i][j].first;
      cout << endl;
   }
   cout << endl << endl;
}