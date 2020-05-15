#ifndef _EDGES_HPP
#define _EDGES_HPP

#include "graph.hpp"

int makeEdges(Graph * graph, int edges, int vertices, string newWord);
int swappingLetter(string newWord, string aux);
int replacingLetter(string newWord, string aux);
int removingOrInsertingLetter(string newWord, string aux);

#endif