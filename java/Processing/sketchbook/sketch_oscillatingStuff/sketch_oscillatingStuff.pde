float rotOffset = 0.1;
float angle;
float xoff = 1;
float yoff = 1;
float start[]={12, 13}; 
float end[]={14, 15};
float x = start[0];
float y = start[1];
float swidth = 25;
float sheight = 25;

void setup(){
  size(800, 600);
  
}

void draw(){
  float xx = sin(angle);
  float sino = map(xx, -1, 1, 0, 255);
  background(175);
  fill(sino);
 
  rect(x, y, x + swidth, y + sheight);
   x++;
  y++;
  rotOffset += 1;
  angle += 0.1;
}
