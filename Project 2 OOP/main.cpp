#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#include <actor.h>
#include <function.h>
#include <hour.h>
#include <movie.h>

const int iMOVIES = 11;
const int iACTORS = 22;

//function key

string getActorByID(actor arrAct[], int iID){
  for (int i = 0; i < iACTORS; i++){
    if (arrAct[i].getID() == iID){
      return arrAct[i].getName();
    }
  }
  return "Unknown actor";
}

void displayActors(movie arrMov[], actor arrAct[],int iNumber){
  for (int i = 0; i < iMOVIES; i++){
    if (arrMov[i].getMovieNumber() == iNumber){
      for (int j = 0; j < arrMov[i].getActorAmount(); j++){
        cout << getActorByID(arrAct, arrMov[i].getActorList(j)) << endl;
      }
     // arrAct[i].printActorInfo();
    }
  }
}

string getMovieGenreByNumber(movie arrMov[], int iNumber){
  for (int i = 0; i < iMOVIES; i++){
    if (arrMov[i].getMovieNumber() == iNumber){
      return arrMov[i].getGenre();
    }
  }
  return "No genre specified";
}

int getMovieLengthByNumber(movie arrMov[], int iNumber){
  for (int i = 0; i < iMOVIES; i++){
    if (arrMov[i].getMovieNumber() == iNumber){
      return arrMov[i].getLength();
    }
  }
  return 0;
}

string getMovieTitleByNumber(movie arrMov[], int iNumber){
  for (int i = 0; i < iMOVIES; i++){
    if (arrMov[i].getMovieNumber() == iNumber){
      return arrMov[i].getTitle();
    }
  }
  return ("Pelicula desconocida.");
}

void showFunctionsByHour(movie arrMov[], function arrFunc[], int iCont){
  int iHora = -1, iMin = -1, iMovieNumber;
  string sTitle;
  bool bExist = false;

  while (iHora < 0 || iHora >= 23 || iMin < 0 || iMin > 59){
    cout << "Hora deseada (hh mm): ";
    cin >> iHora >> iMin;
  }

  int iFunctionHour, iFunctionMin;

  for (int i = 0; i < iCont; i++){
    iFunctionHour = arrFunc[i].getHour().getHour();
    iFunctionMin = arrFunc[i].getHour().getMinute();
    if (iHora == iFunctionHour && iMin == iFunctionMin){
      bExist = true;
      cout << "\n*********************";
      iMovieNumber = arrFunc[i].getMovieNumber();
      cout << "\nTitle: " << getMovieTitleByNumber(arrMov, iMovieNumber) << "\nRoom: " << arrFunc[i].getRoom();
    }
  }
  if (bExist){
    cout << "\n*********************\n";
  }
}

//Debes validar que la clave de la función exista y mostrar en la pantalla el número de sala, el título de la película, la hora a la que se presenta, la duración, el género y los nombres de los actores que participan en la película.
void showFunctionsByKey(movie arrMov[], function arrFunc[],actor arrAct[], int iCont){
  int iIndex;
  string sKey;
  bool bExist = false;
  while (!bExist){
    cout << "Input function key: ";
    cin >> sKey;
    for (int i = 0; i < iCont && !bExist; i++){
      if (arrFunc[i].getFunctionID() == sKey){
      bExist = true;
      iIndex = i;
     }
    }
   }
  cout << "\n***********************************\n";   
  for (int iMovieNumber; iIndex < iCont; iIndex++){
    if (arrFunc[iIndex].getFunctionID() == sKey){
      cout << "Room: " << arrFunc[iIndex].getRoom();
      iMovieNumber = arrFunc[iIndex].getMovieNumber();
      cout << "\nTitle: " << getMovieTitleByNumber(arrMov, iMovieNumber);
      cout << "\nTime: " << arrFunc[iIndex].getHour().getHour() << ":" << arrFunc[iIndex].getHour().getMinute();
      cout << "\nLength: " << getMovieLengthByNumber(arrMov, iMovieNumber) << " mins";
      cout << "\nGenre: " << getMovieGenreByNumber(arrMov, iMovieNumber);
      cout << "\nActors:\n";
      displayActors(arrMov, arrAct,iMovieNumber);
      cout << "***********************************\n";      
    }
  }
}

void showAllFunctions(movie arrMov[], function arrFunc[], int iFunctions){
  cout << "********************************\n";
  for (int i = 0, iHora, iMin, iNumber; i < iFunctions; i++){
    cout << "Function key: " << arrFunc[i].getFunctionID();
    iNumber = arrFunc[i].getMovieNumber();
    cout << "\nMovie name: " << getMovieTitleByNumber(arrMov, iNumber);
    cout << "\nRoom: " << arrFunc[i].getRoom();
    iHora = arrFunc[i].getHour().getHour();
    iMin = arrFunc[i].getHour().getMinute();
    cout << "\nHora: " << iHora << ":" << iMin << endl << "********************************\n";
  }
}

char fillFunctionArray(function arrFunc[], movie arrMov[], int &iCont){
  char cOption = ' ';
  hour *hHour;
  hHour = new hour();
  string sMovieKey;
  bool bMovieNumExist = false;
  int iMovieNum, iMovieRoom, iHour, iMin, iFunctions = 0;
  hour hMovieHour;
  while (cOption != 'N' && iFunctions < 20){
  cout << "\nAdd a function? (y/n): ";
  cin >> cOption;
  cOption = toupper(cOption);
  if (cOption == 'N'){
    cout << "\nWelcome:\n";
  } else if (cOption == 'Y'){
    cout << "Function key: ";
    cin.ignore();
    getline(cin, sMovieKey);
    while (!bMovieNumExist){
    cout << "Movie number: ";
    cin >> iMovieNum;
    for (int i = 0; i < iMOVIES && !bMovieNumExist; i++){
      if (arrMov[i].getMovieNumber() == iMovieNum){
        bMovieNumExist = true;
      }
    }
    if (!bMovieNumExist){
      cout << "Movie number does not exist.\n";
    }
    }
    bMovieNumExist = false;
    while (iHour < 0 || iHour >= 23 || iMin < 0 || iMin > 59){
    cout << "Function time:\nHour: ";
    cin >> iHour;
    cout << "Min: ";
    cin >> iMin;
    }
    cout << "Movie room: ";
    cin >> iMovieRoom;
    arrFunc[iCont].setFunctionID(sMovieKey);
    arrFunc[iCont].setMovieNumber(iMovieNum);
    hHour->setHour(iHour);
    hHour->setMinute(iMin);
    arrFunc[iCont].setHour(*hHour);
    arrFunc[iCont].setRoom(iMovieRoom);
    iCont++;
    iFunctions++;
    iHour = -1;
    iMin = -1;  
  }
  }

  return cOption;
}

void showMovieByActor(movie arrMov[], actor arrAct[]){
  int iID;
  string sName = "Unknown actor";
  while (sName == "Unknown actor"){
  cout << "Enter the actor ID: ";
  cin >> iID;
  sName = getActorByID(arrAct, iID);
  }
  sName = getActorByID(arrAct, iID);
  cout << endl << sName << " movie appearances:";
  cout << "\n\n**********************";
  if (sName == "Unknown actor"){
    cout << "The actor is not recognized.";
  } else {
    for (int i = 0; i < iMOVIES; i++){
      for (int j = 0; j < arrMov[i].getActorAmount(); j++){
        if (iID == arrMov[i].getActorList(j)){
          cout << "\nMovie: " << arrMov[i].getTitle();
          cout << "\nYear: " << arrMov[i].getYear();
          cout << "\n**********************";
        }
      }
    }
  }
}

//Debe mostrar el título, año, duración, género y la lista de los nombres de los actores que participan en una película.
void showAllMovies(movie arrMov[], actor arrAct[]){

  cout << "Movie list:\n";
  cout << "\n*******************************************";

  for (int i = 0; i < iMOVIES; i++){
    int iID;
    cout << "\nTitle: " << arrMov[i].getTitle() << "\nYear: " << arrMov[i].getYear() << "\nLength: " << arrMov[i].getLength() << " mins" << "\nGenre: " << arrMov[i].getGenre() << "\nActor List:";
    for (int j = 0; j < arrMov[i].getActorAmount(); j++){
      iID = arrMov[i].getActorList(j);
      cout << endl << getActorByID(arrAct, iID);
    }
    cout << "\n******************************************";
  }
}

void showAllActors(actor arrAct[]){

  cout << "Actor list:\n";

  for (int i = 0; i < 21; i++){
    //cout << " \033[1;20mID: \033[10m" << arrAct[i].getID();
    cout << "ID: " << arrAct[i].getID();
    //cout << " \033[1;32mActor:\033[10m" << arrAct[i].getName() << endl;
    cout << "\t | \tName:" << arrAct[i].getName() << endl;
  }
}

char showMenu(){
  char cOption;
  cout << "\nA. Show actor list\nB. Show all movies\nC. Show all available functions\nD. Show functions by hour\nE. Show functions by key\nF. Show movie by actor\nG. End\n";
  cout << "Enter the option you want: ";
  //cout << "\033[36;01mEnter the option you want: \033[10m";
  cin >> cOption;
  return cOption;
}

void fillActorArray(actor arrAct[]){
  int iActorID, iCont = 0;
  string sActorName;

  ifstream inActorFile("actors.txt");

  if (inActorFile.is_open()){
    while (!inActorFile.eof()){
      inActorFile >> iActorID;
      getline(inActorFile, sActorName);
      arrAct[iCont].setID(iActorID);
      arrAct[iCont].setName(sActorName);
      iCont++;
    }
  } else {
    cout << "File not open.\n";
  }
  
  inActorFile.close();

}

void fillMovieArray(movie arrMov[]){
  int iMovieNumber, iYear, iLength, iActorAmount, iActorID, iCont = 0;
  string sGenre, sTitle;
  bool bActorAdded;
  bool bErrors = false;

  ifstream inMovieFile("movies.txt");

  if (inMovieFile.is_open()){
    while(!inMovieFile.eof()){
    inMovieFile >> iMovieNumber >> iYear >> iLength >> sGenre >> iActorAmount;
    arrMov[iCont].setMovieNumber(iMovieNumber);
    arrMov[iCont].setYear(iYear);
    arrMov[iCont].setLength(iLength);
    arrMov[iCont].setGenre(sGenre);
    
    for (int i = 0; i < iActorAmount; i++){
      inMovieFile >> iActorID;
      bActorAdded = arrMov[iCont].addActor(iActorID);
      if (bActorAdded){
        //cout << "**";
        cout << "\033[36;32m**\033[0m";
      } else {
        bErrors = 1;
      }
    }

    getline(inMovieFile, sTitle);

    arrMov[iCont].setTitle(sTitle);

    iCont++;
    }
      if (bErrors){
      cout << "\nThere were errors adding actors.\n";
    } else {
      cout << "\nAll actors added successfully.\n";
    }
    
  } else {
    cout << "File not open.";
  }

  inMovieFile.close();
}

int main() {
  actor arrAct[iACTORS];
  function arrFunc[20];
  movie arrMov[iMOVIES];
  char cOption = ' ';
  int iContFunctions = 0;

  fillActorArray(arrAct);
  fillMovieArray(arrMov);

  while(cOption!='N'){
    cOption = fillFunctionArray(arrFunc, arrMov,iContFunctions);
  }

  while(cOption!='G'){
    cOption = toupper(showMenu());
    switch (cOption){
    case 'A':
    showAllActors(arrAct);
    break;
    case 'B':
    showAllMovies(arrMov, arrAct);
    break;
    case 'C':
    showAllFunctions(arrMov, arrFunc, iContFunctions);
    break;
    case 'D':
    showFunctionsByHour(arrMov, arrFunc, iContFunctions);
    break;
    case 'E':
    showFunctionsByKey(arrMov, arrFunc, arrAct,iContFunctions);
    break;
    case 'F':
    showMovieByActor(arrMov, arrAct);
    break;
    case 'G':
    //cout << "Thanks :D.";
    cout << "\033[34;01mThanks :D\033[0m";
    break;
    default:
    cout << "Invalid option.\n";
    break;
    }
  }
  return 0;
}