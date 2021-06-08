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
  
  faboPWM.set_channel_value(DIRA1, 300);
  faboPWM.set_channel_value(DIRA2, 0);
  faboPWM.set_channel_value(DIRB1, 300);
  faboPWM.set_channel_value(DIRB2, 0);
  faboPWM.set_channel_value(DIRC1, 0);
  faboPWM.set_channel_value(DIRC2, 300);
  faboPWM.set_channel_value(DIRD1, 0);
  faboPWM.set_channel_value(DIRD2, 300);
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

void setup() {
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

  pos = 5;
  if(prev != 0 && pos != prev){
    pos = prev;
  }
  Serial.println("Initial Pos");
  Serial.println(pos);
  int var = 0;
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
delay(1000);
Serial.println("-------------------------------------");







}
