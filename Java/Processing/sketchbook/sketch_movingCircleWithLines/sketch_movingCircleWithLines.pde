int circXdir=1, circYdir=1; //circle directions for movement
int circX=120, circY=244; //circle coordinates
int circRadius=150; //circle radius



void setup(){
  size(850, 480, P2D);
}

void draw(){
  int r=int(random(0,255)),g=int(random(0,255)),b=int(random(0,255)); //line colors; generated randomly
  int lineX=int(random(0,width)), lineY=int(random(0,height)), lineX2=int(random(0,width)), lineY2=int(random(0,height));
  stroke(r, g, b); fill(0,0,0); //set stroke and fil colors
  
  line(lineX, lineY, lineX2, lineY2); //draw line on screen
  stroke(0,0,0);
  circle(circX, circY, circRadius); //draw circle on screen
  
  circX=circX+circXdir; //set circle coords 
  circY=circY+circYdir;
  
  if (circX == width-circRadius) circXdir=-1; //set circle directions based on where the circle is
  if (circX == circRadius) circXdir=1;
  if (circY == height-circRadius) circYdir=-1;
  if (circY == circRadius) circYdir=1;
}

void loop(){
  redraw();
}
