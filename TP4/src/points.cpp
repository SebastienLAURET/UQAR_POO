#include <string>
#include <map>

namespace scrabble
 {
 // fonction de score à la C++
 // prenant avantage des maps
 //
 // (garde-fou implicite car si on
 // passe une lettre invalide à la
 // fonction, elle vaut simplement 0)
 //

 int score(const std::string & mot)
  {
   static std::map<char,int>
    letter_scores
    { {'a',1}, {'b',3}, {'c',3}, {'d',2}, {'e',1}, {'f',4},
      {'g',2}, {'h',4}, {'i',1}, {'j',8}, {'k',10}, {'l',1}, 
      {'m',2}, {'n',1}, {'o',1}, {'p',3}, {'q',8},  {'r',1},
      {'s',1}, {'t',1}, {'u',1}, {'v',4}, 
      {'w',10}, {'x',10}, {'y',10}, {'z',10}
    };

   int s=0;
   for (char l : mot)
    s+=letter_scores[l];
   
   return s;
  }



 }
