# include <Servo.h>

Servo vertServo;
Servo horServo;
int vPos = 0;
int hPos = 0;

void setup() {
  Serial.begin(9600);
  vertServo.attach(9);
  horServo.attach(8);
  vertServo.write(vPos);
  horServo.write(hPos);
}

void loop() {
  // if button switches low -> high activate scan
  // while button is high turn off the sense different state thing
  // once button goes low turn it back on again

  // horizontal scan
  for (hPos = 1; hPos <= 180; hPos += 5) {
    for (vPos = 1; vPos <= 120; vPos +=5) {
      vertServo.write(vPos);
      delay(150);
    }
    horServo.write(hPos);
    delay(150);
  }
  vertServo.write(0);
  horServo.write(0);
  delay(500);
}
