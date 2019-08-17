int sphrXdir=5, sphrYdir=5; //sphrle directions for movement
int sphrX=475, sphrY=240; //sphrle coordinates
float sphrRadius=150; //sphrle radius



void setup(){
  size(850, 480, P3D);
}

void draw(){
  int r=int(random(0,255)),g=int(random(0,255)),b=int(random(0,255)); //line colors; generated randomly
  int lineX=int(random(0,width)), lineY=int(random(0,height)), lineX2=int(random(0,width)), lineY2=int(random(0,height)); //line coordinates; generated randomly
  int rotAngle=int(random(-100, 100)); //set rotation angle
  
  stroke(r, g, b); //set stroke to random color
  line(lineX, lineY, lineX2, lineY2); //draw line on screen
  stroke(0); //set stroke to black
  fill(255); //set fill to grey
  translate(sphrX,sphrY,0); //move sphere to coordinates
  rotate(rotAngle); //rotate sphere just because
  sphere(sphrRadius/3); //draw sphere on screen
  
  sphrX=sphrX+sphrXdir; //set sphere x coords 
  sphrY=sphrY+sphrYdir; //set sphere y coords
  
  if (sphrX == width-sphrRadius) sphrXdir=sphrXdir*(-1); //set sphere directions based on where the sphere is
  if (sphrX == sphrRadius) sphrXdir=sphrXdir*(-1);
  if (sphrY == height-sphrRadius) sphrYdir=sphrYdir*(-1);
  if (sphrY == sphrRadius) sphrYdir=sphrYdir*(-1);
}

void loop(){
  redraw();
}
