int sphrXdir=5, sphrYdir=5; //sphrle directions for movement
int sphrX=475, sphrY=240; //sphrle coordinates
float sphrRadius=150; //sphrle radius
float rotAngle=0; //set rotation angle


void setup(){
  size(850, 480, P3D);
}

void draw(){
  int r=int(random(0,255)),g=int(random(0,255)),b=int(random(0,255)); //line colors; generated randomly
    
  background(0);
  stroke(0); //set stroke to random color
  fill(r, g, b); //set fill to grey
  translate(sphrX,sphrY,0); //move sphere to coordinates
  rotateX(rotAngle); //rotate sphere just because
  sphereDetail(15); //set how detailed the sphere is
  sphere(sphrRadius/3); //draw sphere on screen
  
  rotAngle=rotAngle+0.05;
  sphrX=sphrX+sphrXdir; //set sphere x coords 
  sphrY=sphrY+sphrYdir; //set sphere y coords
  
  if (sphrX == width-sphrRadius) sphrXdir=sphrXdir*(-1); //set sphere directions based on where the sphere is
  if (sphrX == sphrRadius) sphrXdir=sphrXdir*(-1);
  if (sphrY == height-sphrRadius) sphrYdir=sphrYdir*(-1);
  if (sphrY == sphrRadius) sphrYdir=sphrYdir*(-1);
}
