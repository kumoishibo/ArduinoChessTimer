/*************************************************** 
  Copyright (c) 2018 Written by Kumoi for the Rolling Chess set
  Started programming in August 2018 for use with Arduino ItsyBitsy by Adafruit
  Designed to be used with Adafruit 7-segment backpacks, LEDs and passive buzzer

  Screen Writing platform

  Produced for Corey, Written by Kumoi as a personal project
  Apache 2.0, all text above must be included in any redistribution
****************************************************/


//Message writer for Splash Screen "Hello Corey" screen
void MessageTyper(uint8_t *txt){
  for (uint16_t counter = 0; counter < 19; counter ++) {
    matrixW.writeDigitRaw(0,txt[counter]);
    matrixW.writeDigitRaw(1,txt[counter+1]);
    matrixW.writeDigitRaw(3,txt[counter+2]);
    matrixW.writeDigitRaw(4,txt[counter+3]);
    matrixW.writeDisplay();
    matrixB.writeDigitRaw(0,txt[counter+4]);
    matrixB.writeDigitRaw(1,txt[counter+5]);
    matrixB.writeDigitRaw(3,txt[counter+6]);
    matrixB.writeDigitRaw(4,txt[counter+7]);
    matrixB.writeDisplay();
    delay(100);
  }
}

//Message writer for Long text beyond 8 characters by splitting two words on alternating screens
void MenuTyperA(uint8_t *txt){
  
  if (millis() - msgMillis >= 800) {
    msgMillis = millis();
    swapMSG = !swapMSG;
    }
  if(swapMSG){
    matrixW.writeDigitRaw(0,txt[0]);
    matrixW.writeDigitRaw(1,txt[1]);
    matrixW.writeDigitRaw(3,txt[2]);
    matrixW.writeDigitRaw(4,txt[3]);
    matrixW.writeDisplay();
    matrixB.writeDigitRaw(0,txt[4]);
    matrixB.writeDigitRaw(1,txt[5]);
    matrixB.writeDigitRaw(3,txt[6]);
    matrixB.writeDigitRaw(4,txt[7]);
    matrixB.writeDisplay();
  }
  else{
    matrixW.writeDigitRaw(0,txt[8]);
    matrixW.writeDigitRaw(1,txt[9]);
    matrixW.writeDigitRaw(3,txt[10]);
    matrixW.writeDigitRaw(4,txt[11]);
    matrixW.writeDisplay();
    matrixB.writeDigitRaw(0,txt[12]);
    matrixB.writeDigitRaw(1,txt[13]);
    matrixB.writeDigitRaw(3,txt[14]);
    matrixB.writeDigitRaw(4,txt[15]);
    matrixB.writeDisplay();
  }
}

//Standard message Writer (split across the two 7segment displays)
void MenuTyperB(uint8_t *txt){
    matrixW.writeDigitRaw(0,txt[0]);
    matrixW.writeDigitRaw(1,txt[1]);
    matrixW.writeDigitRaw(3,txt[2]);
    matrixW.writeDigitRaw(4,txt[3]);
    matrixW.writeDisplay();
}
void BMenuTyperB(uint8_t *txt){
    matrixB.writeDigitRaw(0,txt[4]);
    matrixB.writeDigitRaw(1,txt[5]);
    matrixB.writeDigitRaw(3,txt[6]);
    matrixB.writeDigitRaw(4,txt[7]);
    matrixB.writeDisplay();
}
