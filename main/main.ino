# include <Servo.h>

Servo vertServo;
Servo horServo;
int vPos = 0;
int hPos = 0;
int sensorPin = A0;
int sensorVal = 0;
int sensorCoor[] = {0, 0};

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
  for (hPos = 0; hPos <= 180; hPos += 5) {
    horServo.write(hPos);
    for (vPos = 0; vPos <= 120; vPos +=5) {
      vertServo.write(vPos);
      sensorVal = analogRead(sensorPin);
      sensorCoor[0] = hPos;
      sensorCoor[1] = vPos;
      printSensorInfo(sensorVal, sensorCoor);
      delay(150);
    }
    delay(150);
  }
  vertServo.write(0);
  horServo.write(0);
  delay(500);
}

void printSensorInfo(int sensorVal, int sensorCoor[]) {
  Serial.print(sensorVal);
  Serial.print(", [");
  Serial.print(sensorCoor[0]);
  Serial.print(",");
  Serial.print(sensorCoor[1]);
  Serial.println("]");
}
