#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


LiquidCrystal_I2C lcd(0x27, 16, 2);

#define But1 2
#define But2 3
#define But3 4
#define LED1 5
#define LED2 6
#define LED3 7

int B1State = 0;
int B2State = 0;
int B3State = 0;  
int B1cnt = 0;
int B2cnt = 0;
int B3cnt = 0;

int LB1State = 0;
int LB2State = 0;
int LB3State = 0;  

void Blink(){
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
}

void Blink_em(){
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(200);
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
  digitalWrite(LED3, HIGH);
  delay(200);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  delay(200);
}


void setup() {
  Wire.begin();
  Wire.beginTransmission(0x27);
  
  pinMode(But1, INPUT);
  pinMode(But2, INPUT);
  pinMode(But3, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  
  Serial.begin(9600);
}

void loop() {


  
   
  B2State = digitalRead(But2);  
  B3State = digitalRead(But3);  
  
  for(int i = 0; i < 10; i++){
    lcd.setCursor(0,0);
    lcd.print("Choose Mode");
    lcd.print(" ");
    lcd.print(i);
    B1State = digitalRead(But1); 
    if(digitalRead(But1) == HIGH){
      delay(100);
      B1cnt++;
      if(B1cnt > 1){
        B1cnt = 0;
      }
    }
    else if(B1State == LOW){
      delay(100);  
    }
    lcd.setCursor(0,1);
    lcd.print("Mode");
    lcd.print(B1cnt);
    delay(1000);
  }

  lcd.clear();
  for(int i = 0; i < 10; i++){
    lcd.clear();
    lcd.print("Mode ");
    lcd.print(B1cnt);
    lcd.print(" ?");
    lcd.print(i);
    for(int j = 0; j < 10; j++){
      if(digitalRead(But2) == HIGH){
        delay(100);
        B1cnt++;
        if(B1cnt > 1){
          B1cnt = 0;
        }
      lcd.clear();
      lcd.print("Mode ");
      lcd.print(B1cnt);
      lcd.print(" ?");
      lcd.print(i);
      delay(100);
      }
      else if(digitalRead(But2 == LOW)){
      lcd.clear();
      lcd.print("Mode ");
      lcd.print(B1cnt);
      lcd.print(" ?");
      lcd.print(i);
        delay(100);
      }
      else if(digitalRead(But3 == HIGH)){
        delay(100);
        break;
      }
    }  
    //delay(1000);
  }

  if(B1cnt == 0){
    Blink();
  }else{
    Blink_em();
    }
    delay(1000);

//  
//  if(B1State != LB1State){
//    if(B1State == HIGH){
//      delay(100);
//      digitalWrite(LED1, HIGH);
//      B1cnt++;
//    }
//    else{
//      digitalWrite(LED1, LOW);
//    }
//  }
//  
//  if(B2State != LB2State){
//    B2cnt++;
//    if(B2State == HIGH){
//      digitalWrite(LED2, HIGH);
//    }
//    else{
//      digitalWrite(LED2, LOW);
//    }
//  }
//  
//  if(B3State != LB3State){
//    B3cnt++;
//    if(B3State == HIGH){
//      digitalWrite(LED3, HIGH);
//    }
//    else{
//      digitalWrite(LED3, LOW);
//    }
//  }
//
//  
//  LB2State = B2State;
//  LB3State = B3State;
//
//  char B1res[9];
//  char B2res[9];
//  char B3res[9];
//  itoa(B1cnt, B1res, 10);
//  itoa(B2cnt, B2res, 10);
//  itoa(B3cnt, B3res, 10);

    
   

  delay(100);
    
}
