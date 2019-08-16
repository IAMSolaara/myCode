#include <iostream>
#include "classes.h"

int main() {
  CalcClass calc;
  calc.putX(15);
  calc.putY(12.22);
  calc.putOp('+');
  calc.run();
  std::cout << calc.getRes() << "\n";
}
