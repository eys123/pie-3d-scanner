# include <Servo.h>

servo vertServo;
servo horServo;
int vertPos;
int horPos;

void setup() {
  vertServo.attach(9);
  horServo.attach(10);
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    vertServo.write(pos);
    delay(15);
  }

}
