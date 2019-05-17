PImage img;  //create image variable
int sprX=0, sprY=0;  //set sprite coords
float sprW=50, sprH=sprW*1.17;  //set sprite width and height with correct proportions
int spd=5;
void setup(){
  size(850,480);
  img=loadImage("Sprite-0001.png");  //load image into img
  background(0);
  noSmooth();
}

void draw(){
  background(0);
  fill(0,0,255);
  rect(750, 0, width, height);
  image(img, sprX, sprY, sprW, sprH);  //draw image on the screen
  

  
}


void loop() {redraw();}
void keyPressed(){
  if (key == CODED){
    if (keyCode == UP) sprY=sprY-spd;
    else if (keyCode == DOWN) sprY=sprY+spd;
    else if (keyCode == LEFT) sprX=sprX-spd;
    else if (keyCode == RIGHT) sprX=sprX+spd;  
  }
}
