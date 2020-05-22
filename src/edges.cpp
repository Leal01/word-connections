#include "edges.hpp"

#include <vector>

vector<int> subtractWords(string newWord, string aux) ;

// Trocando letras de uma mesma palavra
bool swappingLetter(string newWord, string aux) {
   if (newWord.length() == aux.length()) {
      int differentLetters = 0;
      int pos1 = -1, pos2 = -1;
      vector<int> wordsSubtracted = subtractWords(newWord, aux);

      for (unsigned int i = 0; i < wordsSubtracted.size() && differentLetters <= 2; i++) {
         if (wordsSubtracted[i] != 0) {
            differentLetters++;

            if (differentLetters <= 2) {
               if (pos1 == -1)
                  pos1 = i;
               else
                  pos2 = i;
            }
         }
      }

      if (differentLetters == 2)
         if (newWord[pos1] == aux[pos2] && newWord[pos2] == aux[pos1])
            return true;

      return false;
   }

   return false;   
}

// Substituindo letras
bool replacingLetter(string newWord, string aux) {
   if (newWord.length() == aux.length()) {
      int differentLetters = 0;
      vector<int> wordsSubtracted = subtractWords(newWord, aux);

      for (unsigned int i = 0; i < wordsSubtracted.size(); i++) 
         if (wordsSubtracted[i] != 0)
            differentLetters++;
      
      if (differentLetters == 1)
         return true;
   }

   return false;
}

// Adicionando ou removendo uma letra
bool removingOrInsertingLetter(string newWord, string aux) {
   string bigger, smaller;
   int smallerIndex = 0;

   if (newWord.length() == aux.length() + 1) {
      bigger = newWord;
      smaller = aux;
   }

   else if (newWord.length() + 1 == aux.length()) {
      bigger = aux;
      smaller = newWord;
   }

   else
      return false;

   for (unsigned int i = 0; i < bigger.length(); i++)
      if (bigger[i] == smaller[smallerIndex])
         smallerIndex++;

   if (smallerIndex == (int) smaller.length())
      return true;
   
   return false;
}

vector<int> subtractWords(string newWord, string aux) {
   vector<int> wordsSubtracted;
   // strings have the same length
   for (unsigned int i = 0; i < aux.length(); i++) 
      wordsSubtracted.push_back(abs(newWord[i] - aux[i]));
   
   return wordsSubtracted;
}