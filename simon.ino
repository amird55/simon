#define pinLed_G 6
#define pinLed_Y 9
#define pinLed_B 10
#define pinLed_R 11

#define NUM_OF_LEDS 4
int Leds[NUM_OF_LEDS]={pinLed_G,pinLed_Y,pinLed_B,pinLed_R};

void setup() {
  for(int k=0;k<NUM_OF_LEDS; k++){
    pinMode(Leds[k],OUTPUT);
  }
}

void loop() {
  for(int k=0;k<NUM_OF_LEDS; k++){
    LedBlink(k);
  }
}
void LedBlink(int chnl){
  digitalWrite(Leds[chnl],HIGH);
  delay(600);
  digitalWrite(Leds[chnl],LOW);
}






