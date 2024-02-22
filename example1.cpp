#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string translateLine(string readLine);

string translateWord(string readWord);

bool isVowel(char letter);

int main(){

  string filename, readLine;
  cout << "Enter a filename to translate to Pig-Latin: ";
  cin >> filename;

  ifstream readEnglish;
  readEnglish.open(filename);

  ofstream writePigLatin;
  writePigLatin.open("PL_" + filename);

    while(getline(readEnglish, readLine)){

      writePigLatin << translateLine(readLine);
      writePigLatin << '\n';
    }

    readEnglish.close();
    writePigLatin.close();

    cout << "Translation Complete.\nName of translated file is: PL_" << filename << endl;
    cout << "              Press any key to exit...";

    cin.get();
    cin.get();
  return 0;
}

string translateLine(string readLine){

  string readWord, returnLine;

  for(int i = 0; i < readLine.length(); i++){//For every character within the line

    if (readLine[i] != ' ' && i + 1 != readLine.length()){

      readWord += readLine[i];
    }
    else if (readLine[i] == ' '){//If space

      returnLine += translateWord(readWord);
      returnLine += " ";
      readWord = "";
    }
    else if (i + 1 == readLine.length()){//If end of line

      returnLine += translateWord(readWord);
    }
  }
  return returnLine;
}

string translateWord(string readWord){

    string pigLatinWord;

  if (isVowel(readWord[0])){//Starts with vowel

    pigLatinWord += readWord;
    pigLatinWord += "hay";
  }
  else{//Starts with consonant

    int index = 0;
    string consonant;

    while(!isVowel(readWord[index])){

      consonant += readWord[index];
      index++;
    }

    for (int i = index; i < readWord.length(); i++){

      pigLatinWord += readWord[i];
    }

    pigLatinWord += consonant;
    pigLatinWord += "ay";
  }
  return pigLatinWord;
}

bool isVowel(char letter){

  char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
  bool rtn = false; 

  for(int i = 0; i < 6; i++){

    if (letter == vowels[i]){

      rtn = true;
    }
  }
  return rtn;
}
