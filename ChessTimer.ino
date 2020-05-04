/*************************************************** 
  Copyright (c) 2018 Written by Kumoi for the Rolling Chess set
  Started programming in August 2018 for use with Arduino ItsyBitsy by Adafruit
  Designed to be used with Adafruit 7-segment backpacks, LEDs and passive buzzer

  Timer and state handler

  Produced for Corey, Written by Kumoi as a personal project
  Apache 2.0, all text above must be included in any redistribution
****************************************************/

void ChessTimer(){
//Variables: currTimeWhite, currTimeBlue, bonusTime, delayTime

  long DeltaTime = millis() - TimerMillis;
  
  //Check for back button
  if (GameOver){
    if(CheckButton(3)){
      if (!Mute)tone(micPin, 330, 30);
      MenuSys = GameMode;
    } 
  }
  else{
    if(LongCheckButton(3)){
      if (!Mute)tone(micPin, 330, 30);
      MenuSys = GameMode;
    } 
  }
  

  //Check for Pause button
  if(CheckButton(2) && !GameOver){
    if (!Mute)tone(micPin, 523, 30);
    paused = !paused;
  }

  //Draw Time as XX:XX unless under 60 seconds, then XX.XX format. Blink 00:00 when out of time & Play death music
  if(DeltaTime > 0) {
    
    if (paused){
      DeltaTime = 0;
//      matrixW.blinkRate(1);
//      matrixB.blinkRate(1);

    }
//    else {
//      matrixW.blinkRate(0);
//      matrixB.blinkRate(0);
//    }
    
    TimerMillis = millis(); 
    // add "&& currTimeBlue - DeltaTime > 0"  
    if (currTimeWhite - DeltaTime > 0  && currTimeBlue - DeltaTime > 0  ) {
      PlaySongOnce = false;
      GameOver = false;

      //If statement for swapping turns, and adding bonuses
      if (WhiteTurn){
        if (GameMode != 3)currTimeWhite -= DeltaTime;
        else{
          currTimeWhite -= DeltaTime;
          currTimeBlue += DeltaTime;
          }
        digitalWrite(WhiteLEDPIN, HIGH);
        digitalWrite(BlueLEDPIN, LOW);
        if(CheckButton(1) && !paused){
          currTimeBlue += bonusTime;
          if (!Mute)tone(micPin, 392, 30);
          WhiteTurn = false;}
      }
      else{
        if (GameMode != 3)currTimeBlue -= DeltaTime;
        else{
          currTimeWhite += DeltaTime;
          currTimeBlue -= DeltaTime;
          }
        digitalWrite(WhiteLEDPIN, LOW);
        digitalWrite(BlueLEDPIN, HIGH);
        if(CheckButton(0) && !paused){
          currTimeWhite += bonusTime;
          if (!Mute)tone(micPin, 440, 30);
          WhiteTurn = true;}
        
       }

      //Display Time on White player
      if (currTimeWhite > 10000){
        matrixW.writeDigitNum(0, (currTimeWhite / 600000), false);
        matrixW.writeDigitNum(1, (currTimeWhite / 60000) % 10, false);
        matrixW.drawColon(true);
        matrixW.writeDigitNum(3, ((currTimeWhite/1000) % 60)/10, false);
        matrixW.writeDigitNum(4, ((currTimeWhite/1000) % 60)%10, false);
      }
      else{
        matrixW.writeDigitNum(0, (currTimeWhite/1000)/10, false);
        matrixW.writeDigitNum(1, (currTimeWhite/1000)%10, true);
        matrixW.drawColon(false);
        matrixW.writeDigitNum(3, (currTimeWhite/100) % 10, false);
        matrixW.writeDigitNum(4, (currTimeWhite/10) %10, false);
      }

      //Display Time on Blue player
      if (currTimeBlue > 10000){
        matrixB.writeDigitNum(0, (currTimeBlue / 600000), false);
        matrixB.writeDigitNum(1, (currTimeBlue / 60000) % 10, false);
        matrixB.drawColon(true);
        matrixB.writeDigitNum(3, ((currTimeBlue/1000) % 60)/10, false);
        matrixB.writeDigitNum(4, ((currTimeBlue/1000) % 60)%10, false);
      }
      else{
        matrixB.writeDigitNum(0, (currTimeBlue/1000)/10, false);
        matrixB.writeDigitNum(1, (currTimeBlue/1000)%10, true);
        matrixB.drawColon(false);
        matrixB.writeDigitNum(3, (currTimeBlue/100) % 10, false);
        matrixB.writeDigitNum(4, (currTimeBlue/10) %10, false);
      }

      
    }
    else {
      //currTimeWhite = 0;
      //matrixW.println();
      //paused = true;
      GameOver = true;
//      matrixW.writeDigitNum(0,0, false);
//      matrixW.writeDigitNum(1,0, false);
//      matrixW.drawColon(true);
//      matrixW.writeDigitNum(3,0, false);
//      matrixW.writeDigitNum(4,0, false);

      if(currTimeWhite < currTimeBlue){
        matrixW.writeDigitRaw(0,B00111000);
        matrixW.writeDigitRaw(1,B00111111);
        matrixW.drawColon(false);
        matrixW.writeDigitRaw(3,B01101101);
        matrixW.writeDigitRaw(4,B01111001);
        currTimeWhite =0;
        if (currTimeBlue > 10000){
          matrixB.writeDigitNum(0, (currTimeBlue / 600000), false);
          matrixB.writeDigitNum(1, (currTimeBlue / 60000) % 10, false);
          matrixB.drawColon(true);
          matrixB.writeDigitNum(3, ((currTimeBlue/1000) % 60)/10, false);
          matrixB.writeDigitNum(4, ((currTimeBlue/1000) % 60)%10, false);
        }
        else{
          matrixB.writeDigitNum(0, (currTimeBlue/1000)/10, false);
          matrixB.writeDigitNum(1, (currTimeBlue/1000)%10, true);
          matrixB.drawColon(false);
          matrixB.writeDigitNum(3, (currTimeBlue/100) % 10, false);
          matrixB.writeDigitNum(4, (currTimeBlue/10) %10, false);
        }
      }
      else{
        currTimeBlue = 0;
        matrixB.writeDigitRaw(0,B00111000);
        matrixB.writeDigitRaw(1,B00111111);
        matrixB.drawColon(false);
        matrixB.writeDigitRaw(3,B01101101);
        matrixB.writeDigitRaw(4,B01111001);
        if (currTimeWhite > 10000){
          matrixW.writeDigitNum(0, (currTimeWhite / 600000), false);
          matrixW.writeDigitNum(1, (currTimeWhite / 60000) % 10, false);
          matrixW.drawColon(true);
          matrixW.writeDigitNum(3, ((currTimeWhite/1000) % 60)/10, false);
          matrixW.writeDigitNum(4, ((currTimeWhite/1000) % 60)%10, false);
        }
        else{
          matrixW.writeDigitNum(0, (currTimeWhite/1000)/10, false);
          matrixW.writeDigitNum(1, (currTimeWhite/1000)%10, true);
          matrixW.drawColon(false);
          matrixW.writeDigitNum(3, (currTimeWhite/100) % 10, false);
          matrixW.writeDigitNum(4, (currTimeWhite/10) %10, false);
        }
      }
      matrixW.writeDisplay();
      matrixB.writeDisplay();

      if(!PlaySongOnce && !Mute && GameOver){
        PlaySongOnce = true;
        PlayDeath();
      }
    }

  if(paused){
     if( millis()/500 %2 == 1){
      matrixW.drawColon(true);
      matrixW.drawColon(true);
     }
     else{
      matrixW.drawColon(false);
      matrixB.drawColon(false);
      }
    
    }
  } 
}

//**********  Mario Death song palyed when timer run outs **************
void PlayDeath()
{
  tone(micPin, NOTE_C5, 40);
  delay(40);
  tone(micPin, NOTE_CS5, 40); 
  delay(40);
  tone(micPin, NOTE_D5, 40); 
  delay(800);
  tone(micPin, NOTE_C5, LongNote);
  delay(LongNote);
  tone(micPin, NOTE_F5, LongNote); 
  delay(LongNote);
  delay(LongNote);
  tone(micPin, NOTE_F5, LongNote); 
  delay(LongNote);
  tone(micPin, NOTE_F5, SupLongNote); 
  delay(SupLongNote);
  tone(micPin, NOTE_E5, SupLongNote); 
  delay(SupLongNote);
  tone(micPin, NOTE_D5, SupLongNote); 
  delay(SupLongNote);
  tone(micPin, NOTE_C5, LongNote);
  delay(LongNote);
  tone(micPin, NOTE_E4, LongNote);
  delay(LongNote);
  delay(LongNote);
  tone(micPin, NOTE_E4, LongNote);
  delay(LongNote);
  tone(micPin, NOTE_C4, LongNote);
  delay(LongNote);
}
