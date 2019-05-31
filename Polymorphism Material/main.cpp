#include <iostream>

using namespace std;

#include <lecture.h>
#include <book.h>
#include <eTutorial.h>

int main() {

  lecture *lecturesArr[100];
  string sTitle, sAuthor, sURL, sUpdate, sEditorial;
  char cOption = ' ', cMaterial = ' ';
  int iCont = 0, iPageAmount;

  while (cOption != 'N'){
    cout << "Add new lecture? (y/n): ";
    cin >> cOption;
    cOption = toupper(cOption);
    if (cOption == 'Y'){
        cout << "Book or eTutorial (b/e): ";
        cin >> cMaterial;
        cMaterial = toupper(cMaterial);
        while (cMaterial != 'B' && cMaterial != 'E'){
          cout << "Book or eTutorial (b/e): ";
          cin >> cMaterial;
          cMaterial = toupper(cMaterial);
        }
          if (cMaterial == 'B'){
              cout << "Title: ";
              cin.ignore();
              getline(cin, sTitle);
              cout << "Author: ";
              getline(cin, sAuthor);
              cout << "Editorial: ";
              getline(cin, sEditorial);
              cout << "Page Amount: ";
              cin >> iPageAmount;
              lecturesArr[iCont++] = new book(sTitle, sAuthor, sEditorial, iPageAmount);
              //lecturesArr[iCont++] = &b;
          } else if (cMaterial == 'E'){
              cout << "Title: ";
              cin.ignore();
              getline(cin, sTitle);
              cout << "Author: ";
              getline(cin, sAuthor);
              cout << "URL: ";
              getline(cin, sURL);
              cout << "Last Update: ";
              getline(cin, sUpdate);
              lecturesArr[iCont] = new eTutorial(sTitle, sAuthor, sURL, sUpdate);
              //lecturesArr[iCont]->show();
              iCont++;
          }
    }
  }

  cout << "La bibliografía utilizada para realizar la investigación es:\n\n";

  for (int i=0; i < iCont; i++){
    lecturesArr[i]->show();
  }

  cout << "*************";

return 0;
}