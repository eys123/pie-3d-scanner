# include <Servo.h>

Servo vertServo;
Servo horServo;
int vertPos = 0;
int horPos = 0;
int pos = 0;

void setup() {
  vertServo.attach(9);
  horServo.attach(10);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    vertServo.write(pos);
    horServo.write(pos);
    delay(15);
  }

}
