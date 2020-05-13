#include "edges.hpp"

int makeEdges(Graph * graph, int edges, int vertices) {
   int newEdges = 0;
   newEdges += swappingLetters(graph, edges, vertices);
   newEdges += replacingLetters(graph, edges, vertices);
   newEdges += removingOrInsertingLetters(graph, edges, vertices);
   
   return newEdges/2;
}
int swappingLetters(Graph * graph, int edges, int vertices);
int replacingLetters(Graph * graph, int edges, int vertices);
int removingOrInsertingLetters(Graph * graph, int edges, int vertices);