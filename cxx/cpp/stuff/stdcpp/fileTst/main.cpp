#include <iostream>
#include <fstream>
#include "classes.h"

using namespace std;

int main() {
  ofstream file, file1, file2, file3, file4;
  CalcClass calc;
  
  file.open ("calcTest.dat", ios::binary | ios::out);
  file1.open("calcTest1.dat", ios::binary | ios::out);
  file2.open("calcTest2.dat", ios::binary | ios::out);

  file3.open ("doubleTest.dat", ios::binary | ios::out);
  file4.open ("test.dat", ios::binary | ios::out);

  double test = 57000000.543454545;
  file3.write((char*) &test, sizeof(double));
  
  file.write((char*) &calc, sizeof(calc));
  
  calc.setX(56);
  
  file1.write((char*) &calc, sizeof(calc));

  calc.setY(23.4534554345345);

  

  calc.setOp('/');
  calc.run();
  
  file2.write((char*) &calc, sizeof(calc));
  
  file.close();
  file1.close();
  file2.close();
  return 0;  
}
