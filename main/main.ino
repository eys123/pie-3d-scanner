/*
A program that uses two servos and a distance sensor
in a pan-and-tilt mechanism to scan a figure.
*/

# include <Servo.h>

// initialize Servo info
Servo vertServo;
Servo horServo;
const int vertPin = 9;
const int horPin = 8;
int vStart = 80;
int hStart = 50;
int vEnd = 140;
int hEnd = 120;
int vPos = vStart;
int hPos = hStart;

// init sensor variables
const int sensorPin = A0;
int sensorVal = 0;
int sensorCoor[] = {0, 0};

// init button variables
const int buttonPin = 13;
int buttonState = 0;
int prevButtonState = 0;

void setup() {
  Serial.begin(9600);
  vertServo.attach(vertPin);
  horServo.attach(horPin);
  // Set servos to starting positions
  vertServo.write(vPos);
  horServo.write(hPos);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // check if button is pressed
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH & prevButtonState == LOW) {
    // run vertical servo scan
    for (vPos = vStart; vPos <= vEnd; vPos +=1) {
      vertServo.write(vPos);
      // for each vertical position, run a horizontal scan
      horMovement();
      delay(50);
    }
    // reset servos to starting positions
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
      and the vertical servo angle-- [hPos, vPos]
  */
  Serial.print(sensorVal);
  Serial.print(", [");
  Serial.print(sensorCoor[0]);
  Serial.print(",");
  Serial.print(sensorCoor[1]);
  Serial.println("]");
}

void horMovement() {
  /*
    Horizontal servo scanning movement.
    Scans right to left on one scan, then scans left to right on the next.
  */
  if (hPos >= hEnd) {
    for (hPos = hEnd; hPos >= hStart; hPos -=1) {
      horServo.write(hPos);
      sensorVal = analogRead(sensorPin);
      sensorCoor[0] = hPos;
      sensorCoor[1] = vPos;
      printSensorInfo(sensorVal, sensorCoor);
      delay(50);
    }
  }
  else {
    for (hPos = hStart; hPos <= hEnd; hPos +=1) {
      horServo.write(hPos);
      sensorVal = analogRead(sensorPin);
      sensorCoor[0] = hPos;
      sensorCoor[1] = vPos;
      printSensorInfo(sensorVal, sensorCoor);
      delay(50);
    }
  }
}