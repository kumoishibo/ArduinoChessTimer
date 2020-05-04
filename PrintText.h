/*************************************************** 
  Copyright (c) 2018 Written by Kumoi for the Rolling Chess set
  Started programming in August 2018 for use with Arduino ItsyBitsy by Adafruit
  Designed to be used with Adafruit 7-segment backpacks, LEDs and passive buzzer

  Hello Message

  Produced for Corey, Written by Kumoi as a personal project
  Apache 2.0, all text above must be included in any redistribution
****************************************************/

//"    HELLO COREY    "
uint8_t HelloCorey[27]={
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B01110100,
B01111001,
B00111000,
B00111000,
B01011100,
B00000000,
B00000000,
B00000000,
B00111001,
B01011100,
B01010000,
B01111001,
B01101110,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000,
B00000000
};

//"    Presets    "
uint8_t Presets[8]={
B01110011,
B01010000,
B01111001,
B01101101, 
B01111001,
B00000111,
B01101101,
B00000000
};

//"    SuddenDeath    "
uint8_t SuddenDeath[16]={
B01101101,
B00011100,
B01011110,
B01011110,
B01111001,
B01010100,
B00000000,
B00000000,
B01011110,
B01111001,
B01110111,
B00000111,
B01110110,
B00000000,
B00000000,
B00000000
};

//"    Bonus    "
uint8_t Bonus[8]={
B01111100,
B01011100,
B01010100,
B00011100,
B01101101,
B00000000,
B00000000,
B00000000
};

//"    HourGlass    "
uint8_t HourGlass[16]={
B01110110,
B01011100,
B00011100,
B01010000,
B00000000,
B00000000,
B00000000,
B00000000,
B01101111,
B00111000,
B01110111,
B01101101, 
B01101101,
B00000000,
B00000000,
B00000000
};

//"    Delay    "
uint8_t Delay[5]={
B01011110,
B01111001,
B00111000,
B01110111,
B01101110
};

//"    Settings    "
uint8_t Settings[8]={
B01101101, 
B01111001,
B00000111,
B00000111,
B00000110,
B01010100,
B01101111,
B01101101
};

//"    SOUND    "
uint8_t Sound[5]={
B01101101,
B01011100,
B00011100,
B01010100,
B01011110
};
//"    Silent    "
uint8_t Silent[6]={
B01101101,
B00000110,
B00111000,
B01111001,
B01111001,
B00000111
};


/*************************************************
 * Public Constants
 *************************************************/
 
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
