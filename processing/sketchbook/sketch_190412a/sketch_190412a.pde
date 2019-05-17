float clk=0;
int refr=5;
int border=10;
int sphrX=width/2, sphrY=height/2; //sphrle coordinates
float sphrRadius=25; //sphrle radius
float rotAngle=0; //set rotation angle

void li_mortacci(int out){
  stroke(out); fill(out);
  text("Li mortacci tua", random(0, width), random(0, height));
}

void e_quelli_de(int out){
  stroke(out); fill(out);
  int x=int(random(border, width-border)), y=int(random(border, height-border));
  println(x, y);
  point(x,y);
}

void setup(){
  size(720, 480, P3D);
  translate(sphrX, sphrY);
  
  sphereDetail(15); //set how detailed the sphere is
}

void draw(){

  rotateX(rotAngle); //rotate sphere just because
  fill(0, 10);
  rect(-1,-1,width+1,height+1);
  int tua=color(random(0, 255),random(0, 255),random(0, 255));
  int tu_madre=color(255);
  if (clk == refr){
    li_mortacci(tua);
    clk=0;
  }
  e_quelli_de(tu_madre);
  clk +=0.5;
  sphere(sphrRadius/3); //draw sphere on screen
  
  rotAngle=rotAngle+0.05;
}
