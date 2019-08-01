color pal[]={color/*0*/(int(random(0,255)),int(random(0,255)),int(random(0,255))),color/*1*/(int(random(0,255)),int(random(0,255)),int(random(0,255))),color/*2*/(int(random(0,255)),int(random(0,255)),int(random(0,255))),color/*3*/(int(random(0,255)),int(random(0,255)),int(random(0,255))),}; //create a palette of four randomly generated colors
int colorI=0; //index variable used to switch colors between the palette's
int rowI=0, colI=0; //index variable used to draw the rects
int sizeX=50, sizeY=75; //size of the individual rects
int rectX1=0, rectY1=0, rectX2=rectX1+sizeX, rectY2=rectY1+sizeY; //start and end point coords
int rowN=6, colN=14; //row and coloumn numbers

void setup(){
  size(850, 480); //set window size
} 

void draw(){
  while (rowI < rowN){
    colI=0; //take coloumn index to zero
    while(colI < colN){
      if (colorI>3) {colorI=0;} //take color index to zero when palette is all scrolled
      stroke(pal[colorI]); //set stroke currently selected palette color
      fill(pal[colorI]); //set fill to currently selected palette color
      rect(rectX1, rectY1, rectX2, rectY2); //draw rectangle
      colI++; //increment coloumn index
      rectX1=rectX1+sizeX; //add size to x1
      rectX2=rectX1+sizeX; //add size to x2 using x1
      colorI++; //increment color index
    }
    rectY1=rectY1+sizeY; //add size to y1
    rectY2=rectY1+sizeY; //add size to y2 using y1
    rectX1=0;  //take x1 back to zero to start next row
    rectX2=rectX1+sizeX; //add size to x2 using x1
    rowI++;  //increment row index
  }
  fill(0); stroke(0);  //set "bg" color to black; I put bg between quote marks because it is not really the bg, but rather a filler to mask artifacts errors in generation
  rect(sizeX*colN, 0, width, height);  //draw bg part 1
  rect(0, sizeY*rowN, width, height);  //draw rest of bg
}
