#define Buzz 5
void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(Buzz, 800, 500);
  delay(500);
  tone(Buzz, 600, 500);
  delay(500);
  tone(Buzz, 1000, 500);
  delay(500);
  delay(1000);
}
