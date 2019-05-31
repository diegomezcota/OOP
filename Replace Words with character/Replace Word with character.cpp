#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){

    string sPhrase, sWord;
    int iIndex;
    ifstream inFile("Phrases.txt");
    ofstream outFile("Output.txt");
   if (inFile.is_open()) // If the file can be open.
    {
      cout << "Enter the word you want to replace: \n";
    getline(cin, sWord);
    while (!inFile.eof())
    {
      getline(inFile, sPhrase);
        if (sPhrase != "") {
        for (int i = 0; i < sPhrase.length(); i++){
        iIndex = sPhrase.find(sWord);
         if (iIndex>=0){
        sPhrase.erase(idx, sWord.length()-1);
        sPhrase[idx] = '*';
    }
}
    archSal << sPhrase << endl;
    cout << sPhrase << endl;
        }
    }

    inFile.close();
    }
    else cout << "File not opened." << endl;
    outFile.close();
    return 0;
}
