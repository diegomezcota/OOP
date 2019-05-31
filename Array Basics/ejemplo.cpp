#include <iostream>
//Diego Gómez Cota
//A00824758
//Activity 1
int main() {
  double dDataArray[5];

  for (int i = 0; i < 5; i++){
    std::cout << i + 1 << ".- Enter data: ";
    std::cin >> adDataArray[i];
  }

  //Activity 2

  double dDataArray2[20];
  int iDataAmount;

    std::cout << "Enter the amount of data you want to input: " << std::endl;
    std::cin >> iDataAmount;

    for (int i=0; i < iDataAmount; i++){
        std::cout << i+1 << ".- Enter data: ";
        std::cin >> dDataArray2[i];
    }

 //Activity 3

  double dDataArray3[20], dAverage, dSum = 0;
  int iDataAmount2;

    std::cout << "Enter the amount of data you want to input: " << std::endl;
    std::cin >> iDataAmount2;

    for (int i=0; i < iDataAmount2; i++){
        std::cout << i+1 << ".- Enter data: ";
        std::cin >> dDataArray3[i];
        dSum += dDataArray3[i];
    }

    dAverage = dSum/iDataAmount2;
    std::cout << "Average of data: " << dAverage;

  return 0;
}
