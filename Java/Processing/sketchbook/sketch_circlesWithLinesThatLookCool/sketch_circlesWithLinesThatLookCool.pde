int circRadius=50; //circle radius
int circ1Spd=10, circ2Spd=10, circ3Spd=10, circ4Spd=10; //circle directions for movement
int circ1Start=120, circ2Start=circ1Start+25, circ3Start=circ1Start+int(random(0,50)) , circ4Start=circ1Start+2; //circle start coords
int circ1End=480-circRadius, circ2End=480-120, circ3End=480-200, circ4End=480-20; //circle end coords
int circ1X=120, circ2X=120*2, circ3X=120*3, circ4X=120*4, circ1Y=circ1Start, circ2Y=circ2Start, circ3Y=circ3Start, circ4Y=circ4Start; //circle coords

void setup(){
  size(850, 480);
}

void draw(){

  //draw background to get rid of earlier waste
  background(0);


  //set stroke and fill to same blue-ish color
  stroke(#47907D); fill(#47907D); //set stroke and fil colors
  
  
  //set circle y coord
  circ1Y=circ1Y+circ1Spd;
  circ2Y=circ2Y+circ2Spd;
  circ3Y=circ3Y+circ3Spd;
  circ4Y=circ4Y+circ4Spd;
  
  //draw circles
  circle(circ1X, circ1Y, circRadius); //draw circle on screen
  circle(circ2X, circ2Y, circRadius); //draw circle on screen
  circle(circ3X, circ3Y, circRadius); //draw circle on screen
  circle(circ4X, circ4Y, circRadius); //draw circle on screen
  

  //draw lines between circles
  line(circ1X,circ1Y, circ2X,circ2Y);
  line(circ2X,circ2Y, circ3X,circ3Y);
  line(circ3X,circ3Y, circ4X,circ4Y);
  
  
  //check if circle has met end or start and invert direction if that is true
  if (circ1Y >= circ1End) circ1Spd=-10;
  else if (circ1Y <= circ1Start) circ1Spd=10;

  if (circ2Y >= circ2End) circ2Spd=-10;
  else if (circ2Y <= circ2Start) circ2Spd=10;
  
  if (circ3Y >= circ3End) circ3Spd=-10;
  else if (circ3Y <= circ3Start) circ3Spd=10;
  
  if (circ4Y >= circ4End) circ4Spd=-10;
  else if (circ4Y <= circ4Start) circ4Spd=10;
}

void loop(){
  redraw();
}
