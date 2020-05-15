#include "edges.hpp"

int makeEdges(Graph * graph, int edges, int vertices, string newWord) {
   int newEdges = 0;

   for (int v = 0; v < vertices; v++) {
      for (int u = v + 1; u < graph[v].size(); u++) {
         string aux = graph[v][u].second;

         if (swappingLetter(newWord, aux) || replacingLetter(newWord, aux) || removingOrInsertingLetter(newWord, aux)) {
            graph[v][u].first = 1;
            graph[u][v].first = 1;
            newEdges++;
         }
      }
   }
   return newEdges;
}

// Trocando letras de uma mesma palavra
int swappingLetter(string newWord, string aux) {}
   string reset = aux;
   char aux2;

   for (int i = 0; i < aux.length(); i++) {
      for (int j = i+1; j < aux.length(); j++) {
         aux2 = aux[i];
         aux[i] = aux[j];
         aux[j] = aux2;

         if (aux == newWord)  
            return 1;

         aux = reset; 
      }
   }

   return 0;   
}

// Substituindo letras
int replacingLetter(string newWord, string aux) {
   string reset = aux; 
   for (int i = 0; i < aux.length(); i++) {
      aux = reset;
      aux[i] = 'a';
      for (int j = 0; j < 26; j++) {
         if (aux == newWord) 
            return 1;
         
         aux[i] = aux[i] + 1;
      }
   }

   return 0;
}

// Adicionando ou removendo uma letra
int removingOrInsertingLetter(string newWord, string aux) {
   string reset = aux;
   
   for (int i = 0; i < aux.length(); i++) {
      aux.erase(aux.begin() + i);
      if (aux == newWord)
         return 1;
      aux = reset
   }

   aux.push_back('a');
   for (int i = aux.length() - 1; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
         if (aux == newWord) 
            return 1;
         
         aux[i] = aux[i] + 1;
      }
      aux[i] = 'a';
      char aux2 = aux[i-1];
      aux[i-1] = aux[i];
      aux[i] = aux2;
   }
}