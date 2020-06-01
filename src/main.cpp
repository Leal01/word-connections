#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "graph.hpp"
#include "edges.hpp"

int main(int argc, char * argv[]) {
   int numEdgesAdded = 0, testInput = 1;
   string word1, word2;
   Graph * graph;
   fstream textFile;
   string word;
   int size, size2, dist;

   if (argc < 3) {
      cout << "./ep2 [número minimo de letras] [arquivo de texto]\n";
      exit(EXIT_FAILURE);
   }

   textFile.open(argv[2]);

   if (!textFile.is_open()) {
      cout << "Erro ao abrir o arquivo\n";
      exit(EXIT_FAILURE);
   }

   graph = new Graph(strtol(argv[1], nullptr, 10));

   while (textFile >> word)
      numEdgesAdded += graph->insert(word);

   graph->print();
   textFile.close();

   while (testInput != 0) {   
      cout << "Testes disponíveis: \n";
      cout << "Digite 1: medidas\n";
      cout << "Digite 2: conexidade\n";
      cout << "Digite 3: caminhos e ciclos\n";
      cout << "Digite 0: sair\n";
      cin >> testInput;
      switch (testInput) {
         case 1: 
            cout << endl;
            cout << "\nMedidas: \n";
            cout << "O grafo tem: " << graph->getVertices() << " vértices e " << graph->getEdges() << " arestas.\n";
            cout << "O grau médio do grafo é: " << graph->averageDegree() << ". " << endl;
            cout << endl;
            break;
         case 2:
            cout << endl;
            if (graph->isConnected())
               cout << "O grafo é conexo!\n";
            else
               cout << "O grafo não é conexo!\n";

            cout << "e tem " << graph->getComponents() << " componentes.\n\n";
            break;
         case 3:
            cout << endl;
            cout << "Digite duas palavras para checar se existe um caminho entre elas e outras caracteristicas de cada uma: ";
            cin >> word1 >> word2;
            cout << endl;

            dist = graph->distance(word1, word2);
            if (dist != -1)
               cout << "Existe caminho e a menor distancia é: " << dist << endl;
            else
               cout << "Não existe caminho entre as duas palavras.\n";
            
            cout << "Além disso, ";
            size = graph->componentSize(word1);

            if (size  != -1)
               cout << "a palavra " << word1 << " está numa componente de tamanho " << size << endl;
            else 
               cout << "a palavra " << word1 << " não se encontra em nenhuma componente.\n";
            
            cout << "E a palavra " << word2;

            size2 = graph->componentSize(word2);

            if (size2 != -1)
               cout << " está numa componente de tamanho " << size2 << endl;
            else 
               cout << " não se encontra em nenhuma componente.\n";

            cout << "Por ultimo: \n";
            if (graph->isWordInCycle(word1))
               cout << "A palavra " << word1 << " se encontra em um ciclo!\n";
            else
               cout << "A palavra " << word1 << " não se encontra em um ciclo!\n";
            
            cout << "Já a palavra " << word2;
            if (graph->isWordInCycle(word2))
               cout << " se encontra em um ciclo!\n";
            else
               cout << " não se encontra em um ciclo!\n";
            
            cout << "E elas ";
            if (graph->shareSameCycle(word1, word2))
               cout << "compartilham do mesmo ciclo\n";
            else
               cout << "estão em ciclos diferentes\n";
            
            cout << endl;
            break;
         default:
            testInput = 0;

      }
   }

   delete graph;
   return 0;
}