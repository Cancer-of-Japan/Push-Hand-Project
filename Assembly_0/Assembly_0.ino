#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#include "FaBoPWM_PCA9685.h"

FaBoPWM faboPWM;

//MOTOR CONTROL Pin
#define DIRA1 0
#define DIRA2 1
#define DIRB1 2
#define DIRB2 3
#define DIRC1 4
#define DIRC2 5
#define DIRD1 6
#define DIRD2 7

//Button pin
#define But1 2
#define But2 3
#define But3 4
#define Buzz 5
// pos is to keep track of position in 3*3 grid, an dprev keeps the previous lcoation on the grid.
int pos;
int prev;
//counter for mode selection 
int B1cnt = 0;
int B2cnt = 0;
int B3cnt = 0;
int mode;
int score;
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte A[8] = {
  0b00100,
  0b00110,
  0b00100,
  0b11111,
  0b10001,
  0b11111,
  0b00000
};

byte B[8] = {
  0b00100,
  0b00100,
  0b00100,
  0b00100,
  0b01010,
  0b01001,
  0b10001
};

  byte C[8] = {
  0b00100,
  0b00110,
  0b00100,
  0b11111,
  0b10001,
  0b11111,
  0b10111
};

byte D[8] = {
  0b00000,
  0b00000,
  0b00000,
  0b00000,
  0b10101,
  0b10101,
  0b10101
};


void avanti(){
    Serial.println("Avanti");
  //Forward sequence
  for(int i = 0; i<10; i++){
    faboPWM.set_channel_value(DIRA1, 1000 - i*40 + mode*40);
    faboPWM.set_channel_value(DIRA2, 0);
    faboPWM.set_channel_value(DIRB1, 1000 - i*40 + mode*40);
    faboPWM.set_channel_value(DIRB2, 0);
    faboPWM.set_channel_value(DIRC1, 0);
    faboPWM.set_channel_value(DIRC2, 1000 - i*40 + mode*40);
    faboPWM.set_channel_value(DIRD1, 0);
    faboPWM.set_channel_value(DIRD2, 1000 - i*40 + mode*40);
    delay(10);
  }
  
  faboPWM.set_channel_value(DIRA1, 500 + mode*300);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 500 + mode*300);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 500 + mode*300);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 500 + mode*300);
  delay(1000 - mode*300);


  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(50);
  
  //Stop sequence
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 2000);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 2000);
  faboPWM.set_channel_value(DIRC1, 2000);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 2000);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(35 + mode*20);
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
      Serial.println("Avanti End");
}

void reverse(){
      Serial.println("Reverse");
  //Forward sequence
  for(int i = 0; i<10; i++){
    faboPWM.set_channel_value(DIRA1, 0);
    faboPWM.set_channel_value(DIRA2, 1000 - i*40 + mode*40);
    faboPWM.set_channel_value(DIRB1, 0);
    faboPWM.set_channel_value(DIRB2, 1000 - i*40 + mode*40);
    faboPWM.set_channel_value(DIRC1, 1000 - i*40 + mode*40);
    faboPWM.set_channel_value(DIRC2, 0);
    faboPWM.set_channel_value(DIRD1, 1000 - i*40 + mode*40);
    faboPWM.set_channel_value(DIRD2, 0);
    delay(10);
  }
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 500 + mode*300);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 500 + mode*300);
  faboPWM.set_channel_value(DIRC1, 500 + mode*300);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 500 + mode*300);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(1000 - mode*300);

  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(50);
  
  //Stop sequence
  
  faboPWM.set_channel_value(DIRA1, 2000);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 2000);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 2000);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 2000);
  delay(35 + mode*20);
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
      Serial.println("Shift Reverse End");
}



void shift_right(){
      Serial.println("Shift Right");
  //shift sequence
  for(int i = 0; i< 10; i++){
    faboPWM.set_channel_value(DIRA1, 0);
    faboPWM.set_channel_value(DIRA2, 1200 - i*50 + mode*50);
    faboPWM.set_channel_value(DIRB1, 1200 - i*50 + mode*50);
    faboPWM.set_channel_value(DIRB2, 0);
    faboPWM.set_channel_value(DIRC1, 0);
    faboPWM.set_channel_value(DIRC2, 1200 - i*50 + mode*50);
    faboPWM.set_channel_value(DIRD1, 1200 - i*50 + mode*50);
    faboPWM.set_channel_value(DIRD2, 0);
    delay(25);
  }

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 600 + mode*300);
  faboPWM.set_channel_value(DIRB1, 600 + mode*300);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 600 + mode*300);
  faboPWM.set_channel_value(DIRD1, 600 + mode*300);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(300 - mode*100);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 400 + mode*300);
  faboPWM.set_channel_value(DIRB1, 400 + mode*300);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 400 + mode*300);
  faboPWM.set_channel_value(DIRD1, 400 + mode*300);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(100);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 600 + mode*300);
  faboPWM.set_channel_value(DIRB1, 600 + mode*300);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 600 + mode*300);
  faboPWM.set_channel_value(DIRD1, 600 + mode*300);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(300 - mode*100);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 400 + mode*300);
  faboPWM.set_channel_value(DIRB1, 400 + mode*300);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 400 + mode*300);
  faboPWM.set_channel_value(DIRD1, 400 + mode*300);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(100);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(20);
  
  //stop sequence  
  faboPWM.set_channel_value(DIRA1, 2000);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 2000);
  faboPWM.set_channel_value(DIRC1, 2000);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 2000);
  delay(50 + mode*30);
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
        Serial.println("Shift Right End");
}

void shift_left(){
      Serial.println("Shift Left");
  //shift sequence
  for(int i = 0; i< 10; i++){
    faboPWM.set_channel_value(DIRA1, 1200 - i*50 + mode*50);
    faboPWM.set_channel_value(DIRA2, 0);
    faboPWM.set_channel_value(DIRB1, 0);
    faboPWM.set_channel_value(DIRB2, 1200 - i*50 + mode*50);
    faboPWM.set_channel_value(DIRC1, 1200 - i*50 + mode*50);
    faboPWM.set_channel_value(DIRC2, 0);
    faboPWM.set_channel_value(DIRD1, 0);
    faboPWM.set_channel_value(DIRD2, 1200 - i*50 + mode*50);
    delay(25);
  }
  
  faboPWM.set_channel_value(DIRA1, 700 + mode*300);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 700 + mode*300);
  faboPWM.set_channel_value(DIRC1, 700 + mode*300);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 700 + mode*300);
  delay(300  - mode*100);
  
  faboPWM.set_channel_value(DIRA1, 400 + mode*300);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 400 + mode*300);
  faboPWM.set_channel_value(DIRC1, 400 + mode*300);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 400 + mode*300);
  delay(100);

  faboPWM.set_channel_value(DIRA1, 700 + mode*300);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 700 + mode*300);
  faboPWM.set_channel_value(DIRC1, 700 + mode*300);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 700 + mode*300);
  delay(300 - mode*100);
  
  faboPWM.set_channel_value(DIRA1, 400 + mode*300);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 400 + mode*300);
  faboPWM.set_channel_value(DIRC1, 400 + mode*300);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 400 + mode*300);
  delay(100);
  
  //stop sequence  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(20);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 2000);
  faboPWM.set_channel_value(DIRB1, 2000);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 2000);
  faboPWM.set_channel_value(DIRD1, 2000);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(50 + mode*30);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
        Serial.println("Shift Left End");
}
void check_score(){
        Serial.println("A0");
        Serial.println(analogRead(A0));
        Serial.println("========================================");
  if(analogRead(A0) > 10){
    score++;
    Serial.println(score);
    
  }
}

void easter_egg(){
  Serial.println("Easter egg called !!!!!!!");
  lcd.clear();
  delay(500);
  lcd.setCursor(1, 0);
  lcd.write(0);
  lcd.setCursor(3, 0);
  lcd.write(0);
  lcd.setCursor(5, 0);
  lcd.write(0);
  lcd.setCursor(7, 0);
  lcd.write(1);
  lcd.setCursor(0,1);
  lcd.print("1989/06/04 ???");
  delay(1000);
  
  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(3, 0);
  lcd.write(0);
  lcd.setCursor(5, 0);
  lcd.write(0);
  lcd.setCursor(7, 0);
  lcd.write(2);
  delay(1000);

  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(5, 0);
  lcd.write(0);
  lcd.setCursor(7, 0);
  lcd.write(2);
  lcd.setCursor(9, 0);
  lcd.write(0);
  delay(1000);

  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(7, 0);
  lcd.write(2);
  lcd.setCursor(9, 0);
  lcd.write(0);
  lcd.setCursor(11, 0);
  lcd.write(0);
  delay(1000);

  lcd.setCursor(0,0);
  lcd.print("                ");
  lcd.setCursor(7, 0);
  lcd.write(3);
  lcd.setCursor(9, 0);
  lcd.write(0);
  lcd.setCursor(11, 0);
  lcd.write(0);
  lcd.setCursor(13, 0);
  lcd.write(0);
  delay(1000);

  lcd.clear();
  lcd.print("Nothing...");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("      ...Happend");
  delay(1500);
  lcd.clear();
  
}
/////////////////////////////////////////////////////////////////////////

void setup() {
  Serial.begin(9600);
  //Setup for LCD
  Wire.begin();
  Wire.beginTransmission(0x27);
  lcd.init();
  lcd.backlight();
  lcd.clear();

  lcd.createChar(0, A);
  lcd.createChar(1, B);
  lcd.createChar(2, C);
  lcd.createChar(3, D);

  
  //Setup for Motor
  if(faboPWM.begin()) {
    Serial.println("Find PCA9685");
    faboPWM.init(300);
  }
  faboPWM.set_hz(50);
  Serial.println("Start"); 
  //RNG for random movement
  randomSeed(analogRead(0));

  //Setup for PINs
  pinMode(But1, INPUT);
  pinMode(But2, INPUT);
  pinMode(But3, INPUT);
  pinMode(6,  INPUT);

}

/////////////////////////////////////////////////////////////////////////

void loop() {
//Start up menu
  lcd.clear();
  lcd.print("Press start");
  delay(1000);
  while(digitalRead(But3) == LOW){
    lcd.setCursor(0,1);
    lcd.print("I'm waiting.. :(");
    if(digitalRead(But1) == HIGH){
      delay(100);
      easter_egg();
    }
  }
  lcd.clear();
  lcd.print("finally!!");
  delay(1000);

  lcd.clear();
//Speed selection screen HIGH or LOW
  while(digitalRead(But3) == LOW){
    lcd.setCursor(0,0);
    lcd.print("Choose Speed");
    lcd.print(" ");
    if(digitalRead(But1) == HIGH){
        delay(100);
        if(B1cnt == 1){ 
          B1cnt--;
        }
      delay(100);
      }else if(digitalRead(But2) == HIGH){
        delay(100);
        if(B1cnt == 0){ 
          B1cnt++;
        }
      }
      lcd.setCursor(0,1);
      lcd.print("Speed");
      lcd.print(" ");
      if(B1cnt == 1){
        lcd.print("Fast");
      }else{
        lcd.print("Slow");
        }
  }
  delay(500);
  lcd.clear();
// Mode selection screen practice or test
    while(digitalRead(But3) == LOW){
    lcd.setCursor(0,0);
    lcd.print("Choose Mode");
    lcd.print(" ");
    if(digitalRead(But1) == HIGH){
        delay(100);
        if(B2cnt == 1){ 
          B2cnt--;
        }
      delay(100);
      }else if(digitalRead(But2) == HIGH){
        delay(100);
        if(B2cnt == 0){ 
          B2cnt++;
        }
      }
      lcd.setCursor(0,1);
      lcd.print("Mode");
      lcd.print(" ");
      if(B2cnt == 1){ 
        lcd.print("Test    ");
      }else{
        lcd.print("Practice");
        }
  }
    delay(500);
    lcd.clear();

// Mode selection screen for duration
    while(digitalRead(But3) == LOW){
      lcd.setCursor(0,0);
      lcd.print("Choose Duration");
      lcd.print(" ");
      if(digitalRead(But1) == HIGH){
          delay(100);
          if(B3cnt > 0){ 
            B3cnt = B3cnt - 5;
          }
          lcd.setCursor(9,1);
          lcd.print("    ");
        delay(100);
        }else if(digitalRead(But2) == HIGH){
          delay(100);
            B3cnt = B3cnt + 5;
        }
        lcd.setCursor(0,1);
        lcd.print("Duration");
        lcd.print(" ");
//        if(B2cnt == 1){ 
//          lcd.print("Test    ");
//        }else{
//          lcd.print("Practice");
//          }
        lcd.print(B3cnt);
    }
  
  delay(500);
  lcd.clear();

  while (digitalRead(But3) == LOW){
    lcd.print("Press Start When");
    lcd.setCursor(0,1);
    lcd.print("You Are Ready ! ");
    delay(600);
    lcd.clear();
    delay(300);
  }

  delay(500);
  lcd.clear();

  lcd.print("Starting in...");
  
  for(int i = 0; i < 5; i++){
    lcd.setCursor(0,1);
    lcd.print(5 - i);
    tone(Buzz, 1000, 200);
    delay(1000);
  }
  tone(Buzz, 1200, 400);
  delay(500);
  lcd.clear();

  lcd.print("Here We Go ~ ");

//Main func
  int prac_cnt = B3cnt;
  mode = B2cnt;
  pos = 5;
//Movement starts  
  score = 0;
  int data = 0;
  for(int i = 0; i < prac_cnt; i++){
    if(pos != prev){
      pos = prev;
    }
    Serial.println("Initial Pos");
    Serial.println(pos);
    int var = 0;
    check_score();
//When practice mode, it waits until it has contact;    
    if(mode == 0){
        Serial.println("A0");
        Serial.println(analogRead(A0));
        Serial.println("========================================");
      while(analogRead(A0) < 10){
        Serial.println(analogRead(A0));
        Serial.println("========================================");
        tone(Buzz, 800, 500);
        delay(500);
      }
    }
//When its at middle
    if(pos == 5){
      var = 0;
    }
    //When its at corner
    if(pos == 1 || pos == 3 || pos == 7 || pos == 9){
      var = 1;
    }
    //When its at middle, against wall
    if(pos == 2 || pos == 4 || pos == 6 || pos == 8){
      var = 2;
    }
  int rng = 0;
  
    switch(var){
      case 0:
      Serial.println("Case 0");
      Serial.println(pos);
        rng = random(0,3);
      Serial.println("RNG");
      Serial.println(rng);      
        if(rng == 0){
          avanti();
          pos = 2;
          delay(500);
  
        }
        else if(rng == 1){
          shift_right();
          pos = 6;
          delay(500);
  
        }
        else if(rng == 2){
          reverse();
          pos = 8;
          delay(500);
  
        }
        else if(rng == 3){
          shift_left();
          pos = 4;
          delay(500);
  
        }
      break; 
      case 1:
      Serial.println("Case 1");
      Serial.println(pos);
      rng = random(0,1);
      Serial.println("RNG");
      Serial.println(rng);   
      //Top left
        if(pos == 1){
          if(rng == 0){
            reverse();
            pos = 4;
            delay(500);
          }
          else{
            shift_right();
            pos = 2;
            delay(500);
          }
          break;
        }
      //Top right
        if(pos == 3){
          if(rng == 0){
            reverse();
            pos = 6;
            delay(500);
  
          }
          else{
            shift_left();
            pos = 2;
            delay(500);
  
          }
          break;
        }
      //Bottom left
        if(pos == 7){
          if(rng == 0){
            avanti();
            pos = 4;
            delay(500);
  
          }
          else{
            shift_right();
            pos = 8;
            delay(500);
  
          }
          break;
        }
      //Bottom right
        if(pos == 9){
          if(rng == 0){
            avanti();
            pos = 6;
            delay(500);
          }
          else{
            shift_left();
            pos = 8;
            delay(500);
          }
          break;
        }
      break;
      
      case 2:
      Serial.println("Case 2");
      Serial.println(pos);
      rng = random(0,2);
      Serial.println("RNG");
      Serial.println(rng);
      //Top
        if(pos == 2){
          if(rng == 0){
            shift_left();
            pos = 1;
            delay(500);
  
          }
          else if(rng == 1){
            reverse();
            pos = 5;
            delay(500);
  
          }
          else{
            shift_right();
            pos = 3;
            delay(500);
  
          }
          break;
        }
      //Left
        if(pos == 4){
          if(rng == 0){
            avanti();
            pos = 1;
            delay(500);
  
          }
          else if(rng == 1){
            shift_right();
            pos = 5;
            delay(500);
  
          }
          else{
            reverse();
            pos = 7;
            delay(500);
          }
          break;
        }
      //Bottom
        if(pos == 8){
          if(rng == 0){
            avanti();
            pos = 5;
            delay(500);
  
          }
          else if(rng == 1){
            shift_right();
            pos = 9;
            delay(500);
  
          }
          else{
            shift_left();
            pos = 7;
            delay(500);
  
          }
          break;
        }
      //Right
        if(pos == 6){
          if(rng == 0){
            avanti();
            pos = 3;
            delay(500);
  
          }
          else if(rng == 1){
            shift_left();
            pos = 5;
            delay(500);
  
          }
          else{
            reverse();
            pos = 9;
            delay(500);
  
          }
          break;
        }
    break;
    default:
      avanti();
      delay(1000);
    break;    
    }
  
    prev = pos;
    Serial.println("Passed !!!!!");
    Serial.println("-------------------------------------");
    check_score();
  }
//Final part, shows score
  if(mode == 1){
    int max_score = prac_cnt * 2;
    Serial.println("score:");
    Serial.println(score);
    Serial.println(max_score);
    int disp_score = (score * 100 / max_score);
    Serial.println(disp_score);
    lcd.clear();
    lcd.print("Your Score is");
    lcd.setCursor(0,1);
    lcd.print(disp_score);
    lcd.print("/100");
      tone(Buzz, 800, 500);
  delay(500);
  tone(Buzz, 600, 500);
  delay(500);
  tone(Buzz, 1000, 500);
  delay(500);
  delay(1000);
    delay(3000);
  }else{
    lcd.clear();
    lcd.print("Practice Done");
    lcd.setCursor(0,1);
    lcd.print("Good Job !");
      tone(Buzz, 800, 500);
  delay(500);
  tone(Buzz, 600, 500);
  delay(500);
  tone(Buzz, 1000, 500);
  delay(500);
  delay(1000);
    delay(3000);
    }


  
}
