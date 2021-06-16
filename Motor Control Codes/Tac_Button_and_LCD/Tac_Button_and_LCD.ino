#include <Wire.h> 
#include <LiquidCrystal_PCF8574.h>


LiquidCrystal_PCF8574 lcd(0x27);

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

void setup() {
  Wire.begin();
  Wire.beginTransmission(0x27);
  
  pinMode(But1, INPUT);
  pinMode(But2, INPUT);
  pinMode(But3, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  B1State = digitalRead(But1);  
  B2State = digitalRead(But2);  
  B3State = digitalRead(But3);  

  if(B1State != LB1State){
    if(B1State == HIGH){
      digitalWrite(LED1, HIGH);
      B1cnt++;
    }
    else{
      digitalWrite(LED1, LOW);
    }
  }
  
  if(B2State != LB2State){
    B2cnt++;
    if(B2State == HIGH){
      digitalWrite(LED2, HIGH);
    }
    else{
      digitalWrite(LED2, LOW);
    }
  }
  
  if(B3State != LB3State){
    B3cnt++;
    if(B3State == HIGH){
      digitalWrite(LED3, HIGH);
    }
    else{
      digitalWrite(LED3, LOW);
    }
  }

  LB1State = B1State;
  LB2State = B2State;
  LB3State = B3State;

  char B1res[9];
  char B2res[9];
  char B3res[9];
  itoa(B1cnt, B1res, 10);
  itoa(B2cnt, B2res, 10);
  itoa(B3cnt, B3res, 10);

    lcd.setBacklight(255);
    lcd.home(); lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("CNT");
    lcd.print(B1cnt);
    lcd.print(B2cnt);
    lcd.print(B3cnt);
    delay(100);

  delay(100);
    
}
