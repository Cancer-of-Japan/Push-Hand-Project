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

#define LED 9

int pos;
int prev;
void avanti(){
    Serial.println("Avanti");
  //Forward sequence
  for(int i = 0; i<10; i++){
    faboPWM.set_channel_value(DIRA1, 1000 - i*40);
    faboPWM.set_channel_value(DIRA2, 0);
    faboPWM.set_channel_value(DIRB1, 1000 - i*40);
    faboPWM.set_channel_value(DIRB2, 0);
    faboPWM.set_channel_value(DIRC1, 0);
    faboPWM.set_channel_value(DIRC2, 1000 - i*40);
    faboPWM.set_channel_value(DIRD1, 0);
    faboPWM.set_channel_value(DIRD2, 1000 - i*40);
    delay(10);
  }
  
  faboPWM.set_channel_value(DIRA1, 500);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 500);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 500);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 500);
  delay(1000);


  
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
  delay(35);
  
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
    faboPWM.set_channel_value(DIRA2, 1000 - i*40);
    faboPWM.set_channel_value(DIRB1, 0);
    faboPWM.set_channel_value(DIRB2, 1000 - i*40);
    faboPWM.set_channel_value(DIRC1, 1000 - i*40);
    faboPWM.set_channel_value(DIRC2, 0);
    faboPWM.set_channel_value(DIRD1, 1000 - i*40);
    faboPWM.set_channel_value(DIRD2, 0);
    delay(10);
  }
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 300);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 300);
  faboPWM.set_channel_value(DIRC1, 300);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 300);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(1000);

  
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
  delay(35);
  
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
    faboPWM.set_channel_value(DIRA2, 1000 - i*50);
    faboPWM.set_channel_value(DIRB1, 1000 - i*50);
    faboPWM.set_channel_value(DIRB2, 0);
    faboPWM.set_channel_value(DIRC1, 0);
    faboPWM.set_channel_value(DIRC2, 1000 - i*50);
    faboPWM.set_channel_value(DIRD1, 1000 - i*50);
    faboPWM.set_channel_value(DIRD2, 0);
    delay(25);
  }

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 500);
  faboPWM.set_channel_value(DIRB1, 500);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 500);
  faboPWM.set_channel_value(DIRD1, 500);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(200);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 400);
  faboPWM.set_channel_value(DIRB1, 400);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 400);
  faboPWM.set_channel_value(DIRD1, 400);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(200);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 500);
  faboPWM.set_channel_value(DIRB1, 500);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 500);
  faboPWM.set_channel_value(DIRD1, 500);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(200);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 400);
  faboPWM.set_channel_value(DIRB1, 400);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 400);
  faboPWM.set_channel_value(DIRD1, 400);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(200);

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
  delay(50);
  
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

void shift_right_plane(){
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 600);
  faboPWM.set_channel_value(DIRB1, 600);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 600);
  faboPWM.set_channel_value(DIRD1, 600);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(1000);

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
  delay(50);
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
}
void shift_left(){
      Serial.println("Shift Left");
  //shift sequence
  for(int i = 0; i< 10; i++){
    faboPWM.set_channel_value(DIRA1, 1000 - i*50);
    faboPWM.set_channel_value(DIRA2, 0);
    faboPWM.set_channel_value(DIRB1, 0);
    faboPWM.set_channel_value(DIRB2, 1000 - i*50);
    faboPWM.set_channel_value(DIRC1, 1000 - i*50);
    faboPWM.set_channel_value(DIRC2, 0);
    faboPWM.set_channel_value(DIRD1, 0);
    faboPWM.set_channel_value(DIRD2, 1000 - i*50);
    delay(25);
  }
  
  faboPWM.set_channel_value(DIRA1, 500);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 500);
  faboPWM.set_channel_value(DIRC1, 500);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 500);
  delay(200);
  
  faboPWM.set_channel_value(DIRA1, 400);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 400);
  faboPWM.set_channel_value(DIRC1, 400);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 400);
  delay(200);

  faboPWM.set_channel_value(DIRA1, 500);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 500);
  faboPWM.set_channel_value(DIRC1, 500);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 500);
  delay(200);
  
  faboPWM.set_channel_value(DIRA1, 400);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 400);
  faboPWM.set_channel_value(DIRC1, 400);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 400);
  delay(200);
  
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
  delay(50);

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
void shift_left_plane(){
  faboPWM.set_channel_value(DIRA1, 700);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 700);
  faboPWM.set_channel_value(DIRC1, 700);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 700);
  delay(1000);
  
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
  delay(50);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
}

void avanti_fast(){
    faboPWM.set_channel_value(DIRA1, 2000);
    faboPWM.set_channel_value(DIRA2, 0);
    faboPWM.set_channel_value(DIRB1, 2000);
    faboPWM.set_channel_value(DIRB2, 0);
    faboPWM.set_channel_value(DIRC1, 0);
    faboPWM.set_channel_value(DIRC2, 2000);
    faboPWM.set_channel_value(DIRD1, 0);
    faboPWM.set_channel_value(DIRD2, 2000);
    delay(600);

    faboPWM.set_channel_value(DIRA1, 0);
    faboPWM.set_channel_value(DIRA2, 2000);
    faboPWM.set_channel_value(DIRB1, 0);
    faboPWM.set_channel_value(DIRB2, 2000);
    faboPWM.set_channel_value(DIRC1, 2000);
    faboPWM.set_channel_value(DIRC2, 0);
    faboPWM.set_channel_value(DIRD1, 2000);
    faboPWM.set_channel_value(DIRD2, 0);
    delay(400);

    faboPWM.set_channel_value(DIRA1, 0);
    faboPWM.set_channel_value(DIRA2, 0);
    faboPWM.set_channel_value(DIRB1, 0);
    faboPWM.set_channel_value(DIRB2, 0);
    faboPWM.set_channel_value(DIRC1, 0);
    faboPWM.set_channel_value(DIRC2, 0);
    faboPWM.set_channel_value(DIRD1, 0);
    faboPWM.set_channel_value(DIRD2, 0);
}

void setup() {
  pinMode(LED, OUTPUT);
  //IO_init();
  Serial.begin(9600);
  if(faboPWM.begin()) {
    Serial.println("Find PCA9685");
    faboPWM.init(300);
  }
  faboPWM.set_hz(50);
  Serial.println("Start"); 
  randomSeed(analogRead(0));
}

void loop() {
  digitalWrite(LED, HIGH);
  shift_right_plane();
  delay(500);
  digitalWrite(LED, LOW);
  shift_left_plane();
  delay(500);
  

}
