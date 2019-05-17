import processing.pdf.*;

int select, palSelect;
boolean mode = false;
color pal[]={color(random(256)), color(random(256)), color(random(256))};
boolean save = false;

void setup(){
  size(595,842);
  frameRate(24);
  rectMode(CORNERS);
}

void draw(){
  fill(pal[palSelect]); stroke(pal[palSelect]);
  if (mode){
    if (select == 0) {stroke(0); strokeWeight(5); point(mouseX, mouseY);}
    else if (select == 1) {stroke(0); line(mouseX, mouseY, mouseX+100, mouseY+100);}  
    else if (select == 2) {noStroke(); ellipse(mouseX, mouseY, 100, 100);}
    else if (select == 3) {noStroke(); rect(mouseX, mouseY, mouseX+100, mouseY+100);}
  }
}

void mouseClicked(){
  beginRecord(PDF, "drawer.pdf");  
}

void mouseReleased(){
  endRecord(); 
}

void keyPressed(){
  if (key == ENTER) mode = !mode;
  if (key == 'c' || key == 'C') {palSelect = int(random(3)); println(palSelect);}
  if (key == 't' || key == 'T') {select = int(random(4)); println(select);}
}
