#ifndef _GRAPH_HPP
#define _GRAPH_HPP

#include <vector>
#include <iostream>
#include <string>
#include <queue>
using namespace std;


//k definido como no enunciado será passado como argumento de linha de comando
class Graph {
   private:
      vector<vector<pair<int, string>>> graph;
      int minimunNumOfLetters;
      int vertices;
      int edges;
      int wordFinder(string word);
      void dfsR(int v, vector<bool> & visited);
      void checkCycles(int u, int p, vector<int> & color, vector<int> & previousNode, vector<int> & cycles, int wordCycle);
      void addVertices(int currentIndex, string auxWord, int lastVertice, string newWord);
      
   public:
      Graph(int k);
      int insert(string word);
      int getVertices();
      int getEdges();
      int getComponents();
      bool isConnected();
      int componentSize(string palavra);
      int distance(string a, string b);
      bool isWordInCycle(string a);
      bool shareSameCycle(string a, string b);
      int averageDegree();
      void print();
      
};

#endif