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

void loop() {
  int i, aCnt=0, bCnt=0;

  for(i=0; i< 50; i++){
      aState = digitalRead(outputA);
      bState = digitalRead(outputB);// Reads the "current" state of the outputA
      //Serial.print("OutputA: ");
      aCnt = aCnt + aState;
      bCnt = bCnt + bState;
      //Serial.println(aState);
      //Serial.print("OutputB: ");
      //Serial.println(bState);
  }
  /*
  // If the previous and the current state of the outputA are different, that means a Pulse has occured
  if (aState != aLastState) {
    // If the outputB state is different to the outputA state, that means the encoder is rotating clockwise
    if (digitalRead(outputB) != aState) {
      counter ++;
    } else {
      counter --;
    }
    Serial.print("Position: ");
    Serial.println(counter);
  }
  */
  if(aCnt > bCnt){
      Serial.println("Right!!!");
  }
  if(aCnt < bCnt){
      Serial.println("Left!!!");
  }

  delay(300);
  aLastState = aState; // Updates the previous state of the outputA with the current state
}
