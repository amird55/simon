#include "pitches.h"

#define pinPsvBzzr 5

#define pinLed_G 6
#define pinLed_Y 9
#define pinLed_B 10
#define pinLed_R 11

#define pinBtn_G 2
#define pinBtn_Y 3
#define pinBtn_B 4
#define pinBtn_R 12

#define NUM_OF_LEDS 4
int Leds[NUM_OF_LEDS]={pinLed_G,pinLed_Y,pinLed_B,pinLed_R};
int Tones[NUM_OF_LEDS]={NOTE_C4, NOTE_G3, NOTE_A3, NOTE_F2};
#define MAX_NUM_OF_LIGHTS 10
int ChosenIndexes[MAX_NUM_OF_LIGHTS];
int NumOfChosenIndexes=0;

int Btns[NUM_OF_LEDS]={pinBtn_G,pinBtn_Y,pinBtn_B,pinBtn_R};
int val[NUM_OF_LEDS];
int lastVal[NUM_OF_LEDS];
int PressedIndexes[MAX_NUM_OF_LIGHTS];
int NumOfPressedIndexes=0;
int maxNumOfPressedBtns=5;
unsigned long lastPressTime[NUM_OF_LEDS];
void Btn_Setup(){
  for(int k=0;k<NUM_OF_LEDS;k++){
    lastVal[k] = digitalRead(Btns[k]);
    lastPressTime[k] = millis();
  }
}
int GetPressedBtn(){
  int BtnPressed = -1;

  for(int k=0;k<NUM_OF_LEDS;k++){
    val[k] = digitalRead(Btns[k]);
    if((val[k]==LOW)&&(lastVal[k]==HIGH)&&(millis()-lastPressTime[k] > 50)){
      lastPressTime[k] = millis();
      BtnPressed = k;
    }
    lastVal[k] = val[k];
  }

  return BtnPressed;
}


void setup() {
  pinMode(pinPsvBzzr, OUTPUT);
  randomSeed(analogRead(A1));
  for(int k=0;k<NUM_OF_LEDS; k++){
    pinMode(Leds[k],OUTPUT);
  }
  for(int k=0;k<MAX_NUM_OF_LIGHTS;k++){
    ChosenIndexes[k]=-1;
  }
  ChooseRandomLights();
  ShowLights();
}
void ChooseRandomLights(){
  NumOfChosenIndexes=5;
  for(int k=0;k<NumOfChosenIndexes;k++){
    ChosenIndexes[k]=random(0,NUM_OF_LEDS);
  }
}
void ShowLights(){
  for(int k=0;k<NumOfChosenIndexes;k++){
    LedBlink(ChosenIndexes[k]);
  }
}
void ShowPresses(){
  for(int k=0;k<NumOfPressedIndexes;k++){
    LedBlink(PressedIndexes[k]);
  }
}
void loop() {
  if(NumOfPressedIndexes < maxNumOfPressedBtns){
    int pressedBtn=GetPressedBtn();
    if(pressedBtn > -1 ){
      PressedIndexes[NumOfPressedIndexes++]=pressedBtn;
    }
  } else {
  }
}
void LedBlink(int chnl){
  digitalWrite(Leds[chnl],HIGH);
  tone(pinPsvBzzr,Tones[chnl],600);
  //delay(600);
  digitalWrite(Leds[chnl],LOW);
}






