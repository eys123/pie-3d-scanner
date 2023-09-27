# include <Servo.h>
Servo vertServo;
Servo horServo;
const int vertPin = 9;
const int horPin = 8;
int vStart = 60;
int hStart = 50;
int vEnd = 150;
int hEnd = 120;
int vPos = vStart;
int hPos = hStart;

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
  // check if button is pressed
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH & prevButtonState == LOW) {
    // execute horizontal movement
    for (hPos = hStart; hPos <= hEnd; hPos +=1) {
      horServo.write(hPos);
      vertMovement();
      delay(75);
    }
    vertServo.write(vStart);
    horServo.write(hStart);
  }
  prevButtonState = buttonState;
}

void printSensorInfo(int sensorVal, int sensorCoor[]) {
  /*
    Prints sensor values and coordinates to Serial Monitor.
    Args:
      sensorVal: an int recording the output value of the distance sensor.
      sensorCoor: an array containing 2 ints recording the horizontal servo angle
      and the vertical servo angle.
  */
  Serial.print(sensorVal);
  Serial.print(", [");
  Serial.print(sensorCoor[0]);
  Serial.print(",");
  Serial.print(sensorCoor[1]);
  Serial.println("]");
}

void vertMovement() {
  /*
    Vertical servo scanning movement.
    Scans up on one scan, then scans downward on the next.
  */
  if (vPos >= vEnd) {
    for (vPos = vEnd; vPos >= vStart; vPos -=1) {
      vertServo.write(vPos);
      sensorVal = analogRead(sensorPin);
      sensorCoor[0] = hPos;
      sensorCoor[1] = vPos;
      printSensorInfo(sensorVal, sensorCoor);
      delay(75);
    }
  }
  else {
    for (vPos = vStart; vPos <= vEnd; vPos +=1) {
      vertServo.write(vPos);
      sensorVal = analogRead(sensorPin);
      sensorCoor[0] = hPos;
      sensorCoor[1] = vPos;
      printSensorInfo(sensorVal, sensorCoor);
      delay(75);
    }
  }
}
