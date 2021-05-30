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

void avanti(){
  //Forward sequence
  faboPWM.set_channel_value(DIRA1, 500);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 500);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 500);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 500);
  delay(250);
  
  faboPWM.set_channel_value(DIRA1, 1000);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 1000);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 1000);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 1000);
  delay(500);
  
  faboPWM.set_channel_value(DIRA1, 500);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 500);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 500);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 500);
  delay(250);

  //Stop sequence
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 1000);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 1000);
  faboPWM.set_channel_value(DIRC1, 1000);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 1000);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(150);
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 2000);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 2000);
  faboPWM.set_channel_value(DIRC1, 2000);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 2000);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(30);
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);

}

void reverse(){
  //reverse sequence
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 500);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 500);
  faboPWM.set_channel_value(DIRC1, 500);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 500);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(250);
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 1000);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 1000);
  faboPWM.set_channel_value(DIRC1, 1000);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 1000);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(500);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 500);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 500);
  faboPWM.set_channel_value(DIRC1, 500);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 500);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(250);

  //stop sequence
  faboPWM.set_channel_value(DIRA1, 1000);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 1000);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 1000);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 1000);
  delay(150);
  
  faboPWM.set_channel_value(DIRA1, 2000);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 2000);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 2000);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 2000);
  delay(30);
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);

}

void spin_right(){
  faboPWM.set_channel_value(DIRA1, 500);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 500);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 500);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 800);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(2000);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 2000);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 2000);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 2000);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 2000);
  delay(60);
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
}

void shift_right(){
  //shift sequence
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 500);
  faboPWM.set_channel_value(DIRB1, 500);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 500);
  faboPWM.set_channel_value(DIRD1, 500);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(250);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 1000);
  faboPWM.set_channel_value(DIRB1, 1000);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 1000);
  faboPWM.set_channel_value(DIRD1, 1000);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(500);

  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 500);
  faboPWM.set_channel_value(DIRB1, 500);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 500);
  faboPWM.set_channel_value(DIRD1, 500);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(250);

  //stop sequence
  faboPWM.set_channel_value(DIRA1, 1000);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 1000);
  faboPWM.set_channel_value(DIRC1, 1000);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 1000);
  delay(150);

  faboPWM.set_channel_value(DIRA1, 2000);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 2000);
  faboPWM.set_channel_value(DIRC1, 2000);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 2000);
  delay(30);
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRD2, 0);
}

void shift_left(){
  //shift sequence
  faboPWM.set_channel_value(DIRA1, 500);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 500);
  faboPWM.set_channel_value(DIRC1, 500);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 500);
  delay(250);

  faboPWM.set_channel_value(DIRA1, 1000);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 1000);
  faboPWM.set_channel_value(DIRC1, 1000);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 1000);
  delay(500);

  faboPWM.set_channel_value(DIRA1, 500);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRB2, 500);
  faboPWM.set_channel_value(DIRC1, 500);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 500);
  delay(250);

  //stop sequence
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 1000);
  faboPWM.set_channel_value(DIRB1, 1000);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 1000);
  faboPWM.set_channel_value(DIRD1, 1000);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(150);
  
  faboPWM.set_channel_value(DIRA1, 0);
  faboPWM.set_channel_value(DIRA2, 2000);
  faboPWM.set_channel_value(DIRB1, 2000);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 2000);
  faboPWM.set_channel_value(DIRD1, 2000);
  faboPWM.set_channel_value(DIRD2, 0);
  delay(30);

  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 0);
  faboPWM.set_channel_value(DIRC2, 0);
  faboPWM.set_channel_value(DIRD1, 0);
}

void setup() {
  //IO_init();
  Serial.begin(9600);
  if(faboPWM.begin()) {
    Serial.println("Find PCA9685");
    faboPWM.init(300);
  }
  faboPWM.set_hz(50);
  Serial.print("Start"); 
}

void loop() {
  avanti();
  delay(1000);
  //spin_right();
//  delay(1000);
  shift_left();
  delay(1000);
  reverse();
  delay(1000);
  shift_right();
  delay(1000);
  
}
