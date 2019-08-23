int sphrXdir=5, sphrYdir=5; //sphrle directions for movement
int sphrX=475, sphrY=240; //sphrle coordinates
float sphrRadius=150; //sphrle radius
float rotAngle=0; //set rotation angle
PShape sphere;
PImage img;


void setup(){
  size(1280, 720, P3D);
  sphere = createShape(SPHERE, sphrRadius/3);
  img = loadImage("checkerboard.jpg");
  sphere.setTexture(img);
  sphere.setStroke(255);
}

void draw(){
  int r=int(random(0,255)),g=int(random(0,255)),b=int(random(0,255)); //line colors; generated randomly
    
  background(0);
  stroke(255); //set stroke to random color
//  fill(r, g, b); //set fill to grey
  fill(255,0,0);
  translate(sphrX,sphrY,0); //move sphere to coordinates
  strokeWeight(2.5);
  rotateY(rotAngle); //rotate sphere just because
  rotateX(330);
  sphereDetail(13); //set how detailed the sphere is
//  sphere(sphrRadius/3); //draw sphere on screen
  shape(sphere);
  rotAngle+=0.05;
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
