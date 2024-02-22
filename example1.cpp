#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){

  string filename;
  cout << "Enter a filename to translate to Pig-Latin: ";
  cin >> filename;

  ifstream readEnglish;
  readEnglish.open(filename);

  ofstream writePigLatin;
  writePigLatin.open("PL_" + filename);

    
  return 0;
}
