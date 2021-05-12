#define output_motor1_A 8
#define output_motor1_B 9
#define output_motor2_A 10
#define output_motor2_B 11

#define in1 2
#define in2 3
#define in3 5
#define in4 6

#define enA 4 
#define enB 7
void setup() {
  //Position data of 2 motors, each motor contains 2 output
  pinMode(output_motor1_A, INPUT);
  pinMode(output_motor1_B, INPUT);
  pinMode(output_motor2_A, INPUT);
  pinMode(output_motor2_B, INPUT);

  //Motor control 
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  //Enable of motors
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

  Serial.begin (9600);

}

void rotR(){
  int state_A, state_B;
  bool check_A = false;
  bool check_B = false;
  
  for(int i = 0; i < 13; i++){
    check_A = false; 
    check_B = false;
    
    while(check_A == false || check_B == false){
      //Reads intial conditon of motor position
      if(digitalRead(output_motor1_A) == HIGH && digitalRead(output_motor2_A) == HIGH){
        state_A = 1;
        state_B = 1;
      }
      else if(digitalRead(output_motor1_A) == HIGH && digitalRead(output_motor2_A) == LOW){
        state_A = 1; 
        state_B = 0;
      }
      else if(digitalRead(output_motor1_A) == LOW && digitalRead(output_motor2_A) == HIGH){
        state_A = 0; 
        state_B = 1;
      }
      else if(digitalRead(output_motor1_A) == LOW && digitalRead(output_motor2_A) == LOW){
        state_A = 0; 
        state_B = 0;
      }
      
      //Serial.println("Called !!!");
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      
      analogWrite(enA, 255);
      analogWrite(enB, 255);
      //delay(1000);
      //Checks motor position changed or not 
      if(digitalRead(output_motor1_A) != state_A || digitalRead(output_motor2_A) != state_B){
        check_A = true;
        check_B = true;
        Serial.println("Clicked !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
      }else{
        check_A = false;
        check_B = false;
      }
      
    }

  }
  /*When rotation is done, motor should stop, but because we use 12V, ust turning off the motor won't be enough, due to
  charactaristics of coil (coil is very analog not good at On/Off, it can only gradually On/Off), so below code
  spins motor backwards to stop motor efficiently.
  */
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    delay(90);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void loop() {
  rotR();
  delay(2000);

}
