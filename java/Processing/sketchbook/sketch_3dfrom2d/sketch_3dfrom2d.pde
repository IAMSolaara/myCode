int drawcnt = 0;

int drawcnt2 = 0;

int cntStep1 = 7;
int cntStep2 = cntStep1*2;
int cntStep3 = cntStep1*4;
int cntStep4 = cntStep1*8;

float noiseBellino = 0;

float offsettoNoioso = 0;

int faceToDraw = 0;

color fillColor = #000000;

int textSize = 15;

PImage plusButton;
PImage minusButton;
PImage switchButton;

PImage plusButtonPressed;
PImage minusButtonPressed;
PImage switchButtonPressed;

boolean mousePremuto = false;
boolean prevMousePremuto = mousePremuto;


class cube{
  boolean showCoords = true;
  
  float face1[][]={{200, 100}, {100, 150}, {200, 200}, {300, 150}};
  float face2[][]={{200, 20}, {100, 70}, face1[1], face1[0]};
  float face3[][]={face2[0], {300, 70}, face1[3], face1[0]};
  float faces[][][]={face1, face2, face3};
  
  float xoffset = 0;
  float yoffset = 200;
  float offinc = 1;
  
  
  float faceSeparator = 20;
  float faceSeparators[][]={{0, 0}, {0, 0}, {0, 0}};
  float sepinc = 1;  
  
  void buildCube(){
    for (int buildCnt = 0; buildCnt < faces.length; buildCnt++) {
      buildFace(faces[buildCnt], buildCnt);
      traceFaceVerts(faces[buildCnt], buildCnt);
    }
  }
  
  void buildFace(float face[][], int faceNum){

    faceSeparators[faceNum][0] = faceSeparatorCheck(faceNum, "x");
    faceSeparators[faceNum][1] = faceSeparatorCheck(faceNum, "y");
    int fcnt = 0;
    int fpcnt = 0;
    while (fcnt < face.length) {
      if (fcnt < face.length - 1) {
        line(face[fcnt][fpcnt] + xoffset + faceSeparators[faceNum][0], face[fcnt][fpcnt+1] + yoffset + faceSeparators[faceNum][1], face[fcnt+1][fpcnt] + xoffset + faceSeparators[faceNum][0], face[fcnt+1][fpcnt+1] + yoffset + faceSeparators[faceNum][1]);
      }
      else if (fcnt == face.length-1) {
        line(face[fcnt][fpcnt] + xoffset + faceSeparators[faceNum][0], face[fcnt][fpcnt+1] + yoffset + faceSeparators[faceNum][1], face[0][fpcnt] + xoffset + faceSeparators[faceNum][0], face[0][fpcnt+1] + yoffset + faceSeparators[faceNum][1]);
      }
      //print(str(face[0][0]) + " " + str(face[0][1]) + "\n");
      fcnt++;
    }
  }
  float faceSeparatorCheck(int fcn, String cho){
    float retorno = 0;
    if (cho == "x") {
      if (fcn == 0) {
        retorno = 0;
      }
      if (fcn == 1) {
        retorno = -abs(faceSeparator);
      }
      if (fcn == 2) {
        retorno = faceSeparator;
      }
    }
    else if (cho == "y") {
      if (fcn == 0) {
        retorno = faceSeparator;
      }
      if (fcn == 1) {
        retorno = -abs(faceSeparator);
      }
      if (fcn == 2) {
        retorno = -abs(faceSeparator);
      }
    }
    return retorno;
  }
  
  void traceFaceVerts(float face[][], int fn){
    if (showCoords) {
      float vpos[]={0, 0};
      for (int j=0; j < face.length; j++){
        for (int i=0; i < face[j].length-1; i++){
          vpos[i] = face[j][i] + xoffset + faceSeparators[fn][0];
          vpos[i+1] = face[j][i+1] + yoffset + faceSeparators[fn][1];
          circle(vpos[i], vpos[i+1], 10);
          text("face[" + str(fn) + "][" + str(j)+ "]\n x:" + str(vpos[i]) + " y:" + str(vpos[i+1]), vpos[i] + 8, vpos[i+1] - 8);
        }
      }
    }
  }
}

void setup(){
    size(1024, 768);
    frameRate(60);
    fill(fillColor);
    textSize(textSize);
    plusButton = loadImage("res/plusButton.png");
    minusButton = loadImage("res/minusButton.png");
    switchButton = loadImage("res/switchButton.png");
    plusButtonPressed = loadImage("res/plusButtonPressed.png");
    minusButtonPressed = loadImage("res/minusButtonPressed.png");
    switchButtonPressed = loadImage("res/switchButtonPressed.png");
}

cube cubino = new cube();

void draw(){
  
  
  
  cntStep2 = cntStep1*2;
  cntStep3 = cntStep1*3;
  cntStep4 = cntStep1*4;

  noiseBellino = noiseBellino + 0.1;
  
  offsettoNoioso = noise(offsettoNoioso) * 10;
  
  background(220);
  if (drawcnt >= cntStep4) drawcnt = cntStep1;
  
  if (drawcnt == cntStep1) faceToDraw = 0;
  
  if (drawcnt == cntStep2) faceToDraw = 1;
  
  if (drawcnt == cntStep3) faceToDraw = 2;

  if (drawcnt == 0) faceToDraw = -1;

  drawcnt++;

  if (faceToDraw == -1) cubino.buildCube();
  else {
    cubino.buildFace(cubino.faces[faceToDraw], faceToDraw);
    cubino.traceFaceVerts(cubino.faces[faceToDraw], faceToDraw);
  }
  HUD();
  
}

void mouseClicked(){
  mousePremuto = true;
  println(str(mouseX) + " " + str(mouseY));
}


void HUD(){
  
  float yseparator = textSize * 3;
  float xseparator = 10;
  
  float HUDx = width-350;
  float HUDy = 20;
  
  float butWidth = 30;
  float butHeight = 30;
  //step inc/dec
  float but1[]={HUDx, HUDy};
  float but2[]={HUDx+butWidth+xseparator, HUDy};
  
  //xoff inc/dec
  float but3[]={but1[0], but1[1] + yseparator + butHeight};
  float but4[]={but2[0], but2[1] + yseparator + butHeight};
  
  //xoff inc/dec
  float but5[]={but3[0], but3[1] + yseparator + butHeight};
  float but6[]={but4[0], but4[1] + yseparator + butHeight};
  
  //yoff inc/dec
  float but7[]={but5[0], but5[1] + yseparator + butHeight};
  float but8[]={but6[0], but6[1] + yseparator + butHeight};
  
  //sep inc/dec
  float but9[]={but7[0], but7[1] + yseparator + butHeight};
  float but10[]={but8[0], but8[1] + yseparator + butHeight};
  
  //sep inc inc/dec
  float but11[]={but9[0], but9[1] + yseparator + butHeight};
  float but12[]={but10[0], but10[1] + yseparator + butHeight};
  
  //show coords toggle
  float but13[]={but11[0], but11[1] + yseparator + butHeight};
  
  float buttons[][]={but1, but2, but3, but4, but5, but6, but7, but8, but9, but10, but11, but12, but13};
  
  text("Cycle counter steps: " + str(cntStep1), but1[0], but1[1]-5);
  
  text("Cube offset increment: " + str(cubino.offinc), but3[0], but3[1]-5);
  
  text("Cube X offset: " + str(cubino.xoffset), but5[0], but5[1]-5);
  
  text("Cube Y offset: " + str(cubino.yoffset), but7[0], but7[1]-5);
  
  text("Cube face separator offset: " + str(cubino.faceSeparator), but9[0], but9[1]-5);
  
  text("Cube face separator offset increment: " + str(cubino.sepinc), but11[0], but11[1]-5);
  
  text("Cube face show coords: " + str(cubino.showCoords), but13[0], but13[1]-5);
    
  text("Cycle counter: " + str(drawcnt), 0, height-1);
  
  image(minusButton, but1[0], but1[1]);
  image(plusButton, but2[0], but2[1]);
  image(minusButton, but3[0], but3[1]);
  image(plusButton, but4[0], but4[1]);
  image(minusButton, but5[0], but5[1]);
  image(plusButton, but6[0], but6[1]);
  image(minusButton, but7[0], but7[1]);
  image(plusButton, but8[0], but8[1]);
  image(minusButton, but9[0], but9[1]);
  image(plusButton, but10[0], but10[1]);
  image(minusButton, but11[0], but11[1]);
  image(plusButton, but12[0], but12[1]);
  image(switchButton, but13[0], but13[1]);  
  
  if (mousePremuto) {
    for (int btnCnt = 0; btnCnt < buttons.length; btnCnt++){
      btnCheck(buttons[btnCnt], btnCnt, butWidth, butHeight);
    }
    mousePremuto = false;
  }
}

void btnCheck(float button[], int btn, float bw, float bh) {
  if ((mouseX >= button[0] && mouseX <= button[0] + bw) && (mouseY >= button[1] && mouseY <= button[1] + bh)) {
    switch (btn) {
      case 0:
        cntStep1--;
        image(minusButtonPressed, button[0], button[1]);
        break;
      case 1:
        cntStep1++;
        image(plusButtonPressed, button[0], button[1]);
        break;
      case 2:
        cubino.offinc--;
        image(minusButtonPressed, button[0], button[1]);
        break;
      case 3:
        cubino.offinc++;
        image(plusButtonPressed, button[0], button[1]);
        break;
      case 4:
        cubino.xoffset -= cubino.offinc;
        image(minusButtonPressed, button[0], button[1]);
        break;
      case 5:
        cubino.xoffset += cubino.offinc;
        image(plusButtonPressed, button[0], button[1]);
        break;
      case 6:
        cubino.yoffset -= cubino.offinc;
        image(minusButtonPressed, button[0], button[1]);
        break;
      case 7:
        cubino.yoffset += cubino.offinc;
        image(plusButtonPressed, button[0], button[1]);
        break;
      case 8:
        cubino.faceSeparator -= cubino.sepinc;
        image(minusButtonPressed, button[0], button[1]);
        break;
      case 9:
        cubino.faceSeparator += cubino.sepinc;
        image(plusButtonPressed, button[0], button[1]);
        break;
      case 10:
        cubino.sepinc--;
        image(minusButtonPressed, button[0], button[1]);
        break;
      case 11:
        cubino.sepinc++;
        break;
      case 12:
        cubino.showCoords = !cubino.showCoords;
        image(switchButtonPressed, button[0], button[1]);
        break;
    }
  }
}
