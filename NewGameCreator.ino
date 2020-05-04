/*************************************************** 
  Copyright (c) 2018 Written by Kumoi for the Rolling Chess set
  Started programming in August 2018 for use with Arduino ItsyBitsy by Adafruit
  Designed to be used with Adafruit 7-segment backpacks, LEDs and passive buzzer

  New Game Manager

  Produced for Corey, Written by Kumoi as a personal project
  Apache 2.0, all text above must be included in any redistribution
****************************************************/

void NewGameCreator(){

//  TimerMinutesW = 1;
//  TimerMinutesB = 1;
//  BonusSeconds = 1;
//  DelaySeconds = 1;
  WhiteTurn = true;

//************* Sudden Death mode *************//
  if (GameMode == 1){ 
    
    matrixW.print(TimerMinutesW, DEC);  
    matrixW.writeDigitRaw(0,B00111001);
    
    matrixB.print(TimerMinutesB, DEC); 
    matrixB.writeDigitRaw(0,B00111001);
     if(SetWhiteTime == 0){
      matrixW.blinkRate(1);
      matrixB.blinkRate(0);
     }
     else {
      matrixW.blinkRate(0);
      matrixB.blinkRate(1);
     }
      
    if(ShortCheckButton(0)){
      if (!Mute)tone(micPin, 440, 30);
      if(SetWhiteTime == 0)TimerMinutesW += (TimerMinutesW < 99)?1:0;
      else if(SetWhiteTime == 1) TimerMinutesB += (TimerMinutesB < 99)?1:0;
    }
    if(ShortCheckButton(1)){
      if (!Mute)tone(micPin, 392, 30);
      if(SetWhiteTime == 0)TimerMinutesW -= (TimerMinutesW > 1)?1:0;
      else if(SetWhiteTime == 1) TimerMinutesB -= (TimerMinutesB > 1)?1:0;
    }
    if(CheckButton(2)){
      if (!Mute)tone(micPin, 523, 30);
      if(SetWhiteTime != 0){
        matrixW.blinkRate(0);
        matrixB.blinkRate(0);
        currTimeBlue = TimerMinutesB*60000;
        currTimeWhite = TimerMinutesW*60000;
        bonusTime = 0;
        delayTime = 0;
        paused = true;
        
        MenuSys =11;
      }
      else SetWhiteTime = 1;
    }   
  }
//************* Bonus mode *************//
  else if (GameMode == 2){ 
    
    
     if(SetWhiteTime == 0){
      matrixW.blinkRate(1);
      matrixB.blinkRate(0);
      matrixW.print(TimerMinutesW, DEC);  
      matrixW.writeDigitRaw(0,B00111001);
      
      matrixB.print(TimerMinutesB, DEC); 
      matrixB.writeDigitRaw(0,B00111001);
     }
     else if(SetWhiteTime == 1){
      matrixW.blinkRate(0);
      matrixB.blinkRate(1);
      matrixW.print(TimerMinutesW, DEC);  
      matrixW.writeDigitRaw(0,B00111001);
      matrixB.print(TimerMinutesB, DEC); 
      matrixB.writeDigitRaw(0,B00111001);
     }
     else if(SetWhiteTime == 2){
      matrixW.blinkRate(0);
      matrixB.blinkRate(0);
      matrixW.print(BonusSeconds, DEC);  
      matrixW.writeDigitRaw(0,B01111100);
      matrixB.print(BonusSeconds, DEC); 
      matrixB.writeDigitRaw(0,B01111100);
     }
      
    if(ShortCheckButton(0)){
      if (!Mute)tone(micPin, 440, 30);
      if(SetWhiteTime == 0) TimerMinutesW += (TimerMinutesW < 99)?1:0;
      else if(SetWhiteTime == 1) TimerMinutesB += (TimerMinutesB < 99)?1:0;
      else if(SetWhiteTime == 2) BonusSeconds += (BonusSeconds < 99)?1:0;
    }
    if(ShortCheckButton(1)){
      if (!Mute)tone(micPin, 392, 30);
      if(SetWhiteTime == 0)TimerMinutesW -= (TimerMinutesW > 0)?1:0;
      else if(SetWhiteTime == 1) TimerMinutesB -= (TimerMinutesB > 0)?1:0;
      else if(SetWhiteTime == 2) BonusSeconds -= (BonusSeconds > 1)?1:0;
    }
    if(CheckButton(2)){
      if (!Mute)tone(micPin, 523, 30);
      if(SetWhiteTime >= 2){
        currTimeBlue = TimerMinutesB*60000;
        currTimeWhite = TimerMinutesW*60000;
        bonusTime = BonusSeconds*1000;
        currTimeWhite += bonusTime;
        delayTime = 0;
        paused = true;
        
        MenuSys =11;
      }
      else SetWhiteTime += 1;
    }   
  
  }

//************* HourGlass mode *************//  
  else if (GameMode == 3){
    if(SetWhiteTime == 0){
      matrixW.blinkRate(1);
      matrixB.blinkRate(0);
      matrixW.print(TimerMinutesW, DEC);  
      matrixW.writeDigitRaw(0,B01101101);
      matrixB.print(TimerMinutesB, DEC); 
      matrixB.writeDigitRaw(0,B01101101);
     }
     else if(SetWhiteTime == 1){
      matrixW.blinkRate(0);
      matrixB.blinkRate(1);
      matrixW.print(TimerMinutesW, DEC);  
      matrixW.writeDigitRaw(0,B01101101);
      matrixB.print(TimerMinutesB, DEC); 
      matrixB.writeDigitRaw(0,B01101101);
     }
      
    if(ShortCheckButton(0)){
      if (!Mute)tone(micPin, 440, 30);
      if(SetWhiteTime == 0) TimerMinutesW += (TimerMinutesW < 99)?1:0;
      else if(SetWhiteTime == 1) TimerMinutesB += (TimerMinutesB < 99)?1:0;
    }
    if(ShortCheckButton(1)){
      if (!Mute)tone(micPin, 392, 30);
      if(SetWhiteTime == 0)TimerMinutesW -= (TimerMinutesW > 1)?1:0;
      else if(SetWhiteTime == 1) TimerMinutesB -= (TimerMinutesB > 1)?1:0;
    }
    if(CheckButton(2)){
      
      if (!Mute)tone(micPin, 523, 30);
      if(SetWhiteTime == 1){
        matrixW.blinkRate(0);
        matrixB.blinkRate(0);
        currTimeBlue = TimerMinutesB*1000;
        currTimeWhite = TimerMinutesW*1000;
        bonusTime = 0;
        delayTime = 0;
        paused = true;
        
        MenuSys =11;
      }
      else SetWhiteTime = 1;
    }   
  
  
  }
  else if (GameMode == 4){ //Delay mode
  
  
  }
}
