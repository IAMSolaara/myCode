float shipW, shipH;  //declare ship size
int shipX, shipY;  //declare ship coords
float alienW, alienH;  //declare alien size
float alienX; int alienY;  //declare alien coords (x is float to allow for finer control)
int misX, misY;  //declare missile coords
int misW, misH;  //declare missile size
PImage ship, alien;  //declare ship and alien image
PShape missile;  //declare missile shape
int spd;  //declare movement speed
float alienSpd;  //declare alien speed (float for same reason as alienX)
int border;  //declare screen borders
boolean misHidden=true;  //declare missile hidden state and init to true
boolean alienHidden=false;  //declare alien hidden state and init to false
void setup(){
  size(850,480);
  
  shipW=50; shipH=shipW*0.61;  //set ship width and height with correct proportions
  shipX=int((width/2)-(int(shipW)/2)); shipY=(height-int(shipH))-10;  //set ship coords
  
  alienW=50; alienH=alienW*0.72;  //set alien width and height with correct proportions
  alienX=75; alienY=75;  //set alien coords
  
  misW=10; misH=25;  //set missile size
  misY=shipY-50;  //set missile y coords
  
  spd=5;  //set movement speed
  alienSpd=0.15;  //set alien speed
  border=20;  //set screen borders
  
  ship=loadImage("ship.png");  //load ship sprite
  alien=loadImage("alien.png");  //load ship sprite
  
  missile=createShape(RECT, 0, 0, misW, misH);  //create missile shape
  missile.setFill(0);  //fill missile shape with black
  
  background(0);  //set bg to black
  noSmooth();  //disable smoothing for nice and crisp sprite pixels
}

void draw(){
  background(0);
  image(ship, shipX, shipY, shipW, shipH);  //draw ship on the screen

  shape(missile, misX, misY);  //draw missile on screen

  if (!alienHidden) image(alien, int(alienX), alienY, alienW, alienH);  //draw alien on the screen
  
  alienX=alienX+alienSpd;
  if (misHidden == false) misY=misY-spd; //missile movement
  if (misY <= 20 || misHit()==true) {
    misY=shipY-50; misHidden=true; missile.setFill(0); alienHidden=true;  //if missile hits ceiling or alien, take it back to starting state and hide alien
  }
}

void loop() {redraw();}

void keyPressed(){
  if (key == CODED){
    if (keyCode == LEFT && shipX > border) shipX=shipX-spd;  //move ship left
    if (keyCode == RIGHT && shipX < (width-border)-shipW) shipX=shipX+spd;  //move ship right
  }
  if (key == 'z') misShoot();  //call missile shooting function
}

void misShoot(){
  misHidden = false;  //show missile
  missile.setFill(255);  //set missile to ship color
  misX=(shipX+(int(shipW)/2))-misW/2;  //set missile x to middle point of ship width
}

boolean misHit(){
  boolean out=false;
  if (alienX < misX && (alienX+alienW) > (misX+misW)) {  //check if missile is inside alien's width
    if (alienY < misY && (alienY+alienH) > (misY+misH)) out=true;  //check if missile is also inside alien's height; if both are verified true is returned
  }
  else out=false;  //return false if conditions are not verified
  
  return out;
}
