#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void ptrTst(int* tst);

int main() {
     srand(time(NULL));
     int x = 1;
     cout << "Vaule X is: " << x << "\n";
     cout << "pointers test\n";
     ptrTst(&x);
     cout << "Modified value: " << x << "\n";
}

void ptrTst(int* tst) {
     *tst = *tst * rand() % 10;
}
