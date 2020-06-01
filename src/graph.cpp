#include "graph.hpp"
#include "edges.hpp"


Graph::Graph(int k) {
   /* Inicializa um grafo com parâmetro k */
   minimunNumOfLetters = k;
   vertices = 0;
   edges = 0;

}


void Graph::addVertices(int currentIndex, string auxWord, int lastVertice, string newWord) {
  graph[currentIndex].push_back(make_pair(lastVertice, newWord));
  graph[lastVertice].push_back(make_pair(currentIndex, auxWord));
}

int Graph::insert(string word) {
   int newEdges = 0;

   if ((int) word.length() < minimunNumOfLetters)
      return -1;
   
   for (int v = 0; v < vertices; v++) {
      if (graph[v][0].second == word)
         return -1;
   }
   
   
   graph.push_back(vector<pair<int, string>>());
   graph[vertices].push_back(make_pair(vertices, word));

   for (int v = 0; v < vertices; v++) {
      string auxWord = graph[v].at(0).second;
      if (swappingLetter(word, auxWord) || replacingLetter(word, auxWord) || removingOrInsertingLetter(word, auxWord)) {
         addVertices(v, auxWord, vertices, word);
         newEdges++;
      }
   }

   edges += newEdges;
   vertices++;
   return newEdges;
   /* Insere a palavra e retorna o número de arestas adicionados ao grafo,
   retorna -1 se a palavra já está no grafo ou tem tamanho menor que k*/
}

int Graph::getVertices() {
   return vertices;
}

int Graph::getEdges() {
   return edges;
}

int Graph::getComponents() {
   vector<bool> visited(vertices, false);
   int numOfComponents = 0;

   for (int i = 0; i < vertices; i++) {
      if (!visited[i]) {
         numOfComponents++;
         dfsR(i, visited);
      }
   }

   return numOfComponents;
   /* Retorna o número de componentes do grafo */
}

bool Graph::isConnected(){
   vector<bool> visited(vertices, false);
   dfsR(0, visited);

   for (int i = 0; i < vertices; i++)
      if (!visited[i])
         return false;
   
   return true;
}

int Graph::componentSize(string word) {
   int wordIndex = wordFinder(word);

   if (wordIndex != -1) {
      vector<bool> visited(vertices, false);
      int size = 0;

      dfsR(wordIndex, visited);

      for (int i = 0; i < vertices; i++)
         if (visited[i])
            size++;

      return size;
   }

   return -1;
}

int Graph::distance(string a, string b) {
   int indexA = wordFinder(a);
   int indexB = wordFinder(b);

   if (indexA != -1 && indexB != -1) {
      vector<int> dist(vertices, -1);
      queue<int> queue;
      bool found = false;
   
      queue.push(indexA);
      dist[indexA] = 0;

      while (!queue.empty() && !found) {
         int u = queue.front();
         queue.pop();

         for (unsigned int i = 1; i < graph[u].size(); i++) {
            int w = graph[u][i].first;

            if (dist[w] == -1) {
               queue.push(w);
               dist[w] = dist[u] + 1;
            }

            if (w == indexB)
               found = true;
         }
      }

      return dist[indexB];

   }

   return -1;
   /* Retorna a menor distância entre as palavras a e b ou -1
   caso elas estejam desconexas ou não estejam no grafo */
}

int Graph::averageDegree() {
   int neighborsCount = 0;

   for (int i = 0; i < vertices; i++)
      neighborsCount += graph[i].size() - 1;

   return (neighborsCount/vertices);
}

bool Graph::isWordInCycle(string a) {
   int indexA = wordFinder(a);

   if (indexA != -1) {
      vector<int> color(vertices, 0);
      vector<int> previousNode(vertices, -1);
      vector<int> cycles(vertices, -1);
      int wordCycle = 0;

      checkCycles(0, -1, color, previousNode, cycles, wordCycle);

      if (cycles[indexA] != -1)
         return true;
   }

   return false;
   /* Retorna verdadeiro casa a palavra esteja em algum ciclo,
   falso caso contrário */
}

bool Graph::shareSameCycle(string a, string b) {
   int indexA = wordFinder(a);
   int indexB = wordFinder(b);

   if (indexA != -1 && indexB != -1) {
      vector<int> color(vertices, 0);
      vector<int> previousNode(vertices, -1);
      vector<int> cycles(vertices, -1);
      int wordCycle = 0;

      checkCycles(0, -1, color, previousNode, cycles, wordCycle);

      if (cycles[indexA] != -1 && (cycles[indexA] == cycles[indexB]))
         return true;
   }

   return false;
   /* Retorna verdadeiro casa exista um ciclo que contenha ambas as palavras,
   falso caso contrário */
}

void Graph::print() {
   cout << endl << "Grafo: " << endl;
   for (unsigned int i = 0; i < graph.size(); i++) {
      for (unsigned int j = 0; j < graph[i].size(); j++)
         cout << graph[i][j].second << " ";
      cout << endl;
   }
   cout << endl << endl;
}

int Graph::wordFinder(string word) {
   for (int i = 0; i < vertices; i++) 
      if (graph[i][0].second == word)
         return i;
   
   return -1;
}


void Graph::dfsR(int v, vector<bool> & visited) {
   visited[v] = true;

   for (unsigned int i = 1; i < graph[v].size(); i++) {
      int w = graph[v][i].first;
      if (!visited[w])
         dfsR(w, visited);
   }
}


void Graph::checkCycles(int u, int p, vector<int> & color, vector<int> & previousNode, vector<int> & cycles, int wordCycle) {
   // v is the current node
   // p is the previous node

   if (color[u] == 2)
      return;

   // detect cycle
   if (color[u] == 1) {
      int currentNode = p;
      wordCycle += 1;
      cycles[currentNode] = wordCycle;

      // back to the previous node one until you reach the node v
      while (currentNode != u) {
         currentNode = previousNode[currentNode];
         cycles[currentNode] = wordCycle;
      }

      return;
   }

   previousNode[u] = p;

   color[u] = 1;

   for (int v = 1; v < (int) graph[u].size(); v++) {
      int w = graph[u][v].first;

      if (w == previousNode[u])
         continue;

      checkCycles(w, u, color, previousNode, cycles, wordCycle);
   }

   color[u] = 2;
}
