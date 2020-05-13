#include <iostream>
#include <fstream>
#include "graph.hpp"

int main(int argc, char * argv[]) {
   int numEdgesAdded, testInput = 1;
   Graph * graph;
   fstream texFile;
   string word;

   if (argc < 3) {
      cout << "./main [número minimo de letras] [arquivo de texto]\n";
      exit(EXIT_FAILURE);
   }

   textFile.open(argv[2]);

   if (!textFile.is_open()) {
      cout << "Erro ao abrir o arquivo\n";
      exit(EXIT_FAILURE);
   }

   graph = new Graph(stoi(argv[1]));

   else 
      while (textFile >> word)
         numEdgesAdded = graph->insert(word);
      
   textFile.close();
   while (testInput != 0) {
      graph->print();
   
      cout << "Testes disponíveis: \n";
      cout << "Digite 1: medidas\n";
      cout << "Digite 2: conexidade\n";
      cout << "Digite 3: caminhos e ciclos\n";
      cout << "Digite 0: sair\n";
      cin >> testInput;

      switch (testInput) {
         case 1:  break;
         case 2:  break;
         case 3:  break;
         default:
            testInput = 0;
            break;
      }
   }

   delete graph;
   return 0;
}