int x1offset = 2;
int x2offset = -2;
int xyoffset = 2;

int x1=2, y1=2, x2=40, y2=40;
int x1s=x1, y1s=y1, x2s=x2, y2s=y2;

void setup(){
  size(400, 400);
}

void draw(){lines();}

void lines(){
  background(220);
  line(x1, y1+xyoffset, x2, y2+xyoffset);
  if (x1 == x2s) x1offset = -abs(x1offset);
  if (x1 == x1s) x1offset = abs(x1offset);
  if (x2 == x1s) x2offset = abs(x2offset);
  if (x2 == x2s) x2offset = -abs(x2offset);
  

  x1+=x1offset;
  x2+=x2offset;
  print(str(x1offset) + " "+ str(x2offset) + "\n");
}
