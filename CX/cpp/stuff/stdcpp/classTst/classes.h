#ifndef CLASSES_DEF
#define CLASSES_DEF
#endif

class CalcClass {
private:
  double regX;
  double regY;
  char op;
  double res;
public:
  CalcClass() {
    regX = regY = res = 0;
    op = '+';
  }
  //put instructions
  void putX(double in) {
    regX = in;
  }
  void putY(double in) {
    regY = in;
  }
  void putOp(char in) {
    op = in;
  }
  //get instructions, useful for debugging
  double getX() {
    return regX;
  }
  double getY() {
    return regY;
  }
  char getOp() {
    return op;
  }
  void run(){
    switch (op) {
    case '+' :
      res = regX + regY;
      break;
    case '-' :
      res = regX - regY;
      break;
    case '*' :
      res = regX * regY;
      break;
    case '/' :
      res = regX / regY;
      break;
    }      
  }
  double getRes() {
    return res;
  }
};
