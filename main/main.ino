# include <Servo.h>

Servo vertServo;
Servo horServo;
int vPos = 0;
int hPos = 0;

void setup() {
  Serial.begin(9600);
  vertServo.attach(8);
  horServo.attach(10);
}

void loop() {
  for (vPos = 0; vPos <= 180; vPos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    vertServo.write(vPos);
    for (hPos = 0; hPos <= 1800; hPos += 1) {
      horServo.write(hPos);
      delay(150);
    }
    delay(150);
  }

}

void init_pos() {
  vertServo.write(10);
  horServo.write(0);
}
