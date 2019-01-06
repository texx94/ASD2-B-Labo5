/*
 * File: FileIO.cpp
 * ASD 2 - Labo 5 - Mini projet
 * Authors: Loris Gilliand, Mateo Tutic, Luc Wachter
 * Created on 04.01.2019
 *
 * Description: Définition de fonctions pour la lecture et l'écriture de fichiers.
 */

#include "FileIO.h"

#include <algorithm>

using namespace std;

// Prédicat pour différencier les caractères appartenant à l'alphabet et
// l'apostrophe de tous les autres caractères
bool isNotAlphabeticOrApostrophe(char c) {
   // Code ASCII des lettres minuscules : 97-122
   // Code ASCII de l'apostrophe : 39
   if (((int) c >= 97 && (int) c <= 122) || (int) c == 39)
      return false;
   else
      return true;
}

// Permet de nettoyer une string en la convertissant en minuscules et en lui
// retirant les caractères non autorisés (voir isNotAlphabetic)
string sanitize(string word) {
   // On convertit le mot en minuscules
   for (size_t i = 0; i < word.length(); ++i) {
       word[i] = (char) tolower(word[i]);
   }

   // On retire tous les caractères qui ne sont pas alphabétiques ou un apostrophe
   word.erase(remove_if(word.begin(), word.end(), isNotAlphabeticOrApostrophe), word.end());

   // On retire les apostrophes avant et après le mot
   if (!word.empty() and word.at(0) == '\'')
      word.erase(0, 1);
   if (!word.empty() and word.at(word.length() - 1) == '\'')
      word.erase(word.length() - 1, 1);

   return word;
}