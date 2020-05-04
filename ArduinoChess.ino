/*************************************************** 
  Copyright (c) 2018 Written by Kumoi for the Rolling Chess set
  Started programming in August 2018 for use with Arduino ItsyBitsy by Adafruit
  Designed to be used with Adafruit 7-segment backpacks, LEDs and passive buzzer

Menu system:
  -Game mode 1: Preset Games
  -Game mode 2: Sudden Death
  -Game mode 3: Bonus (Fischer)
  -Game mode 4: Hourglass
  -Game mode 5: Delay (European style)
  -Settings:
    -MuteAudio
    -Dim LCD
    -Brighten LCD

*Preset Game modes*
  1+0 Bullet
  2+1 Bullet
  3+0 Blitz
  3+2 Blitz
  5+0 Blitz
  5+3 Blitz
  10+0 Rapid
  15+15 Classical

  Produced for Corey, Written by Kumoi as a personal project
  Apache 2.0, all text above must be included in any redistribution
****************************************************/

#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <Math.h>
#include "PrintText.h"

//*******PINS***********
#define BlueLEDPIN 1
#define WhiteLEDPIN 0
#define micPin 5
#define UpBtn 11
#define DwnBtn 10
#define SelectBtn 9
#define BackBtn 7
#define LongNote 150
#define SupLongNote 200

Adafruit_7segment matrixW = Adafruit_7segment();
Adafruit_7segment matrixB = Adafruit_7segment();

int tempBrightness;
long previousMillis = 0;
long msgMillis = 0;
long BtnTimeMillis = 0;
long TimerMillis =0; 
long previousBtn = 0; 
long currTimeBlue = 0;
long currTimeWhite = 0;
long bonusTime = 0;
long delayTime = 0;

uint8_t buttonState[4] = { 0 };
uint8_t MenuSys;
uint8_t presetMode;
uint8_t GameMode;

bool BtnDelay;
bool ShortBtnDelay;
bool Mute;
bool swapMSG = false;
bool paused;
bool WhiteTurn;
bool GameOver;

bool PlaySongOnce = false;
uint8_t SetWhiteTime = 0;

//Temporary values for item creator:
int TimerMinutesW;
int TimerMinutesB;
int BonusSeconds;
int DelaySeconds;


void setup() {
  // put your setup code here, to run once:
  #ifndef __AVR_ATtiny85__
    Serial.begin(9600);
    //Serial.println("7 Segment Backpack Test");
  #endif
    matrixW.begin(0x71);
    matrixB.begin(0x70);

  pinMode(UpBtn, INPUT_PULLUP);
  pinMode(DwnBtn, INPUT_PULLUP);
  pinMode(SelectBtn, INPUT_PULLUP);
  pinMode(BackBtn, INPUT_PULLUP);

  pinMode(BlueLEDPIN, OUTPUT);
  pinMode(WhiteLEDPIN, OUTPUT);

  digitalWrite(WhiteLEDPIN, LOW);
  digitalWrite(BlueLEDPIN, LOW);
  
  paused = true;
  tempBrightness = 8;
  MenuSys = 0;
  BtnDelay = false;
  ShortBtnDelay = false;
  Mute = false;
  presetMode = 0;

  TimerMinutesW = 1;
  TimerMinutesB = 1;
  BonusSeconds = 1;
  DelaySeconds = 1;

  TimerMillis = millis();
  GameMode = 0;
  MessageTyper(HelloCorey);
  GameOver = false;
}

void loop() {
  
  matrixW.clear();
  matrixW.setBrightness(tempBrightness);
  matrixB.clear();
  matrixB.setBrightness(tempBrightness);
  
  unsigned long currentMillis = millis();
  long DeltaTime = currentMillis - previousBtn;
  
  buttonState[0] = digitalRead(UpBtn);
  buttonState[1] = digitalRead(DwnBtn);
  buttonState[2] = digitalRead(SelectBtn);
  buttonState[3] = digitalRead(BackBtn);
  
  if (BtnDelay && DeltaTime > 300){
      BtnDelay = false;
  }
  if (ShortBtnDelay && DeltaTime > 150){
      ShortBtnDelay = false;
  }
  matrixW.drawColon(false);
  matrixB.drawColon(false);
  switch (MenuSys) {
    case 0:
      digitalWrite(WhiteLEDPIN, LOW);
      digitalWrite(BlueLEDPIN, LOW);
      SetWhiteTime = 0;
      // statements
      matrixW.blinkRate(0);
      matrixB.blinkRate(0);
      MenuTyperB(Presets);
      BMenuTyperB(Presets);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        MenuSys +=1;
      }
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        MenuSys = 4;
      }
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        GameMode = 0;
        MenuSys = 6; 
      }
      break;
//********** SUDDEN DEATH Game mode ***********
    case 1:
      digitalWrite(WhiteLEDPIN, LOW);
      digitalWrite(BlueLEDPIN, LOW);
      SetWhiteTime = 0;
      matrixW.blinkRate(0);
      matrixB.blinkRate(0);
      MenuTyperA(SuddenDeath);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        MenuSys +=1;
      }
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        MenuSys -=1;
      }
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        GameMode = 1;
        MenuSys = 7; 
        
      }
      break;
//********** BONUS Game mode ***********
    case 2:
      digitalWrite(WhiteLEDPIN, LOW);
      digitalWrite(BlueLEDPIN, LOW);
      SetWhiteTime = 0;
      matrixW.blinkRate(0);
      matrixB.blinkRate(0);
      MenuTyperB(Bonus);
      BMenuTyperB(Bonus);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        MenuSys +=1;
        }
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        MenuSys -=1;
      }
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        GameMode = 2;
        MenuSys = 7; 
      }
      break;
//********** HourGlass Game mode ***********
    case 3:
      digitalWrite(WhiteLEDPIN, LOW);
      digitalWrite(BlueLEDPIN, LOW);
      SetWhiteTime = 0;
      matrixW.blinkRate(0);
      matrixB.blinkRate(0);
      MenuTyperA(HourGlass);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        MenuSys +=1;
        }
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        MenuSys -=1;
      }
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        GameMode = 3;
        MenuSys = 7; 
      }
      break;
//********** Settings Menu ***********
    case 4:
      // statements
      matrixW.blinkRate(0);
      matrixB.blinkRate(0);
      MenuTyperB(Settings);
      BMenuTyperB(Settings);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        MenuSys = 0;
        }
      if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        MenuSys -=1;
      }
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        MenuSys = 10; 
      }
      break; 

//********** Settings Menu *********** REMOVED FROM GAME!!!!
   case 5:
      // statements
//      matrixW.blinkRate(0);
//      matrixB.blinkRate(0);
//      MenuTyperB(Delay);
//      if(CheckButton(0)){
//        if (!Mute)tone(micPin, 440, 30);
//        MenuSys +=1;
//        }
//      else if(CheckButton(1)){
//        if (!Mute)tone(micPin, 392, 30);
//        MenuSys -=1;
//      }
      break;  
      
//***************** Preset options menu function(Preset Options.ino) *****************
    case 6:
      matrixW.blinkRate(0);
      matrixB.blinkRate(0);
      PresetOptions(); 
      
      if(CheckButton(3)){
        if (!Mute)tone(micPin, 330, 30);
        MenuSys =0;
      }
      break; 
//***************** Game Creator menu function(NewGameCreator.ino) *****************
    case 7:
      //matrixW.blinkRate(0);
      //matrixB.blinkRate(0);
      NewGameCreator();
      GameOver = false;
      if(CheckButton(3)){
        if (!Mute)tone(micPin, 330, 30);
        MenuSys =GameMode;
      }
      break; 

    case 8:
      // statements
//      matrixW.blinkRate(0);
//      matrixB.blinkRate(0);
//      matrixW.print(0x00A1, HEX);
//      if(CheckButton(3)){
//        if (!Mute)tone(micPin, 330, 30);
//        MenuSys =0;
//      }
      break; 

    case 9:
      // statements
//      matrixW.blinkRate(0);
//      matrixB.blinkRate(0);
//      matrixW.print(0x00A2, HEX);
//      
//      if(CheckButton(3)){
//        if (!Mute)tone(micPin, 330, 30);
//        MenuSys =0;
//      }
      break; 

    case 10: // Settings sub-menu
      // statements
      matrixW.blinkRate(0);
      matrixB.blinkRate(0);
      
      matrixB.print(tempBrightness, DEC);
      if(Mute){
        MenuTyperB(Silent);
        matrixB.writeDigitRaw(0,B01010100);
        matrixB.writeDigitRaw(1,B00000111);    
        }
      else {
        MenuTyperB(Sound);
        matrixB.writeDigitRaw(0,B01011110);
        matrixB.writeDigitRaw(1,B00000000);  
        }
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        //BrightenLight
        tempBrightness += (tempBrightness < 15)?1:0;
      }
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        //DimLight
        tempBrightness -= (tempBrightness > 0)?1:0;
      }
      else if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        Mute = !Mute; 
      }
      else if(CheckButton(3)){
        if (!Mute)tone(micPin, 330, 30);
        MenuSys =4;
      }
      break; 
      
    case 11: //Chess run Menu
      ChessTimer();
      break; 
  }
  //Draw all things to I2C 7 segment backpack.
  matrixW.writeDisplay();
  matrixB.writeDisplay();
}

//Time must have transpired before button pressed again
bool CheckButton(uint8_t i) {
  if (buttonState[i] == LOW && !BtnDelay) {
    BtnDelay=true;
    previousBtn = millis();
    return true;
  }
  else return false;
}

//ShortBtnDelay
//Time must have transpired before button pressed again
bool ShortCheckButton(uint8_t i) {
  if (buttonState[i] == LOW && !ShortBtnDelay) {
    ShortBtnDelay=true;
    previousBtn = millis();
    return true;
  }
  else return false;
}

//Must Hold button till 1.5s for button to transpire
bool LongCheckButton(uint8_t i) {
  if (buttonState[i] == LOW) {
    if (millis() - BtnTimeMillis >= 1500) {
          return true;
    }
  }
  else{
    BtnTimeMillis = millis();
    return false;
  }
  
}
