PImage srcImg;
PImage overlay;

int overX=-32;
int overY=-32;

void setup() {
  size(32, 32);
  smooth();
  noStroke();
  background(0);

  
  srcImg = loadImage("majentoBG.gif");
  overlay = loadImage("overlay.png");

  frameRate(12);
}

void draw() {
  image(srcImg, 0, 0);

  image(overlay, overX, overY);
  //image(overlay, overX+32, overY);
  //image(overlay, overX, overY+32);
  //image(overlay, overX+32, overY+32);

  if (overX != 0 && overY != 0){
    overX++;
    //overY++;
    TImage frame = new TImage(width,height,RGB,sketchPath("frame_"+nf(frameCount,3)+".png"));
    frame.set(0,0,get());
    frame.saveThreaded();
  }
/*
  if(frameCount <= 120){
    TImage frame = new TImage(width,height,RGB,sketchPath("frame_"+nf(frameCount,3)+".png"));
    frame.set(0,0,get());
    frame.saveThreaded();
  }*/
}
class TImage extends PImage implements Runnable{//separate thread for saving images
  String filename;

  TImage(int w,int h,int format,String filename){
    this.filename = filename;
    init(w,h,format);
  }

  public void saveThreaded(){
    new Thread(this).start();
  }

  public void run(){
    this.save(filename);
  }

}
