# include <Servo.h>

Servo vertServo;
Servo horServo;
const int vertPin = 9;
const int horPin = 8;
int vPos = 55;
int hPos = 50;
const int sensorPin = A0;
int sensorVal = 0;
int sensorCoor[] = {0, 0};
const int buttonPin = 13;
int buttonState = 0;
int prevButtonState = 0;

void setup() {
  Serial.begin(9600);
  vertServo.attach(vertPin);
  horServo.attach(horPin);
  vertServo.write(vPos);
  horServo.write(hPos);
  pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH & prevButtonState == LOW) {
    for (hPos = 50; hPos <= 130; hPos +=2) {
      horServo.write(hPos);
      for (vPos = 55; vPos <= 150; vPos +=2) {
        vertServo.write(vPos);
        sensorVal = analogRead(sensorPin);
        sensorCoor[0] = hPos;
        sensorCoor[1] = vPos;
        printSensorInfo(sensorVal, sensorCoor);
        delay(75);
      }
      delay(75);
    }
    vertServo.write(55);
    horServo.write(50);
    delay(500);
  }
  prevButtonState = buttonState;

}

void printSensorInfo(int sensorVal, int sensorCoor[]) {
  Serial.print(sensorVal);
  Serial.print(", [");
  Serial.print(sensorCoor[0]);
  Serial.print(",");
  Serial.print(sensorCoor[1]);
  Serial.println("]");
}

