#define outputA 6
#define outputB 7
#define in3 8
#define in4 9
#define enB 10
int counter = 0;
int aState;
int bState;
int aLastState;

void setup() {
  pinMode(outputA, INPUT);
  pinMode(outputB, INPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  Serial.begin (9600);
  // Reads the initial state of the outputA
  aLastState = digitalRead(outputA);
}

void rotR() {
  
  int state;
  bool check = false;
  for(int i = 0; i < 21; i++){
    check = false;
    while(check == false){
      if(digitalRead(outputA) == HIGH){
        state = 1;
      }else{
        state = 0;
      }
      
      //Serial.println("Called !!!");
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      analogWrite(enB, 255);
      //delay(1);

      if(digitalRead(outputA) != state){
        check = true;
        Serial.println("Clicked !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
      }else{
        check = false;
      }
      
    }
  }
}

void loop() {
  int i, aCnt=0, bCnt=0;
  int cur_cnt = counter;
  rotR();
  delay(1000);
  if(cur_cnt > counter){
      Serial.println("Right!!!");
  }
  if(counter > cur_cnt){
      Serial.println("Left!!!");
  }

  delay(100);
  aLastState = aState; // Updates the previous state of the outputA with the current state
}
