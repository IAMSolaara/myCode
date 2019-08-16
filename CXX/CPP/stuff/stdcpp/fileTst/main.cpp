#include <iostream>
#include <fstream>
#include <ios>

using namespace std;

int main() {
  ofstream file;
  file.open("test.txt", ios::binary | ios::out);

  file.close();
  return 0;  
}
