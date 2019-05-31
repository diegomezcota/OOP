#ifndef movie_h
#define movie_h

#include <string>

using namespace std;

class movie {
  private:
    int iMovieNumber, iYear, iLength, iActorAmount, iActorList[10];
    string sTitle, sGenre;
  public:
    movie();
    //movie(int, string, int, int, string, int, int[]);
    void setMovieNumber(int);
    void setTitle(string);
    void setYear(int);
    void setLength(int);
    void setGenre(string);
    int getMovieNumber();
    string getTitle();
    int getYear();
    int getLength();
    string getGenre();
    int getActorList(int);
    int getActorAmount();
    bool addActor(int);
};

movie::movie(){
  iMovieNumber = 0;
  iYear = 0;
  iLength = 0;
  iActorAmount = 0;
  sTitle = "";
  sGenre = "";
  for (int i = 0; i < 10; i++){
    iActorList[i] = 0;
  }
}

/*
movie::movie(int iMovieNumber, string sTitle, int iYear, int iLength, string sGenre, int iActorAmount, int iActorList[]){
  this iMovieNumber -> iMovieNumber;
  this sTitle -> sTitle;
  this iYear -> iYear;
  this iLength -> iLength;
  this sGenre -> sGenre;
  this iActorAmount -> iActorAmount;
  this iActorList[10] -> iActorList[10];
}
*/

void movie::setMovieNumber(int iMovieNumber){
  this->iMovieNumber = iMovieNumber;
}

void movie::setTitle(string sTitle){
  this->sTitle = sTitle;
}

void movie::setYear(int iYear){
  this->iYear = iYear;
}

void movie::setLength(int iLength){
  this->iLength = iLength;
}

void movie::setGenre(string sGenre){
  this->sGenre = sGenre;
}

int movie::getMovieNumber(){
  return iMovieNumber;
}

string movie::getTitle(){
  return sTitle;
}

int movie::getYear(){
  return iYear;
}

int movie::getLength(){
  return iLength;
}

string movie::getGenre(){
  return sGenre;
}

int movie::getActorAmount(){
  return iActorAmount;
}

int movie::getActorList(int iIndex){
  return iActorList[iIndex];
}

bool movie::addActor(int iID){

  if (iActorList[9] != 0){
    return false;
  }

  for (int i = 0; i < 10; i++){
    if (iActorList[i] == iID){
      return false;
    }
  }

  iActorAmount++;
  return true;

}

/*
Debe haber un método para agregar un actor a la lista de actores, éste método debe recibir como parámetro el id del actor que se va a agregar y el método debe agregarlo al arreglo listaActores y ajustar el atributo cantidadActores. Es necesario que este método tenga como valor de retorno un valor booleano que indique si se pudo agregar o no el actor a la película, no se podrá agregar si se duplica o si el arreglo ya tiene los 10 actores.
*/

#endif