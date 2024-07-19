#include "pitches.h"

#define pinPsvBzzr 5

#define pinLed_G 6
#define pinLed_Y 9
#define pinLed_B 10
#define pinLed_R 11

#define NUM_OF_LEDS 4
int Leds[NUM_OF_LEDS]={pinLed_G,pinLed_Y,pinLed_B,pinLed_R};
int Tones[NUM_OF_LEDS]={NOTE_C4, NOTE_G3, NOTE_A3, NOTE_F2};
#define MAX_NUM_OF_LIGHTS 10
int ChosenIndexes[MAX_NUM_OF_LIGHTS];
int NumOfChosenIndexes=0;

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
void loop() {
  
}
void LedBlink(int chnl){
  digitalWrite(Leds[chnl],HIGH);
  tone(pinPsvBzzr,Tones[chnl],600);
  //delay(600);
  digitalWrite(Leds[chnl],LOW);
}






