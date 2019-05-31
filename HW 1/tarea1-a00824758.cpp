// Diego Gómez Cota
// A00824758
// HW 1
#include <iostream>
#include <string>
using namespace std;
/*
842053211
The ISBN is 842053211-8
032130332
The ISBN is 032130332-6
043935806
The ISBN is 043935806-X
*/
int main(){
    //Variable that keeps the mod
   int iMod;
   //One variable for reading the 9 digit number and the other for keep the code running
   string sNum, sContinue="S";
   // Repeating cycle while sContinue is different from 'N'
   do {
       // Execute if wanted
     if (sContinue == "S"){
       // Variable that stores the sum
       int iSum = 0;
       // Read number
            cout << "Enter the 9 digit number: ";
            getline(cin, sNum);
       // Verify the length is correct
            if (sNum.length() != 9) {
            cout << "Invalid term.\n";
            }
            else {
       // Do the sum with the ASCII values - 48
                for (int i = 0; i < 9; i++){
                iSum += (int(sNum[i]) - 48) * (i+1);
                }
       // Get the mod
                iMod = iSuma % 11;
       // Show mod
                if (iMod != 10){
                cout << "The ISBN is " << sNum << "-" << iMod << endl;
                }
                else {
                    cout << "The ISBN is " << sNum << "-X\n";
                }
             }
    }
   // Update variable sContinue
    cout << "Continue?(Y/N): ";
    getline(cin, sSeguir);
   } while (sSeguir != "N");
   return 0;
}
