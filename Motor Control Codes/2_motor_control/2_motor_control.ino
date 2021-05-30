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

void check_motor1_stats(int  *state_1A, int *state_1B){
  if(digitalRead(output_motor1_A) == HIGH && digitalRead(output_motor1_B) == HIGH){
        *state_1A = 1;
        *state_1B = 1;
      }
      else if(digitalRead(output_motor1_A) == HIGH && digitalRead(output_motor1_B) == LOW){
        *state_1A = 1;
        *state_1B = 0;
      }
      else if(digitalRead(output_motor1_A) == LOW && digitalRead(output_motor1_B) == HIGH){
        *state_1A = 0;
        *state_1B = 1;
      }
      else if(digitalRead(output_motor1_A) == LOW && digitalRead(output_motor1_B) == LOW){
        *state_1A = 0;œ
        *state_1B = 0;
      }
}
void check_motor2_stats(int *state_2A, int *state_2B){
  if(digitalRead(output_motor2_A) == HIGH && digitalRead(output_motor2_B) == HIGH){
        *state_2A = 1;
        *state_2B = 1;
      }
      else if(digitalRead(output_motor2_A) == HIGH && digitalRead(output_motor2_B) == LOW){
        *state_2A = 1;
        *state_2B = 0; 
      }
      else if(digitalRead(output_motor2_A) == LOW && digitalRead(output_motor2_B) == HIGH){
        *state_2A = 0;
        *state_2B = 1;
      }
      else if(digitalRead(output_motor2_A) == LOW && digitalRead(output_motor2_B) == LOW){
        *state_2A = 0;
        *state_2B = 0; 
      }
}

void rotR(){
  int state1A, state1B, state2A, state2B;
  bool check_A = false;
  bool check_B = false;
  
  for(int i = 0; i < 220; i++){
    check_A = false; 
    check_B = false;
    
    while(check_A == false && check_B == false){
      
      //Reads intial conditon of motor position
      int a,b;
      check_motor1_stats(&a, &b);
      state1A = a, state1B = b;
      check_motor2_stats(&a, &b);
      state2A = a, state2B = b;
//      Serial.print("state_1A...");
//      Serial.println(state1A);
//      Serial.print("state_1B...");
//      Serial.println(state1B);
//      Serial.print("state_2A...");
//      Serial.println(state2A);
//      Serial.print("state_2B...");
//      Serial.println(state2B);
//      
      
      //Serial.println("Called !!!");
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW); 
      analogWrite(enA, 225);
      analogWrite(enB, 225);
      //delay(5);
      
      //Checks motor position changed or not 
      int test1A, test1B, test2A, test2B;
      check_motor1_stats(&a, &b);
      test1A = a, test1B = b;
      check_motor2_stats(&a, &b);
      test2A = a, test2B = b;
      if((state1A != test1A || state1B != test1B) && (state2A != test2A || state2B != test2B)){
        check_A = true;
        check_B = true;

      }else{
        check_A = false;
        check_B = false;
      }
      
    }

  }
  /*When rotation is done, motor should stop, but because we use 12V, just turning off the motor won't be enough, due to
  charactaristics of coil (coil is very analog not good at On/Off, it can only gradually On/Off), so below code
  spins motor backwards to stop motor efficiently. By reversing for short period, it offsets "gradually stop" section.
  */
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, 255);
    analogWrite(enB, 255);
    delay(80);
    //analogWrite(enA, 227);
    //analogWrite(enB, 227);
    //delay(20);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);  
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

void loop() {
  rotR();
  delay(2000);

}
