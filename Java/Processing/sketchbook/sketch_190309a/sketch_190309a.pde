void setup(){
  size(850,480);
}
void draw(){
  int r,g,b;
  r=int(random(0,255));
  g=int(random(0,255));
  b=int(random(0,255));
  float test, test2, test3, test4;
  stroke(r, g, b);
  fill(r, g, b);
  test=random(0, 500);
  test2=random(0, 800);
  test3=random(0, 655);
  test4=random(0, 712);
  circle(test,test2,test3);
}

void loop(){
  int refrbase=500000000;
  int refresh=refrbase/30;
  int clk=0;
  while (keyPressed){
    if (clk > refresh){
      redraw();
      clk=0;
    }
    clk++;
  }
}
