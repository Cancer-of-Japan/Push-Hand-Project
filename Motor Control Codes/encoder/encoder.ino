/*
   How to test encoder with Arduino
   url: http://osoyoo.com/?p=30267
*/
#define outputA A0
#define outputB A1
#define in3 8
#define in4 9
#define enB 10
int counter = 0;
int aState;
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
  Serial.println("Called !!!");
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
  delay(100);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}


void loop() {
  aState = digitalRead(outputA); // Reads the "current" state of the outputA
  Serial.print("Initial: ");
  Serial.println(aState);
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
rotR();
delay(100);


  aLastState = aState; // Updates the previous state of the outputA with the current state
}
