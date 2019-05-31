#include <iostream>
#include <fstream>
#include <string>
#include <reservation.h>
#include <hour.h>
#include <service.h>
#include <device.h>
#include <court.h>

using namespace std;

void fillServiceArray(service *arrServ[], int &iContServ){
  string sKey, sDescription;
  int iMaxTime, iMaxPeople;
  char cType, cInstructor;
  double dCost;
  bool bInstructor;
   ifstream inFile("Services.txt");
   if (inFile.is_open()){
     while(!inFile.eof()){
       inFile >> sKey >> iMaxTime >> cType;
       if (cType == 'C' || cType == 'B' || cType == 'E'){
         inFile >> dCost >> cInstructor;
         if (cInstructor == 'F'){
           bInstructor = false;
         } else {
           bInstructor = true;
         }
         getline(inFile, sDescription);
         arrServ[iContServ++] = new device(sKey, iMaxTime, cType, dCost, bInstructor, sDescription);
       } else if (cType == 'T' || cType == 'F' || cType == 'V'){
         inFile >> dCost >> iMaxPeople;
         getline(inFile, sDescription);
         arrServ[iContServ++] = new court(sKey, iMaxTime, cType, dCost, iMaxPeople, sDescription);
       }
     }
   } else {
     cout << "Error loading services.\n";
   }
    inFile.close();
}

void fillReservArray(reservation arrReserv[], int &iContReserv){
  string sServiceID;
  hour hHour;
  int iLength, iClientID;

  ifstream inFile("Reservations.txt");

  if (inFile.is_open()){
    while (!inFile.eof()){
      inFile >> sServiceID >> hHour >> iLength >> iClientID;
      reservation rReserv(sServiceID, iClientID, hHour, iLength);
      arrReserv[iContReserv++] = rReserv;
    }
  } else {
    cout << "Error loading reservations.\n";
  }

}

void consultServices(service *arrServ[], int iContServ){
  for (int i = 0; i < iContServ; i++){
    cout << "\n▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
    arrServ[i]->show();
  }
    cout << "\n▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
}

void consultAllReservations(reservation arrReserv[], service *arrServ[], int &iContServ, int &iContReserv){
  for (int i = 0; i < iContReserv; i++){
    for (int j = 0; j < iContServ; j++){
      if (arrReserv[i].getServiceID() == arrServ[j]->getKey()){
        cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n";
        cout << "Service ID: " << arrReserv[i].getServiceID();
        arrServ[j]->show();
        cout << "\n";
        cout << "Client ID: " << arrReserv[i].getClientID() << endl;
        cout << "Time: " << arrReserv[i].getStartingHour() << endl;
        cout << "Ending time: " << arrReserv[i].calculateReservationEnd() << endl;
        cout << "Cost: $" << arrServ[j]->calculateCost(arrReserv[i].getLength()) << endl;
      }
    }
  }
  cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n";
}

void consultReservationsFromAService(reservation arrReserv[], service *arrServ[], int &iContReserv, int &iContServ){
  string sServiceID;
  bool bExist = false, bExistReserv = false;
  int iIndex;
  while (!bExist){
    cout << "Enter service ID: ";
    cin >> sServiceID;
    for (int i = 0; i < iContServ && !bExist; i++){
      if (sServiceID == arrServ[i]->getKey()){
        bExist = true;
        iIndex = i;
      }
    }
    if (!bExist){
      cout << "Incorrect ID.\n";
    }
  }

  cout << "\n▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
  arrServ[iIndex]->show();

  for (int i = 0, iCont = 0; i < iContReserv; i++){
    if (sServiceID == arrReserv[i].getServiceID()){
      iCont++;
      bExistReserv = true;
      cout << "\n▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n";
      cout << "Reservation " << iCont << endl;
      cout << "Starts at: " << arrReserv[i].getStartingHour() << endl;
      cout << "Ends at: " << arrReserv[i].calculateReservationEnd();
    }
  }
  if (!bExistReserv){
    cout << "\nThere's no reservations for this service yet.\n";
  }
  cout << "\n▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n";
}

void consultReservationsFromAnHour(reservation arrReserv[], service *arrServ[], int &iContServ, int &iContReserv){
  hour hReservation;
  bool bExistReservation = false;
  cout << "Enter the hour (hh mm): ";
  cin >> hReservation;

  if (cin.fail())
  {
     cout << "ERROR -- You did not enter as the format expected";
     // get rid of failure state
     cin.clear();
     cin.ignore();
  } else {
    cout << "\nReservated at " << hReservation;

    for (int i = 0; i < iContReserv; i++){
      if ((hReservation >= arrReserv[i].getStartingHour()) && (hReservation <= arrReserv[i].calculateReservationEnd())){
        bExistReservation = true;
        for (int j = 0; j < iContServ; j++){
          if (arrReserv[i].getServiceID() == arrServ[j]->getKey()){
            cout << "\n▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
            arrServ[j]->show();
            cout << "\nStarts at: " << arrReserv[i].getStartingHour() << endl;
            cout << "Ends at: " << arrReserv[i].calculateReservationEnd();
          }
        }
      }
    }

    if (!bExistReservation){
      cout << "\nThere are no reservations at this hour.";
    }
    cout << "\n▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n";
  }
}

void makeAReservation(reservation arrReserv[], service *arrServ[], int &iContReserv){
  int iClientID, iIndex, iReservationMinutes = 0;
  string sKey;
  char cOption = ' ', cOut = ' ';
  hour hReservation, hEndingReservation;
  bool bExist = false;
  bool bExit = false;
  bool bQuit = false;

  cout << "Enter client ID (numeric): ";
  cin >> iClientID;

  if (cin.fail()){
    cout << "ERROR -- You did not enter as the format expected\n";
    cin.clear();
    cin.ignore();
    while (cin.fail()){
      cin.clear();
      cin.ignore();
    }
  } else {
      //Validating key exists, asking until it does
      while (!bExist){
        cout << "Enter service key: ";
        cin >> sKey;
        for (int i = 0; i < service::iServices && !bExist; i++){
          if (arrServ[i]->getKey() == sKey){
            iIndex = i;
            bExist = true;
          }
        }
        if (!bExist){
          cout << "Try an existing one.\n";
        }
      }
      //Validating that the amount of time is possible
      while ((iReservationMinutes <= 0 || iReservationMinutes > arrServ[iIndex]->getMaximumTime()) && (!bExit)){
        cout << "Enter how much minutes you will reserve: ";
        cin >> iReservationMinutes;
        cOption = ' ';
        if (iReservationMinutes <= 0){
          cout << "Invalid amount of time.\n";
        }
        if (iReservationMinutes > arrServ[iIndex]->getMaximumTime()){
          while (cOption != 'N' && cOption != 'Y'){
            cout << "Time exceeds limits for reservations. Try less minutes? (y/n): ";
            cin >> cOption;
            cOption = toupper(cOption);
          }
          if (cOption == 'N'){
            bExit = true;
          }
        }
      }

      if (cOption == 'N'){
        cout << "Reservation cancelled.\n";
      } else {
        //Validating that service is available at the time needed
        while (!bQuit){
          cout << "Enter the hour (hh mm) for reservation: ";
          cin >> hReservation;
          hEndingReservation = hReservation + iReservationMinutes;
          bExit = false;
          cOut = ' ';
          for (int i = 0; i < iContReserv && !bExit; i++){
            hour hRsv = arrReserv[i].getStartingHour();
            hour hEnd = hRsv + arrReserv[i].getLength();
            if 
            //if hour is not correct
            (!(hReservation >= hEnd || hEndingReservation <= hRsv) && arrReserv[i].getServiceID() == sKey){
              bExit = true;
            }
          }
          if (!bExit){
            bQuit = true;
            //Test this, don't know if it works
            arrReserv[iContReserv].setClientID(iClientID);
            arrReserv[iContReserv].setLength(iReservationMinutes);
            arrReserv[iContReserv].setServiceID(sKey);
            arrReserv[iContReserv].setStartingHour(hReservation);
            iContReserv++;
            cout << "Reservation made, the cost is $" << arrServ[iIndex]->calculateCost(iReservationMinutes);
          } else { 
            while (cOut != 'Y' && cOut != 'N'){
              cout << "The hour is occupied. Try another one? (y/n): ";
              cin >> cOut;
              cOut = toupper(cOut);
            }
            if (cOut == 'N'){
              bQuit = true;
              cout << "Reservation cancelled.\n";
            }
          }
        }
      }
  }
}

void chooseOption(char &cOption, service *arrServ[], reservation arrReserv[], int &iContServ, int &iContReserv){
  cout << "\n*********************************";
  cout << "\nA. Consult service list.\nB. Consult reservations list.\n";
  cout << "C. Consult reservations from a service.\nD. Consult reservations from an hour.\n";
  cout << "E. Make a reservation\nF. End.";
  cout << "\n*********************************\n";
  cout << "Enter the letter of the option you want: ";
  cin >> cOption;
  cOption = toupper(cOption);
  switch (cOption){
    case 'A':
    consultServices(arrServ, iContServ);
    break;
    case 'B':
    consultAllReservations(arrReserv, arrServ, iContServ, iContReserv);
    break;
    case 'C':
    consultReservationsFromAService(arrReserv, arrServ, iContReserv, iContServ);
    break;
    case 'D':
    consultReservationsFromAnHour(arrReserv, arrServ, iContServ, iContReserv);
    break;
    case 'E':
    makeAReservation(arrReserv, arrServ, iContReserv);
    break;
    case 'F':
    cout << "Thanks, bye!";
    break;
    default:
    cout << "Wrong option, try again.";
    break;
  }
}

int main() {
  int iContServ = 0, iContReserv = 0;
  service *arrServ[20];
  reservation arrReserv[50];

  fillServiceArray(arrServ, iContServ);
  fillReservArray(arrReserv, iContReserv);

  char cOption = ' ';

  while (cOption != 'F'){
    chooseOption(cOption, arrServ, arrReserv, iContServ, iContReserv);
  }

  return 0;
} 