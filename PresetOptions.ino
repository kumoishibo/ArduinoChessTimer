/*************************************************** 
  Copyright (c) 2018 Written by Kumoi for the Rolling Chess set
  Started programming in August 2018 for use with Arduino ItsyBitsy by Adafruit
  Designed to be used with Adafruit 7-segment backpacks, LEDs and passive buzzer

  Preset Game Handler

  Produced for Corey, Written by Kumoi as a personal project
  Apache 2.0, all text above must be included in any redistribution
****************************************************/

void PresetOptions(){

  switch(presetMode){
    case 0: //Preset 1 minute Bullet
      WhiteTurn = true;
      matrixW.writeDigitNum(1,1, false);
      matrixW.drawColon(true);
      matrixW.writeDigitNum(3,0, false);
      matrixB.writeDigitNum(1,1, false);
      matrixB.drawColon(true);
      matrixB.writeDigitNum(3,0, false);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        presetMode +=1;}
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        presetMode =7;}
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        currTimeBlue = 59999;
        currTimeWhite = 59999;
        bonusTime = 0;
        delayTime = 0;
        paused = true;
        currTimeWhite += bonusTime;
        MenuSys = 11; 
      }
      break;
    case 1: //Preset 3 minute Blitz
      WhiteTurn = true;
      matrixW.writeDigitNum(1,3, false);
      matrixW.drawColon(true);
      matrixW.writeDigitNum(3,0, false);
      matrixB.writeDigitNum(1,3, false);
      matrixB.drawColon(true);
      matrixB.writeDigitNum(3,0, false);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        presetMode +=1;}
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        presetMode -=1;}
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        currTimeBlue = 180000;
        currTimeWhite = 180000;
        bonusTime = 0;
        delayTime = 0;
        paused = true;
        currTimeWhite += bonusTime;
        MenuSys = 11; 
      }
      break;
    case 2: //Preset 5 minute Blitz
      WhiteTurn = true;
      matrixW.writeDigitNum(1,5, false);
      matrixW.drawColon(true);
      matrixW.writeDigitNum(3,0, false);
      matrixB.writeDigitNum(1,5, false);
      matrixB.drawColon(true);
      matrixB.writeDigitNum(3,0, false);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        presetMode +=1;}
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        presetMode -=1;}
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        currTimeBlue = 300000;
        currTimeWhite = 300000;
        bonusTime = 0;
        delayTime = 0;
        paused = true;
        currTimeWhite += bonusTime;
        MenuSys = 11; 
      }
      break;
    case 3: //Preset 10 minute Rapid
      WhiteTurn = true;
      matrixW.writeDigitNum(0,1, false);
      matrixW.writeDigitNum(1,0, false);
      matrixW.drawColon(true);
      matrixW.writeDigitNum(3,0, false);
      matrixB.writeDigitNum(0,1, false);
      matrixB.writeDigitNum(1,0, false);
      matrixB.drawColon(true);
      matrixB.writeDigitNum(3,0, false);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        presetMode +=1;}
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        presetMode -=1;}
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        currTimeBlue = 600000;
        currTimeWhite = 600000;
        bonusTime = 0;
        delayTime = 0;
        paused = true;
        currTimeWhite += bonusTime;
        MenuSys = 11; 
      }
      break;
    case 4: //Preset 2 minute Blitz + 1 second bonus
      WhiteTurn = true;
      matrixW.writeDigitNum(1,2, false);
      matrixW.drawColon(true);
      matrixW.writeDigitNum(3,1, false);
      matrixB.writeDigitNum(1,2, false);
      matrixB.drawColon(true);
      matrixB.writeDigitNum(3,1, false);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        presetMode +=1;}
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        presetMode -=1;}
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        currTimeBlue = 120000;
        currTimeWhite = 120000;
        bonusTime = 1000;
        delayTime = 0;
        paused = true;
        currTimeWhite += bonusTime;
        MenuSys = 11; 
      }
      break;
    case 5: //Preset 3 minute Blitz + 2 second bonus
      WhiteTurn = true;
      matrixW.writeDigitNum(1,3, false);
      matrixW.drawColon(true);
      matrixW.writeDigitNum(3,2, false);
      matrixB.writeDigitNum(1,3, false);
      matrixB.drawColon(true);
      matrixB.writeDigitNum(3,2, false);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        presetMode +=1;}
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        presetMode -=1;}
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        currTimeBlue = 180000;
        currTimeWhite = 180000;
        bonusTime = 2000;
        delayTime = 0;
        paused = true;
        currTimeWhite += bonusTime;
        MenuSys = 11; 
      }
      break;
    case 6: //Preset 5 minute Blitz + 3 second bonus
      WhiteTurn = true;
      matrixW.writeDigitNum(1,5, false);
      matrixW.drawColon(true);
      matrixW.writeDigitNum(3,3, false);
      matrixB.writeDigitNum(1,5, false);
      matrixB.drawColon(true);
      matrixB.writeDigitNum(3,3, false);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        presetMode +=1;}
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        presetMode -=1;}
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        currTimeBlue = 300000;
        currTimeWhite = 300000;
        bonusTime = 3000;
        delayTime = 0;
        paused = true;
        currTimeWhite += bonusTime;
        MenuSys = 11; 
      }
      break;
    case 7: //Preset 15 minute Blitz + 15 second bonus
      WhiteTurn = true;
      matrixW.writeDigitNum(0,1, false);
      matrixW.writeDigitNum(1,5, false);
      matrixW.drawColon(true);
      matrixW.writeDigitNum(3,1, false);
      matrixW.writeDigitNum(4,5, false);

      matrixB.writeDigitNum(0,1, false);
      matrixB.writeDigitNum(1,5, false);
      matrixB.drawColon(true);
      matrixB.writeDigitNum(3,1, false);
      matrixB.writeDigitNum(4,5, false);
      if(CheckButton(0)){
        if (!Mute)tone(micPin, 440, 30);
        presetMode =0;}
      else if(CheckButton(1)){
        if (!Mute)tone(micPin, 392, 30);
        presetMode -=1;}
      if(CheckButton(2)){
        if (!Mute)tone(micPin, 523, 30);
        currTimeBlue = 900000;
        currTimeWhite = 900000;
        bonusTime = 15000;
        delayTime = 0;
        paused = true;
        currTimeWhite += bonusTime;
        MenuSys = 11; 
      }
      break;
  }      
}
