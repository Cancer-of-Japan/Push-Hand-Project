#define LED 6



void setup() {
  pinMode(LED, OUTPUT);
  pinMode(8, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(A0); 
  Serial.println(A0);
  if (data  > 40) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
