int in3 = 8;
int in4 = 9;
int enB = 10;

void setup() {
  // put your setup code here, to run once:
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);
}


void rotR(){
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enB, 255);
  delay(3000);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void rotL(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enB, 255);
  delay(3000);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:
  rotR();
  delay(500);
  rotL();
  delay(500);
}
