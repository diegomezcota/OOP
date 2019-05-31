#include <iostream>
#include <string>

using namespace std;

// Diego Gómez Cota
// Code the algorithm to get the ISBN code of a 9 digit number
// The ISBN code: https://en.wikipedia.org/wiki/International_Standard_Book_Number#ISBN-10_check_digits

int main(){
   int iResidue, iSum;
   string sNumber, sContinue="Y";
   do {
    if (sContinue == "Y"){
    iSum = 0;
    cout << "Enter 9 digit number: ";
    getline(cin, sNumber);
    if (sNumber.length() != 9) {
        cout << "Incorrect term.\n";
    } else {
            for (int i = 0; i < 9; i++){
                iSum += (int(sNumber[i]) - 48) * (i+1);
            }
            iResidue = iSum % 11;
            if (iResidue != 10){
                cout << "The ISBN code is " << sNumber << "-" << iResidue << endl;
            } else {
                cout << "The ISBN code is " << sNumber << "-X\n";
            }
        }
    }

        cout << "Continue?(Y/N): ";
        getline(cin, sContinue);

   } while (sContinue != "N");

    cout << "Bye!";

   return 0;
}
